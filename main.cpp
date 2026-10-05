#include "Library.h"
#include <iostream>
#include <limits>
#include <string>

void pauseScreen() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Library library("data/library_records.txt");
    library.load();

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n========== OBJECT-ORIENTED LIBRARY MANAGER ==========\n"
                  << "1. List all books\n2. List available books\n3. Search books\n"
                  << "4. List members\n5. List loans\n6. Issue book\n7. Return book\n"
                  << "8. Add sample book\n9. Add sample member\n0. Save and Exit\n"
                  << "Choose: ";
        if (!(std::cin >> choice)) { std::cin.clear(); std::cin.ignore(10000, '\n'); choice = -1; }

        if (choice == 1) library.listBooks();
        else if (choice == 2) library.listAvailableBooks();
        else if (choice == 3) {
            std::string key; std::cout << "Keyword: "; std::cin >> key; library.searchBooks(key);
        } else if (choice == 4) library.listMembers();
        else if (choice == 5) library.listLoans();
        else if (choice == 6) {
            int bookId, memberId; std::string date;
            std::cout << "Book ID: "; std::cin >> bookId;
            std::cout << "Member ID: "; std::cin >> memberId;
            std::cout << "Issue date (YYYY-MM-DD): "; std::cin >> date;
            std::cout << (library.issueBook(bookId, memberId, date) ? "Book issued successfully.\n" : "Issue failed: check IDs or availability.\n");
        } else if (choice == 7) {
            int bookId; std::string date;
            std::cout << "Book ID: "; std::cin >> bookId;
            std::cout << "Return date (YYYY-MM-DD): "; std::cin >> date;
            std::cout << (library.returnBook(bookId, date) ? "Book returned successfully.\n" : "Return failed: no active loan found.\n");
        } else if (choice == 8) {
            int id; std::string title, author, category;
            std::cout << "Book ID: "; std::cin >> id;
            std::cin.ignore();
            std::cout << "Title: "; std::getline(std::cin, title);
            std::cout << "Author: "; std::getline(std::cin, author);
            std::cout << "Category: "; std::getline(std::cin, category);
            library.addBook(Book(id, title, author, category));
            std::cout << "Book added (if ID was unique).\n";
        } else if (choice == 9) {
            int id; std::string name, email;
            std::cout << "Member ID: "; std::cin >> id;
            std::cin.ignore();
            std::cout << "Name: "; std::getline(std::cin, name);
            std::cout << "Email: "; std::getline(std::cin, email);
            library.addMember(Member(id, name, email));
            std::cout << "Member added (if ID was unique).\n";
        } else if (choice == 0) {
            if (library.save()) std::cout << "Data saved. Goodbye!\n";
            else std::cout << "Warning: could not save data.\n";
        } else std::cout << "Invalid option.\n";
    }
    return 0;
}
