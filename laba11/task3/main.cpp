#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

struct Author {
    std::string surname;
    std::string name;
    std::string patronymic;
    Author(std::string s, std::string n, std::string p)
        : surname(s), name(n), patronymic(p) {}
    Author() : surname(""), name(""), patronymic("") {}
    ~Author() {};

    bool operator== (Author& a){
        if(surname == a.surname && name == a.name && patronymic == a.patronymic){
            return true;
        }
        return false;
    }
};

struct Book {
    size_t id;
    std::string title;
    std::list<Author> author;
    int year;
    Book() : id(0), title(""), author(), year(0) {}
    Book(size_t i, std::string t, std::list<Author> a, int y)
        : id(i), title(t), author(a), year(y) {}
    ~Book() {};

    void addAuthor(std::string &line) {
        std::string surname;
        std::string name;
        std::string patronymic;
        size_t n = line.size();
        for(size_t i = 0; i < n; ++i){
            if(surname.empty()){
                while(i < n && (line[i] != ' ' && line[i] != ',' && line[i] != ';')){
                    surname += line[i];
                    ++i;
                }
            }
            else if(name.empty()){
                while(i < n && (line[i] != ' ' && line[i] != ',' && line[i] != ';')){
                    name += line[i];
                    ++i;
                }
            }
            else if(patronymic.empty()){
                while(i < n && (line[i] != ' ' && line[i] != ',' && line[i] != ';')){
                    patronymic += line[i];
                    ++i;
                }
            }
            if(!surname.empty() && !name.empty() && !patronymic.empty()){
                author.push_back(Author(surname, name, patronymic));
                surname.clear();
                name.clear();
                patronymic.clear();
            }
        }
    }

    friend std::ostream& operator<< (std::ostream& out, const Book& book){
        out << "ID: " << book.id << ", Title: " << book.title << ", Year: " << book.year << ", \nAuthors: ";
            for (const auto& author : book.author) {
                out << author.surname << ' ' << author.name << ' ' << author.patronymic << ";\n";
            }
        return out;
    }

    friend std::ofstream& operator<< (std::ofstream& fout, const Book& book){
        fout << "ID: " << book.id << ", Title: " << book.title << ", Year: " << book.year << ",\nAuthors: ";
            for (const auto& author : book.author) {
                fout << author.surname << ' ' << author.name << ' ' << author.patronymic << ";\n";
            }
        return fout;
    }
};

class Library {
private:
    std::list<Book> books{};
    bool checkUniqueID(size_t id){
        for(auto& book : books){
            if(book.id == id){
                return false;
            }
        }
        return true;
    }
public:
    Library(){}
    Library(std::ifstream& fin) {addLibrary(fin);}
    void addLibrary(std::ifstream& fin){
        std::string line;
        size_t id{};
        std::string title;
        std::list<Author> author;
        int year{};
        while(std::getline(fin, line)){
            if(line.empty())    continue;
            size_t n = line.size();
            for(size_t i = 0;i<n;++i){
                if(!id){
                    id = std::stoi(line.substr(4), &i);
                    i+=4;
                }
                if(title.empty()){
                    i+=9;
                    while(line[i]!=','){
                        title+=line[i];
                        ++i;
                    }
                }
                if(!year){
                    size_t numLen{};
                    i+=8;
                    year = std::stoi(line.substr(i), &numLen);
                    i+=numLen;
                    break;
                }
                if(!author.empty())
            }
            if(id!=0 && year!=0 && !title.empty() && !author.empty()){
                books.emplace_back(id, title, author, year);
                id=0;
                year=0;
                title.clear();
                author.clear();
            }
        }
    }
    ~Library(){}

    void addBook() {
        Book temp;
        std::cout << "Enter book ID: ";
        std::cin >> temp.id;
        if(!checkUniqueID(temp.id)){
            throw "Books id should be unique!\n";
        }
        std::cout << "Enter book title: ";
        std::cin.ignore();
        std::getline(std::cin, temp.title);
        std::cout << "Enter authors: ";
        std::string line;
        std::getline(std::cin, line);
        temp.addAuthor(line);
        std::cout << "Enter book year: ";
        std::cin >> temp.year;
        books.push_back(temp);
    }

    void printBooks(std::ofstream &fout){
        for (const auto& book : books) {
            fout << book;
        }
    }

    void deleteBookById(size_t id) {
        books.remove_if([id](const Book& book) {
            return book.id == id;
        });
    }

    std::vector<Book> findBookByTitle(const std::string& title){
        std::vector<Book> foundBooks;
        for (const auto& book : books) {
            if (book.title == title) {
                foundBooks.push_back(book);
            }
        }
        return foundBooks;
    }

    std::vector<Book> findBookByAuthor(Author& author){
        std::vector<Book> foundBooks;
        for (const auto& book : books) {
            for(auto i : book.author){
                if(i == author){
                    foundBooks.push_back(book);
                }
            }
        }
        return foundBooks;
    }

    void deleteAuthor(size_t id){
        for(auto& book : books){
            if(book.id == id){
                book.author.clear();
                return;
            }
        }
    }

    void addAuthor(size_t id){
        for(auto& book : books){
            if(book.id == id){
                Book temp;
                std::cout << "Enter authors: ";
                std::string line;
                std::getline(std::cin, line);
                temp.addAuthor(line);
                book.author.clear();
                return;
            }
        }
    }
};

int get_status(){
    std::cout<<"Press key:\n\
    1 - add new book\n\
    2 - delete book\n\
    3 - find book by the title\n\
    4 - find book by the author\n\
    5 - add author to the book\n\
    6 - delete author of the book\n\
    7 - quit\nYour choice: ";
    int status;
    if(!(std::cin>>status)){
        throw "You need to enter a number!";
    }
    return status;
}

int main(){
    try{
        std::ifstream fin ("Library.txt");
        std::ofstream fout ("Library.txt");
        Library data;
        data.addLibrary(fin);
        fin.close();
        bool quit=false;
        while(!quit){
            switch (int status = get_status(); status)
            {
            case 1:
                data.addBook();
                break;
            case 2:{
                size_t id;
                if(!(std::cin>>id)){
                    throw "You need to enter a number\n";
                }
                data.deleteBookById(id);
            }
            case 5:{
                size_t id;
                if(!(std::cin>>id)){
                    throw "You need to enter a number\n";
                }
                data.addAuthor(id);
            }
            case 3:{
                std::string title;
                std::cout<<"Enter a title: ";
                std::getline(std::cin, title);
                std::vector<Book> books = data.findBookByTitle(title);
                for(const auto& book : books){
                    std::cout<<book;
                }
            }
            case 4:{
                std::string line;
                std::getline(std::cin, line);
                Book temp;
                temp.addAuthor(line);
                std::vector<Book>books = data.findBookByAuthor(temp.author.front());
                for(const auto& book : books){
                    std::cout<<book;
                }
            }
            case 6:{
                size_t id;
                if(!(std::cin>>id)){
                    throw "You need to enter a number\n";
                }
                data.deleteAuthor(id);
            }
            case 7:{
                quit=true;
                data.printBooks(fout);
            }
            default:
                throw "Invalid input!\n";
            }
        }
    }catch(const char* msg){
        std::cout<<msg;
    }
}