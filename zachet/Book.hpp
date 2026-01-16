#pragma once

#include <fstream>

enum Genre{
    Fiction = 1,
    Tech = 2,
    Sience = 3,
    Detective = 4,
    Fantasy = 5,
};

class Book{
    public:
        char* title;
        char* author;
        size_t year;
        size_t pagesNum;
        Genre genre;
        bool isHere;
        Book(char* t = nullptr, char* a = nullptr, size_t y = 0, size_t p = 0, Genre g = Fiction, bool i = 0);
        ~Book();

        void printBook(std::ofstream&);
};