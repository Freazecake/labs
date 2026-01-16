#include "Book.hpp"
#include "Library.hpp"
#include <iostream>

Book::Book(char* t, char* a, size_t y, size_t p, Genre g, bool i)
        : title(t), author(a), year(y), pagesNum(p), genre(g), isHere(i) {}

Book::~Book(){
    delete title;
    delete author;
}

void Book::printBook(std::ofstream& fout){
    fout<<"Book: "<<title<<' '<<author<<' '<<year<<'\n'<<"Genre: "<< genre<<" Number of pages: "<< pagesNum;
    if(!isHere){
        fout<<"\nThere is no such book in the library right now\n";
    }
    else{
        fout<<"\nThere is such book in the library\n";
    }
}
