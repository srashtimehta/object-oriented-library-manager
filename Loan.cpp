#include "Loan.h"
#include <sstream>
#include <stdexcept>
#include <vector>

Loan::Loan() : bookId(0), memberId(0), returned(false) {}

Loan::Loan(int bookId, int memberId, const std::string& issueDate,
           const std::string& returnDate, bool returned)
    : bookId(bookId), memberId(memberId), issueDate(issueDate),
      returnDate(returnDate), returned(returned) {}

int Loan::getBookId() const { return bookId; }
int Loan::getMemberId() const { return memberId; }
const std::string& Loan::getIssueDate() const { return issueDate; }
const std::string& Loan::getReturnDate() const { return returnDate; }
bool Loan::isReturned() const { return returned; }
void Loan::markReturned(const std::string& date) { returnDate = date; returned = true; }

std::string Loan::serialize() const {
    return std::to_string(bookId) + "|" + std::to_string(memberId) + "|" + issueDate + "|" + returnDate + "|" + (returned ? "1" : "0");
}

Loan Loan::deserialize(const std::string& line) {
    std::stringstream ss(line);
    std::string field;
    std::vector<std::string> fields;
    while (std::getline(ss, field, '|')) fields.push_back(field);
    if (fields.size() != 5) throw std::runtime_error("Invalid loan record");
    return Loan(std::stoi(fields[0]), std::stoi(fields[1]), fields[2], fields[3], fields[4] == "1");
}
