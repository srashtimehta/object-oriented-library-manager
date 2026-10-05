#ifndef LOAN_H
#define LOAN_H

#include <string>

class Loan {
private:
    int bookId;
    int memberId;
    std::string issueDate;
    std::string returnDate;
    bool returned;

public:
    Loan();
    Loan(int bookId, int memberId, const std::string& issueDate,
         const std::string& returnDate = "", bool returned = false);

    int getBookId() const;
    int getMemberId() const;
    const std::string& getIssueDate() const;
    const std::string& getReturnDate() const;
    bool isReturned() const;
    void markReturned(const std::string& date);

    std::string serialize() const;
    static Loan deserialize(const std::string& line);
};

#endif
