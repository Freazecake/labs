#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cctype>
#include <algorithm>

void fileChecking(std::ifstream &fin){
    if(fin.good()){
        throw "file doesnt exist";
    }
    if(!fin){
        throw "file error";
    }
    if(fin.peek()==EOF){
        throw "file is empty";
    }
}

bool my_isalpha(char ch)
{
    return std::isalpha(static_cast<unsigned char>(ch));
}

struct Student
{
    int16_t course;
    int16_t group;
    std::string name;
    std::string surname;
    std::string otchestvo;
    std::vector<int16_t> marks;

    Student(int16_t _course, int16_t _group, std::string _surname, std::string _name,
            std::string _otchestvo, std::vector<int16_t> _marks)
    {
        course = _course;
        group = _group;
        name = _name;
        surname = _surname;
        otchestvo = _otchestvo;
        marks = _marks;
    }
    ~Student()
    {
    }
};

void printStudent(std::vector<Student> &students, std::ofstream &fout, int16_t id)
{
    fout << "Course: " << students[id].course << '\n';
    fout << "Group: " << students[id].group << '\n';
    fout << "Surname:" << students[id].surname << '\n';
    fout << "Name:" << students[id].name << '\n';
    fout << "Otchestvo:" << students[id].otchestvo << '\n';
    fout << "Marks: ";
    for (auto j : students[id].marks)
    {
        fout << j << ' ';
    }
    fout << "\n\n";
}

void getLines(std::vector<std::string> &lines, std::ifstream &fin)
{
    std::string str;
    while (std::getline(fin, str))
    {
        if (!str.empty())
            lines.push_back(str);
    }
    std::cout << "Lines readed: " << lines.size() << '\n';
}

int16_t getNum(std::string &str, int &j)
{
    size_t k{static_cast<size_t>(j)};
    int16_t num = std::stoi(str.substr(j), &k);
    j += k;
    ++j;
    return num;
}

std::string getStr(std::string &line, int &j)
{
    std::string str;
    while (j < line.size() && line[j] != ';')
    {
        str += line[j];
        ++j;
    }
    ++j;
    return str;
}

std::vector<int16_t> getVec(std::string &i)
{
    std::vector<int16_t> marks;
    size_t k{};
    while (k < i.size())
    {
        if (isdigit(i[k]))
        {
            size_t g{k};
            int mark = std::stoi(i.substr(k), &g);
            marks.push_back(static_cast<int16_t>(mark));
            k += g;
        }
        else
        {
            ++k;
        }
    }
    return marks;
}

void getStudents(std::vector<Student> &students, std::vector<std::string> &lines)
{
    size_t lines_size;

    Student temp_student(0, 0, "", "", "", std::vector<int16_t>{});
    // bool IsGoodStr=0;
    for (auto i : lines)
    {
        // switch(j%6){
        // case 0:{
        //     int16_t course_{};
        //     for(size_t k=0;k<i.size();++k)
        //         if(isdigit(i[k])){
        //             course_ = i[k] - '0';
        //             IsGoodStr=1;
        //         }
        //     temp_student.course=course_;
        //     break;
        // }
        // case 1:{
        //     int16_t group_{};
        //     for(size_t k=0;k<i.size();++k){
        //         if(isdigit(i[k])){
        //             group_ += i[k] - '0';
        //             IsGoodStr=1;
        //         }
        //     }
        //     temp_student.group=group_;
        //     break;
        // }
        // case 2:{
        //    std::string name_;
        //     for(auto g : i){
        //         if(my_isalpha(g)){
        //             name_+=g;
        //             IsGoodStr=1;
        //         }
        //     }
        //     temp_student.name=name_;
        //     break;
        // }
        // case 3:{
        //     std::string surname_;
        //     for(auto g : i){
        //         if(my_isalpha(g)){
        //             surname_+=g;
        //             IsGoodStr=1;
        //         }
        //     }
        //     temp_student.surname=surname_;
        //     break;
        // }
        // case 4:{
        //     std::string otchestvo_;
        //     for(auto g : i){
        //         if(my_isalpha(g)){
        //             otchestvo_+=g;
        //             IsGoodStr=1;
        //         }
        //     }
        //     temp_student.otchestvo=otchestvo_;
        //     break;
        // }
        // case 5:{
        //     std::vector<int16_t> marks_;
        //     size_t k{};
        //     while(k < i.size()){
        //         if(isdigit(i[k])){
        //             size_t g{k};
        //             int mark = std::stoi(i.substr(k), &g);
        //             marks_.push_back(static_cast<int16_t>(mark));
        //             k+=g;
        //             IsGoodStr=1;
        //         }
        //         ++k;
        //     }
        //     temp_student.marks=marks_;
        //     break;
        // }}
        // if(j%6==0 && j!=0){
        //     if(IsGoodStr)
        //         students.push_back(temp_student);
        //     temp_student=Student(0, 0, "", "", "", std::vector<int16_t>{});
        //     if((static_cast<int>(lines.size())-j)/6==0)
        //         break;
        // }
        // if(IsGoodStr){
        //     ++j;
        //     IsGoodStr=0;
        // }
        int j{};
        lines_size = i.size();
        temp_student.course = getNum(i, j);
        temp_student.group = getNum(i, j);
        temp_student.surname = getStr(i, j);
        temp_student.name = getStr(i, j);
        temp_student.otchestvo = getStr(i, j);
        i = i.substr(j);
        temp_student.marks = getVec(i);
        students.push_back(temp_student);
        temp_student = Student(0, 0, "", "", "", std::vector<int16_t>{});
    }
    std::cout << "Students read: " << students.size() << '\n';
}

void sortingStudents(std::vector<Student> &students, std::ofstream &fout)
{
    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b)
              {
        if(a.course<b.course)   return 1;
        else if(a.course>b.course)  return 0;
        else{
            if(a.group<b.group)   return 1;
            else if(a.group>b.group)  return 0;
            else{
                if(a.surname<b.surname)   return 1;
                else if(a.surname>b.surname)  return 0;
                else{
                    if(a.name<b.name)    return 1;
                    else if(a.name>b.name)  return 0;
        return 0;
        }}} });
    fout << "Sorted students:\n";
    for (size_t i = 0; i < students.size(); ++i)
    {
        printStudent(students, fout, i);
    }
}

std::vector<int16_t> namesakes(std::vector<Student> &students)
{
    int n = students.size();
    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b)
              { return a.name > b.name; });
    std::vector<int16_t> id;
    for (size_t i = 0; i < n - 1; ++i)
    {
        if (students[i].name == students[i + 1].name)
        {
            while (i < n - 1 && students[i].name == students[i + 1].name)
            {
                id.push_back(i);
                ++i;
            }
            id.push_back(i);
            id.push_back(-1);
        }
    }
    return id;
}

void worstStudents(std::vector<Student> &students, std::ofstream &fout)
{
    bool IsOnce = 1;
    for (size_t i = 0; i < students.size(); ++i)
    {
        std::vector<int16_t> marks = students[i].marks;
        bool passed = 1;
        for (auto j : marks)
        {
            if (j < 4)
            {
                passed = 0;
                break;
            }
        }
        if (!passed)
        {
            if (IsOnce)
            {
                IsOnce = 0;
                fout << "Students who didnt pass:\n";
            }
            printStudent(students, fout, i);
        }
    }
    if (IsOnce)
    {
        fout << "All students passed\n\n";
    }
}

void exelentStudents(std::vector<Student> &students, std::ofstream &fout)
{
    bool IsOnce = 1;
    for (size_t i = 0; i < students.size(); ++i)
    {
        std::vector<int16_t> marks = students[i].marks;
        bool passed = 1;
        for (auto j : marks)
        {
            if (j < 9)
            {
                passed = 0;
                break;
            }
        }
        if (passed)
        {
            if (IsOnce)
            {
                IsOnce = 0;
                fout << "Exelent students:\n";
            }
            printStudent(students, fout, i);
        }
    }
    if (IsOnce)
    {
        fout << "There is no exelent students\n\n";
    }
}

void someUI(std::ofstream &fout)
{
    fout << "------------------------------------------------\n\n";
}

int main()
{
    try{
        std::ifstream fin("in.txt");
    std::ofstream fout("answer.txt");
    fileChecking(fin);

    std::vector<std::string> lines;
    getLines(lines, fin);
    fin.close();

    std::vector<Student> students;
    getStudents(students, lines);

    sortingStudents(students, fout);
    someUI(fout);
    std::vector<int16_t> id = namesakes(students);
    int n = id.size();
    if (n != 0)
    {
        fout << "namesakes:\n";
        for (size_t i = 0; i < n - 1; ++i)
        {
            if (id[i] == -1)
            {
                fout << "----\n";
            }
            else
            {
                printStudent(students, fout, id[i]);
            }
        }
    }
    else
    {
        fout << "There is no namesakes amoung the students\n\n";
    }
    someUI(fout);
    worstStudents(students, fout);
    someUI(fout);
    exelentStudents(students, fout);

    fout.close();
    }
    catch(const char *msg){
        std::cout<<msg;
    }
}