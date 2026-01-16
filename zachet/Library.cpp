#include "Library.hpp"
#include <cctype>
#include <iostream>
#include <cstring>

Library::Library(Book* l, size_t size) : lib(l) {
    lib = new Book[size];
}

Library::~Library(){
    delete lib;
}

void Library::addBook(const Book& book){
    lib = new Book[size+1];
    lib[size] = book;
    ++size;
}

void Library::regetLib(size_t it){
    for(size_t i=it;i<size-1;++i){
        lib[i] = lib[i+1];
    }
    --size;
}

void Library::deleteBook(const char* name){
    for(size_t i = 0;i<size;++i){
        if(lib[i].title == name){
            regetLib(i);
        }
    }
}

Library Library::findBook(const char* author){
    Library temp;
    for(size_t i =0; i<size;++i){
        if(lib[i].author == author){
            temp.addBook(lib[i]);
        }
    }
    return temp;
}

Library Library::findBook(const Genre genre){
    Library temp;
    for(size_t i =0; i<size;++i){
        if(lib[i].genre == genre){
            temp.addBook(lib[i]);
        }
    }
    return temp;
}

Library Library::findBook(size_t year){
    Library temp;
    for(size_t i =0; i<size;++i){
        if(lib[i].year == year){
            temp.addBook(lib[i]);
        }
    }
    return temp;
}

void sortLib(Book* lib, size_t size, Lines comp){
    switch (comp)
    {
    case title:
        for(size_t i=0;i<size;++i){
            for(size_t j=0;j<size-i-1;++j){
                if(lib[j].title>lib[j+1].title)
                    std::swap(lib[j], lib[j+1]);
            }
        }
        break;
    case author:
        for(size_t i=0;i<size;++i){
            for(size_t j=0;j<size-i-1;++j){
                if(lib[j].author>lib[j+1].author)
                    std::swap(lib[j], lib[j+1]);
            }
        }
        break;
    case year:
        for(size_t i=0;i<size;++i){
            for(size_t j=0;j<size-i-1;++j){
                if(lib[j].year>lib[j+1].year)
                    std::swap(lib[j], lib[j+1]);
            }
        }
        break;
    case pagesNum:
        for(size_t i=0;i<size;++i){
            for(size_t j=0;j<size-i-1;++j){
                if(lib[j].pagesNum>lib[j+1].pagesNum)
                    std::swap(lib[j], lib[j+1]);
            }
        }
        break;
    case genre:
        for(size_t i=0;i<size;++i){
            for(size_t j=0;j<size-i-1;++j){
                if(lib[j].genre>lib[j+1].genre)
                    std::swap(lib[j], lib[j+1]);
            }
        }
        break;
    case isHere:
        for(size_t i=0;i<size;++i){
            for(size_t j=0;j<size-i-1;++j){
                if(lib[j].isHere>lib[j+1].isHere)
                    std::swap(lib[j], lib[j+1]);
            }
        }
        break;
    }
    
}

void Library::printLib(std::ofstream& fout, Lines comp){
    sortLib(lib, size, comp);
    for(size_t i = 0;i<size;++i){
        lib[i].printBook(fout);
    }
}

void Library::saveLib(std::ofstream& fout){
    for(size_t i = 0;i<size;++i){
        lib[i].printBook(fout);
    }
}

Genre getGenre(char* genre){
    if(genre == "Fiction")
        return Fiction;
    if(genre == "Tech")
        return Tech;
    if(genre == "Sience")
        return Sience;
    if(genre == "Detective")
        return Detective;
    if(genre == "Fantasy")
        return Fantasy;
    else throw "invalid input";
}

bool getIsHere(char* isHere){
    if(isHere == "true")
        return true;
    if(isHere == "True")
        return true;
    if(isHere == "False")
        return false;
    if(isHere == "false")
        return false;
    else throw "invalid input";
}

void Library::getLib(std::ifstream &fin){
    char line[1000];
    while(fin.getline(line, 1000)){
        if (strncmp(line, "Book: ", 6) == 0) {
            Book newBook;
            char title[100], author[100], genre[100];
            int year, pagesNum;

            char* firstSpace = strchr(line + 6, ' ');
            if (!firstSpace) continue;
            
            char* secondSpace = strchr(firstSpace + 1, ' ');
            if (!secondSpace) continue;
            
            int titleLen = firstSpace - (line + 6);
            strncpy(title, line + 6, titleLen);
            title[titleLen] = '\0';
            
            int authorLen = secondSpace - (firstSpace + 1);
            strncpy(author, firstSpace + 1, authorLen);
            author[authorLen] = '\0';
            
            year = atoi(secondSpace + 1);
            
            strncpy(title, newBook.title, 99);
            title[99] = '\0';
            strncpy(author, newBook.author, 99);
            author[99] = '\0';
            newBook.year = year;
            
            if (fin.getline(line, 1000)) {
                char* genreStart = strstr(line, "Genre: ");
                if (!genreStart) continue;
                genreStart += 7;
                
                char* pagesStart = strstr(line, "Number of pages: ");
                if (!pagesStart) continue;
                
                int genreLen = pagesStart - genreStart - 1;
                strncpy(genre, genreStart, genreLen);
                genre[genreLen] = '\0';
                
                pagesNum = atoi(pagesStart + 17);
                
                Genre g = getGenre(genre);

                newBook.genre = g;
                newBook.pagesNum = pagesNum;
            }
            
            if (fin.getline(line, 1000)) {
                if (strstr(line, "There is such book in the library")) {
                    newBook.isHere = true;
                } else if (strstr(line, "There is no such book in the library")) {
                    newBook.isHere = false;
                }
            }
            addBook(newBook);
        }
    }
}

void Library::statistics(){
    std::cout<<"The number of books in the library: "<<size<<'\n';
}