#include "Book.h"
#include <sstream>
#include <stdexcept>
#include <vector>

Book::Book() : id(0), available(true) {}

Book::Book(int id, const std::string& title, const std::string& author,
           const std::string& category, bool available)
    : id(id), title(title), author(author), category(category), available(available) {}

int Book::getId() const { return id; }
const std::string& Book::getTitle() const { return title; }
const std::string& Book::getAuthor() const { return author; }
const std::string& Book::getCategory() const { return category; }
bool Book::isAvailable() const { return available; }
void Book::setAvailable(bool value) { available = value; }

std::string Book::serialize() const {
    return std::to_string(id) + "|" + title + "|" + author + "|" + category + "|" + (available ? "1" : "0");
}

Book Book::deserialize(const std::string& line) {
    std::stringstream ss(line);
    std::string field;
    std::vector<std::string> fields;
    while (std::getline(ss, field, '|')) fields.push_back(field);
    if (fields.size() != 5) throw std::runtime_error("Invalid book record");
    return Book(std::stoi(fields[0]), fields[1], fields[2], fields[3], fields[4] == "1");
}
