#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct SMark
{
    std::string subject;
    int mark{};

    SMark();
    SMark(std::string _name, int _mark) : subject(_name), mark(_mark) {};
};

struct SStudData
{
    std::string name;
    int number;
    std::vector<SMark> marks;

    SStudData(std::string _name, int _number, std::vector<SMark> _marks) : name(_name), number(_number), marks(_marks) {};
};

void checkInputFile(std::ifstream &fin)
{
    if (!fin.good())
    {
        throw "file doesnt exist";
    }
    if (!fin)
    {
        throw "file error";
    }
    if (fin.peek() == EOF)
    {
        throw "file is empty";
    }
}

std::map<int, SStudData> getData(std::ifstream &fin, std::map<int, SStudData> data)
{
    std::string line;
    while (getline(fin, line))
    {
        if (line.empty())
            continue;
        size_t n = line.size();
        std::string name;
        int number;
        std::vector<SMark> marks;
        bool nameIsGot = false;
        bool numberIsGot = false;
        for (size_t i = 0; i < n; ++i)
        {
            if (line[i] == ' ')
                continue;
            while (true)
            {
                if (line[i] == ',' || nameIsGot){
                    nameIsGot = true;
                    ++i;
                    break;
                }
                if (i == n)
                    break;
                name += line[i];
                ++i;
            }
            if(nameIsGot && !numberIsGot){
                size_t numberLength{};
                number = std::stoi(line.substr(i), &numberLength);
                i+=numberLength;
                numberIsGot=true;
            }
            if(nameIsGot && numberIsGot){
                bool subjectIsGot = false;
                bool markIsGot = false;
                std::string subj;
                int mark;
                while(i<n){
                while(line[i]==' ' || line[i]==','){
                    ++i;
                }
                    if(!subjectIsGot){
                        while(line[i]!=':' && i<n){
                        subj+=line[i];
                        ++i;
                        }
                        subjectIsGot=true;
                    }
                    if(subjectIsGot){
                        if(isdigit(line[i])){
                            size_t markLenth{};
                            mark = std::stoi(line.substr(i), &markLenth);
                            i+=markLenth;
                            markIsGot=true;
                        }
                        else{
                            ++i;
                        }
                    }
                    if(markIsGot){
                        SMark temp(subj, mark);
                        marks.push_back(temp);
                        subjectIsGot=false;
                        markIsGot=false;
                        subj.clear();
                    }
                }
            }
        }
        SStudData studentData(name, number, marks);
        data.emplace(number, studentData);
    }
    return data;
}

void printStudent(std::pair<int, SStudData> i){
    std::cout<<i.first<<" - ";
    auto studData = i.second;
    std::cout<<studData.name<<' ';
    for(auto j : studData.marks){
        std::cout<<j.subject<<": "<<j.mark<<"; ";
    }
    std::cout<<'\n';
}

void printData(std::map<int, SStudData> &data){
    for(auto i : data){
        printStudent(i);
    }
}

std::vector<double> getAverageMark(std::map<int, SStudData> &data){
    std::vector<double> averageMark;
    for(auto i : data){
        auto studData = i.second;
        int marks_sum{};
        for(auto j : studData.marks){
            marks_sum+=j.mark;
        }
        double average = static_cast<double>(marks_sum)/studData.marks.size();
        averageMark.push_back(average);
    }
    return averageMark;
}

void printStudent(std::pair<int, SStudData> i, double average){
    printStudent(i);
    std::cout<<"Average mark: "<<average<<"\n\n";
}

std::vector<std::pair<SStudData, double>> sortingStudents(std::map<int, SStudData> &data, std::vector<double> &averageMarks){
    std::vector<std::pair<SStudData, double>> para;
    size_t n{};
    for(auto i : data){
        std::pair<SStudData, double> temp = {i.second, averageMarks[n]};
        para.push_back(temp);
        ++n;
    }
    std::sort(para.begin(), para.end(), [](std::pair<SStudData, double> &a, std::pair<SStudData, double> &b){
        if(a.first.name == b.first.name){
            return a.second < b.second;
        }
        return a.first.name < b.first.name;
    });
    return para;
}

void printPara(const std::vector<std::pair<std::string, double>> &para){
    bool IsOnce = false;
    for(auto i : para){
        if(!IsOnce){
            IsOnce=true;
            std::cout<<"Subjects and their average:\n";
        }
        std::cout<<i.first<<": "<<i.second<<'\n';
    }
    if(!IsOnce){
        std::cout<<"There is no marks!\n";
    }
}

void printPara(const std::vector<std::pair<SStudData, double>> &para){
    for(auto i : para){
        std::pair<int, SStudData> temp = {i.first.number, i.first};
        printStudent(temp, i.second);
    }
}


void printData(std::map<int, SStudData> &data, std::vector<double> &averageMarks){
    size_t num{1};
    std::vector<std::pair<SStudData, double>> para = sortingStudents(data, averageMarks);
    printPara(para);
}

void getBounds(double &a, double &b){
    std::cout<<"Enter bounds of the average mark: ";
    if (!(std::cin >> a >> b))
        throw "you need to enter numbers";
    if (a > b)
        std::swap(a, b);
}

void printDataByAverage(std::map<int, SStudData> &data, std::vector<double> &averageMarks){
    double a, b;
    getBounds(a, b);
    size_t n = averageMarks.size();
    bool IsOnce=false;
    size_t i=0;
    for(auto j : data){
        if(averageMarks[i]>=a && averageMarks[i]<=b){
            if(!IsOnce){
                std::cout<<"Students with the average between "<<a<<" and "<<b<<":\n";
                IsOnce=true;
            }
            printStudent(j, averageMarks[i]);
        }
        ++i;
    }
    if(!IsOnce){
        std::cout<<"There is no students with the average between "<<a<<" and "<<b<<'\n';
    }
}

void printStudentsWhoPassedSubject(std::map<int, SStudData> &data){
    std::cout<<"Enter the subject: ";
    std::string subject;
    std::cin.ignore();
    getline(std::cin, subject);
    bool IsOnce = false;
    for(auto i : data){
        for(auto j : i.second.marks){
            if(j.subject == subject){
                if(!IsOnce){
                    std::cout<<"Students who get mark on "<< subject<<":\n";
                    IsOnce=true;
                }
                printStudent(i);
            }
        }
    }
    if(!IsOnce){
        std::cout<<"Nobody get mark on this subject\n";
    }
}

void shell_sort(std::vector<size_t> &arr)
{
    int size = arr.size();
    for (int i = size / 2; i > 0; i /= 2)
    {
        for (int j = i; j < size; ++j)
        {
            int k = j;
            while (k > i - 1 && arr[k] > arr[k - i])
            {
                std::swap(arr[k], arr[k - i]);
                k -= i;
            }
        }
    }
}

std::map<std::string, std::vector<size_t>> getSubjectsAndStudents(std::map<int, SStudData> &data,\
                                                std::map<std::string, std::vector<size_t>> subj)
{
    size_t q{};
    for(auto i : data){
        for(auto j : i.second.marks){
            auto it = subj.find(j.subject);
            if(it!=subj.end()){
                it->second.push_back(q);
            }
            else{
                subj.emplace(std::pair<std::string, std::vector<size_t>>(j.subject, {q}));
            }
        }
        ++q;
    }
    for(auto i : subj){
        shell_sort(i.second);
    }
    return subj;
}

void makeUnique(std::map<std::string, std::vector<size_t>> &subj){
    for(auto i : subj){
        for(size_t j = 0;j<i.second.size()-1;++j){
            if(i.second[j]==i.second[j+1]){
                i.second.erase(i.second.begin()+j);
                --j;
            }
        }
    }
}

void printSubjectsAndStudents(std::map<int, SStudData> &data){
    std::map<std::string, std::vector<size_t>> subj;
    subj = getSubjectsAndStudents(data, subj);
    makeUnique(subj);
    if(!subj.empty()){
        std::cout<<"Subjects:\n";
    }
    for(auto i : subj){
        std::cout<<i.first<< ": ";
        std::cout<<i.second.size();
        std::cout<<'\n';
    }
}

std::vector<double> getAverage(const std::map<std::string, std::vector<size_t>> &subj){
    std::vector<double> average;
    for(auto i : subj){
        double sum{};
        size_t n = i.second.size();
        for(size_t j = 0;j<n;++j){
            sum += i.second[j];
        }
        sum /= n;
        average.push_back(sum);
    }
    return average;
}

std::vector<std::pair<std::string, double>> getAndSort(std::map<std::string, std::vector<size_t>> &subj, std::vector<double> average){
    std::vector<std::pair<std::string, double>> para;
    size_t n{};
    for(auto i : subj){
        std::pair<std::string, double> temp = {i.first, average[n]};
        para.push_back(temp);
        ++n;
    }
    std::sort(para.begin(), para.end(), [](std::pair<std::string, double> a, std::pair<std::string, double> b){
        return a.second<b.second;
    });
    return para;
}

std::map<std::string, std::vector<size_t>> getSubjectsAndStudents2(std::map<int, SStudData> &data,\
                                                std::map<std::string, std::vector<size_t>> subj)
{
    for(auto i : data){
        for(auto j : i.second.marks){
            auto it = subj.find(j.subject);
            if(it!=subj.end()){
                it->second.push_back(j.mark);
            }
            else{
                subj.emplace(std::pair<std::string, std::vector<size_t>>(j.subject, {static_cast<size_t>(j.mark)}));
            }
        }
    }
    for(auto i : subj){
        shell_sort(i.second);
    }
    return subj;
}

void printAverageSubject(std::map<int, SStudData> &data){
    std::map<std::string, std::vector<size_t>> subj;
    std::vector<double> average;
    subj = getSubjectsAndStudents2(data, subj);
    average = getAverage(subj);
    std::vector<std::pair<std::string, double>> para = getAndSort(subj, average);
    printPara(para);
}

void findAndPrintBestStudents(std::map<int, SStudData> &data){
    std::vector<std::pair<int, SStudData>> para;
    int max{-1};
    for(auto i : data){
        int sum{};
        for(auto j : i.second.marks){
            sum+=j.mark;
        }
        if(sum>max){
            para.clear();
            para.push_back(i);
            max=sum;
        }
        else if(sum==max){
            para.push_back(i);
        }
    }
    size_t n = para.size();
    bool IsOnce = false;
    for(size_t i=0;i<n;++i){
        if(!IsOnce){
            std::cout<<"Best Students:\n";
            IsOnce=true;
        }
        printStudent(para[i]);
    }
    if(!IsOnce){
        std::cout<<"Students got 0 marks yet\n";
    }
}

void findAndPrintWorstStudents(std::map<int, SStudData> &data){
    bool IsOnce = false;
    for(auto i : data){
        bool IsWorst=false;
        for(auto j : i.second.marks){
            if(j.mark<4){
                IsWorst=true;
            }
        }
        if(IsWorst){
            if(!IsOnce){
                std::cout<<"Bad students:\n";
                IsOnce=true;
            }
            printStudent(i);
            
        }
    }
    if(!IsOnce){
        std::cout<<"There is no bad students!";
    }
}

int main()
{
    try
    {
        std::map<int, SStudData> data;
        std::ifstream fin("in.txt");
        checkInputFile(fin);
        data = getData(fin, data);
        fin.close();
        // printData(data);
        // std::vector<double> averageMarks;
        // averageMarks = getAverageMark(data);
        // printData(data, averageMarks);
        // printDataByAverage(data, averageMarks);
        // printStudentsWhoPassedSubject(data);
        // printSubjectsAndStudents(data);
        printAverageSubject(data);
        findAndPrintBestStudents(data);
        findAndPrintWorstStudents(data);
    }
    catch (const char *msg)
    {
        std::cout << msg;
    }
}