#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

struct Student {
    std::string surname;
    std::string name;
    int group;
    int year;
    Student(std::string s, std::string n, int g, int y)
        : surname(s), name(n), group(g), year(y) {}
    ~Student() {};
};

void fileChecking(std::ifstream &fin){
    if (!fin.good())
        throw "file doesnt exist";
    if (!fin)
        throw "file error";
    if (fin.peek() == EOF)
        throw "file is empty";
}

std::vector<Student> getStudents(std::ifstream &fin, std::vector<Student> &students){
    std::string line;
    while (std::getline(fin, line)){
        std::string surname;
        std::string name;
        int group{};
        int year{};
        size_t n = line.size();
        for(size_t i = 0; i < n; ++i){
            if(name.empty()){
                while(i < n && (line[i] != ' ' && line[i] != ',' && line[i] != ';')){
                    name += line[i];
                    ++i;
                }
            }
            else if(surname.empty()){
                while(i < n && (line[i] != ' ' && line[i] != ',' && line[i] != ';')){
                    surname += line[i];
                    ++i;
                }
            }
            else if(!year){
                size_t numLen = 0;
                year = std::stoi(line.substr(i), &numLen);
                i += numLen;
            }
            else if(!group){
                size_t numLen = 0;
                group = std::stoi(line.substr(i), &numLen);
                i += numLen;
            }
        }
        students.emplace_back(surname, name, group, year);
    }
    return students;
}

std::vector<Student> sortStudentsBySurname(std::vector<Student> &students){
    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        if(a.surname > b.surname) 
            return false;
        else if(a.surname < b.surname)
            return true;
        else{
            if(a.name > b.name) 
                return false;
            else if(a.name < b.name)
                return true;
        }
        return false;
    });
    return students;
}

void printFios(const std::vector<Student> &students, std::ofstream &fout){
    for (const auto& student : students){
        fout << student.surname << ' ' << student.name << '\n';
    }
}

void sortStudents(std::vector<Student> &students){
    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        if(a.year > b.year) 
            return false;
        else if(a.year < b.year)
            return true;
        else{
            if(a.group > b.group) 
                return false;
            else if(a.group < b.group)
                return true;
            else{
                if(a.surname > b.surname) 
                    return false;
                else if(a.surname < b.surname)
                    return true;
        }}
        return false;
    });
}

void printGroups(const std::vector<Student> &students, std::ofstream &fout){
    for (const auto& student : students){
        fout << student.year << ' ' << student.group << ' ' << student.surname << ' ' << student.name << '\n';
    }
}

int main(){
    try{
        std::ifstream fin("Students.txt");
        fileChecking(fin);
        std::vector<Student> students;
        students = getStudents(fin, students);
        fin.close();
        std::ofstream fout1("Fio.txt");
        printFios(students, fout1);
        fout1.close();
        std::ofstream fout2("Group.txt");
        sortStudents(students);
        printGroups(students, fout2);
        fout2.close();
        std::cout<<"Data has been written to files successfully\n";
    }catch(const char* msg){
        std::cout<<msg;
    }
    return 0;
}