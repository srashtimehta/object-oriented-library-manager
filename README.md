# Object-Oriented Library Manager

A beginner-friendly multi-file C++ console application demonstrating object-oriented programming, encapsulation, STL collections, borrowing/returning, searching, availability tracking, and file persistence.

## Features
- Separate `Book`, `Member`, `Loan`, and `Library` classes.
- Encapsulation using private data members and public methods.
- STL `std::vector` collections.
- Issue and return books with availability checks.
- Search books by title, author, or category.
- List books, available books, members, and loans.
- Persistent local storage in `data/library_records.txt`.
- Records reload automatically when the program starts.
- Seed/sample data included.

## Project structure
```text
Object-Oriented-Library-Manager/
├── Book.h
├── Book.cpp
├── Member.h
├── Member.cpp
├── Loan.h
├── Loan.cpp
├── Library.h
├── Library.cpp
├── main.cpp
├── class_diagram.md
├── README.md
└── data/
    └── library_records.txt
```

## Requirements
- C++17 or later
- Any standard C++ compiler such as g++ / MinGW

## Compile
```bash
g++ -std=c++17 main.cpp Book.cpp Member.cpp Loan.cpp Library.cpp -o library_manager
```

## Run
Linux/macOS:
```bash
./library_manager
```
Windows:
```powershell
.\library_manager.exe
```

Run the executable from the project root so the relative `data/` path works correctly.

## Persistence format
The application stores three sections:
- `[BOOKS]`: `id|title|author|category|availability`
- `[MEMBERS]`: `id|name|email`
- `[LOANS]`: `bookId|memberId|issueDate|returnDate|returned`

The program ignores malformed records instead of terminating during startup, which keeps loading safe.

## OOP design
- **Book** owns book information and availability state.
- **Member** owns member identity/contact information.
- **Loan** represents an issue transaction and return state.
- **Library** manages collections and coordinates issue/return/search/persistence behavior.

## Submission checklist
- [x] Multi-file C++ project
- [x] Book, Member, Loan classes
- [x] Encapsulation
- [x] Collections (`std::vector`)
- [x] Issue behavior
- [x] Return behavior
- [x] Search behavior
- [x] Availability behavior
- [x] File persistence and reload
- [x] Sample data
- [x] Class diagram
- [x] README

## Suggested proof/demo
1. Start the program.
2. Select `1` to show all books.
3. Select `6`, issue book `101` to member `201` with a date such as `2026-10-05`.
4. Select `2` to demonstrate that the issued book is no longer available.
5. Select `7` and return book `101`.
6. Select `5` to show the completed loan.
7. Exit with `0`; restart the program to demonstrate persistence.
