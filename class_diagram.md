# Class Diagram

```text
+---------------------------+
|           Book            |
+---------------------------+
| - id: int                 |
| - title: string           |
| - author: string          |
| - category: string        |
| - available: bool         |
+---------------------------+
| + getId()                 |
| + getTitle()              |
| + getAuthor()             |
| + getCategory()           |
| + isAvailable()           |
| + setAvailable()          |
| + serialize()             |
| + deserialize()           |
+---------------------------+

+---------------------------+
|          Member           |
+---------------------------+
| - id: int                 |
| - name: string            |
| - email: string           |
+---------------------------+
| + getId()                 |
| + getName()               |
| + getEmail()              |
| + serialize()             |
| + deserialize()           |
+---------------------------+

+---------------------------+
|           Loan            |
+---------------------------+
| - bookId: int             |
| - memberId: int           |
| - issueDate: string       |
| - returnDate: string      |
| - returned: bool          |
+---------------------------+
| + getBookId()             |
| + getMemberId()           |
| + getIssueDate()          |
| + getReturnDate()         |
| + isReturned()            |
| + markReturned()          |
| + serialize()             |
| + deserialize()           |
+---------------------------+

                 managed by
                     |
                     v
+------------------------------------------------+
|                   Library                      |
+------------------------------------------------+
| - books: vector<Book>                          |
| - members: vector<Member>                      |
| - loans: vector<Loan>                          |
| - dataFile: string                             |
+------------------------------------------------+
| + addBook()                                    |
| + addMember()                                  |
| + issueBook()                                  |
| + returnBook()                                 |
| + searchBooks()                                |
| + listAvailableBooks()                         |
| + listBooks()                                  |
| + listMembers()                                |
| + listLoans()                                  |
| + load()                                       |
| + save()                                       |
+------------------------------------------------+

Library 1 ---- * Book
Library 1 ---- * Member
Library 1 ---- * Loan
Loan * ---- 1 Book
Loan * ---- 1 Member
```

The relationships are implemented with vectors and IDs rather than raw pointers, keeping ownership simple and beginner-friendly.
