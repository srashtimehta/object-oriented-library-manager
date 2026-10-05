#include "Member.h"
#include <sstream>
#include <stdexcept>
#include <vector>

Member::Member() : id(0) {}
Member::Member(int id, const std::string& name, const std::string& email)
    : id(id), name(name), email(email) {}

int Member::getId() const { return id; }
const std::string& Member::getName() const { return name; }
const std::string& Member::getEmail() const { return email; }

std::string Member::serialize() const {
    return std::to_string(id) + "|" + name + "|" + email;
}

Member Member::deserialize(const std::string& line) {
    std::stringstream ss(line);
    std::string field;
    std::vector<std::string> fields;
    while (std::getline(ss, field, '|')) fields.push_back(field);
    if (fields.size() != 3) throw std::runtime_error("Invalid member record");
    return Member(std::stoi(fields[0]), fields[1], fields[2]);
}
