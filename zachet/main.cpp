#include <iostream>
#include "Library.hpp"

void fileChecking(std::ifstream &fin)
{
    if (!fin.good())
        throw "file doesnt exist";
    if (!fin)
        throw "file error";
    // if (fin.peek() == EOF)
    //     throw "file is empty";
}

int get_status(){
    std::cout<<"Press key:\n\
    1 - add new book\n\
    2 - delete book by title\n\
    3 - find books by the author\n\
    4 - find books by the genre\n\
    5 - find books by the year\n\
    6 - get statistics\n\
    7 - quit\nYour choice: ";
    int status;
    if(!(std::cin>>status)){
        throw "You need to enter a number!";
    }
    return status;
}

Book getBook(){
    char* title;
    char* author;
    size_t year;
    size_t pagesNum;
    char genre[10];
    char isHere[10];
    std::cin.ignore();
    std::cout<<"Enter a title of the book: ";
    std::cin.getline(title, 100);
    std::cout<<"Enter a author of the book: ";
    std::cin.getline(author, 100);
    std::cout<<"Enter a year of the book: ";
    if(!(std::cin>>year)){
        throw "You need to enter a number!";
    }
    std::cout<<"Enter a number of pages of the book: ";
    if(!(std::cin>>pagesNum)){
        throw "You need to enter a number!";
    }
    std::cin.ignore();
    std::cout<<"Enter a genre of the book: ";
    std::cin.getline(genre, 10);
    std::cout<<"Is there a book in the library?(true or false): ";
    std::cin.getline(isHere, 10);
    Book temp(title, author, year, pagesNum, getGenre(genre), getIsHere(isHere));
    return temp;
}

int main(){
    try{
        std::ifstream fin ("Library.txt");
        fileChecking(fin);
        std::ofstream fout ("Library.txt");
        Library data;
        data.getLib(fin);
        fin.close();
        while(true){
            int status = get_status();
            switch (status)
            {
            case 1:
            {
                Book temp = getBook();
                data.addBook(temp);
                break;
            }
            case 2:{
                char title[256];
                std::cout<<"Enter the title: ";
                std::cin.getline(title, 256);
                data.deleteBook(title);
                break;
            }
            case 3:{
                char author[256];
                std::cout<<"Enter the author: ";
                std::cin.getline(author, 256);
                data.findBook(author);
                break;
            }
            case 4:{
                char genre[256];
                std::cout<<"Enter the genre: ";
                std::cin.getline(genre, 256);
                data.findBook(getGenre(genre));
                break;
            }
            case 5:{
                size_t year;
                std::cout<<"Enter the year: ";
                if(!(std::cin>>year))
                    throw "You need to enter a number!";
                data.findBook(year);
                break;
            }
            case 6:
                data.statistics();
                break;
            case 7:{
                data.saveLib(fout);
                break;
            }
            default:
                throw "Invalid input!\n";
            }
        }
    }catch(const char* msg){
        std::cout<<msg;
    }
    return 0;
}