#include "Library.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>

namespace {
std::string lowerCopy(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return s;
}
}

Library::Library(const std::string& dataFile) : dataFile(dataFile) {}

Book* Library::findBook(int id) {
    for (auto& book : books) if (book.getId() == id) return &book;
    return nullptr;
}

Member* Library::findMember(int id) {
    for (auto& member : members) if (member.getId() == id) return &member;
    return nullptr;
}

Loan* Library::findActiveLoan(int bookId) {
    for (auto& loan : loans) if (loan.getBookId() == bookId && !loan.isReturned()) return &loan;
    return nullptr;
}

void Library::addBook(const Book& book) {
    if (!findBook(book.getId())) books.push_back(book);
}

void Library::addMember(const Member& member) {
    if (!findMember(member.getId())) members.push_back(member);
}

bool Library::issueBook(int bookId, int memberId, const std::string& date) {
    Book* book = findBook(bookId);
    Member* member = findMember(memberId);
    if (!book || !member || !book->isAvailable()) return false;
    book->setAvailable(false);
    loans.emplace_back(bookId, memberId, date);
    return true;
}

bool Library::returnBook(int bookId, const std::string& date) {
    Book* book = findBook(bookId);
    Loan* loan = findActiveLoan(bookId);
    if (!book || !loan) return false;
    loan->markReturned(date);
    book->setAvailable(true);
    return true;
}

void Library::searchBooks(const std::string& keyword) const {
    const std::string key = lowerCopy(keyword);
    bool found = false;
    for (const auto& book : books) {
        std::string hay = lowerCopy(book.getTitle() + " " + book.getAuthor() + " " + book.getCategory());
        if (hay.find(key) != std::string::npos) {
            std::cout << "[" << book.getId() << "] " << book.getTitle() << " | "
                      << book.getAuthor() << " | " << book.getCategory() << " | "
                      << (book.isAvailable() ? "Available" : "Issued") << '\n';
            found = true;
        }
    }
    if (!found) std::cout << "No matching books found.\n";
}

void Library::listAvailableBooks() const {
    bool found = false;
    for (const auto& book : books) if (book.isAvailable()) {
        std::cout << "[" << book.getId() << "] " << book.getTitle() << " - " << book.getAuthor() << '\n';
        found = true;
    }
    if (!found) std::cout << "No books are currently available.\n";
}

void Library::listBooks() const {
    for (const auto& book : books) {
        std::cout << "[" << book.getId() << "] " << book.getTitle() << " | "
                  << book.getAuthor() << " | " << book.getCategory() << " | "
                  << (book.isAvailable() ? "Available" : "Issued") << '\n';
    }
}

void Library::listMembers() const {
    for (const auto& member : members) {
        std::cout << "[" << member.getId() << "] " << member.getName() << " | " << member.getEmail() << '\n';
    }
}

void Library::listLoans() const {
    for (const auto& loan : loans) {
        std::cout << "Book " << loan.getBookId() << " -> Member " << loan.getMemberId()
                  << " | Issue: " << loan.getIssueDate()
                  << " | Return: " << (loan.isReturned() ? loan.getReturnDate() : "Active") << '\n';
    }
}

bool Library::load() {
    std::ifstream in(dataFile);
    if (!in) return false;
    books.clear(); members.clear(); loans.clear();
    std::string section, line;
    while (std::getline(in, line)) {
        if (line == "[BOOKS]") { section = "books"; continue; }
        if (line == "[MEMBERS]") { section = "members"; continue; }
        if (line == "[LOANS]") { section = "loans"; continue; }
        if (line.empty() || line[0] == '#') continue;
        try {
            if (section == "books") books.push_back(Book::deserialize(line));
            else if (section == "members") members.push_back(Member::deserialize(line));
            else if (section == "loans") loans.push_back(Loan::deserialize(line));
        } catch (...) { /* Ignore malformed seed records and keep loading safely. */ }
    }
    return true;
}

bool Library::save() const {
    std::ofstream out(dataFile);
    if (!out) return false;
    out << "# Object-Oriented Library Manager data file\n[BOOKS]\n";
    for (const auto& b : books) out << b.serialize() << '\n';
    out << "[MEMBERS]\n";
    for (const auto& m : members) out << m.serialize() << '\n';
    out << "[LOANS]\n";
    for (const auto& l : loans) out << l.serialize() << '\n';
    return true;
}
