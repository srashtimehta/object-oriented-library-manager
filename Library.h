#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include <string>
#include <vector>

class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;
    std::string dataFile;

    Book* findBook(int id);
    Member* findMember(int id);
    Loan* findActiveLoan(int bookId);

public:
    explicit Library(const std::string& dataFile = "data/library_records.txt");

    void addBook(const Book& book);
    void addMember(const Member& member);
    bool issueBook(int bookId, int memberId, const std::string& date);
    bool returnBook(int bookId, const std::string& date);

    void searchBooks(const std::string& keyword) const;
    void listAvailableBooks() const;
    void listBooks() const;
    void listMembers() const;
    void listLoans() const;

    bool load();
    bool save() const;
};

#endif
