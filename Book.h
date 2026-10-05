#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    std::string category;
    bool available;

public:
    Book();
    Book(int id, const std::string& title, const std::string& author,
         const std::string& category, bool available = true);

    int getId() const;
    const std::string& getTitle() const;
    const std::string& getAuthor() const;
    const std::string& getCategory() const;
    bool isAvailable() const;
    void setAvailable(bool value);

    std::string serialize() const;
    static Book deserialize(const std::string& line);
};

#endif
