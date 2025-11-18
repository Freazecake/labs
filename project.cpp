#include<fstream>
#include<iostream>
#include<vector>
#include<string>

struct Student{
    int16_t course;
    int16_t group;
    std::string name;
    std::string surname;
    std::string otchestvo;
    std::vector<int16_t> marks;

    Student(int16_t _course, int16_t _group, std::string _name, std::string _surname,\
         std::string _otchestvo, std::vector<int16_t> _marks){
            course=_course;
            group=_group;
            name=_name;
            surname=_surname;
            otchestvo=_otchestvo;
            marks=_marks;
         }
    ~Student(){
        
    }
};

void getLines(std::vector<std::string> &lines, std::ifstream &fin){
    std::string str;
    while(std::getline(fin, str)){
        lines.push_back(str);
    }
}

void getStudents(std::vector<Student> &students, std::vector<std::string> &lines){
    size_t lines_size;
    int j{};
    for(auto i : lines){
        switch(j%6){
        case 0:
            for(size_t k=0;k<i.size();++k)
                if(isdigit(i[k]))
                    int16_t course = i[k] - '0';
            students
            break;
        case 1:
            for(size_t k=0;k<i.size();++k){
                int16_t group{};
                if(isdigit(i[k]))
                    group += i[k] - '0';
            }
            break;
        case 2:
            std::string name;
            for(size_t k=0;k<i.size();++k){
                if(isalpha(i[k])){
                    name+=i[k];
                }
            }break;
        case 3:
        default:
            break;
        }
        ++j;
    }
}

int main(){
    std::ifstream fin("in.txt");
    std::ofstream fout("answer.txt");
    
    std::vector<std::string> lines;
    getLines(lines, fin);
    
    std::vector<Student> students;
    getStudents(students, lines);
    
}