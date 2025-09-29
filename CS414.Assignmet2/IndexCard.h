#pragma once
#include <string>
#include <iostream>

class IndexCard {
private:
    int id;
    std::string keyword;
    std::string note;

public:
    IndexCard() : id(0), keyword(""), note("") {}
    IndexCard(int i, const std::string& k, const std::string& n)
        : id(i), keyword(k), note(n) {}

    int getId() const { return id; }
    std::string getKeyword() const { return keyword; }
    std::string getNote() const { return note; }

    bool operator<(const IndexCard& other) const { return id < other.id; }
    bool operator>(const IndexCard& other) const { return id > other.id; }
    bool operator==(const IndexCard& other) const { return id == other.id; }

    friend std::ostream& operator<<(std::ostream& os, const IndexCard& card) {
        os << "[" << card.id << "] " << card.keyword << ": " << card.note;
        return os;
    }
};
