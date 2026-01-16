#pragma once

#include "Book.hpp"

enum Lines{
    title,
    author,
    year,
    pagesNum,
    genre,
    isHere,
};

class Library{
    private:
        Book* lib;
        size_t size{};
        
        void regetLib(size_t);
    public:
        Library(Book* l = nullptr, size_t size = 0);
        ~Library();

        void addBook(const Book&);
        void deleteBook(const char*);
        Library findBook(const char*);
        Library findBook(const Genre);
        Library findBook(const size_t);
        friend void sortLib(Book*, size_t, Lines);
        void printLib(std::ofstream&, Lines = title);

        void saveLib(std::ofstream&);
        void getLib(std::ifstream&);

        void statistics();
};

Genre getGenre(char*);
bool getIsHere(char*);