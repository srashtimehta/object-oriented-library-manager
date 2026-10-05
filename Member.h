#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
private:
    int id;
    std::string name;
    std::string email;

public:
    Member();
    Member(int id, const std::string& name, const std::string& email);

    int getId() const;
    const std::string& getName() const;
    const std::string& getEmail() const;

    std::string serialize() const;
    static Member deserialize(const std::string& line);
};

#endif
