#include <iostream>
#include <fstream>
#include <exception>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>

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

void checkOutputFile(std::ofstream &fout)
{
    if (!fout)
    {
        throw "file error";
    }
}

int main(){
    try{
        std::ifstream fin("in.txt");
        std::ofstream fout("out.txt");
        checkInputFile(fin);
        checkOutputFile(fout);

        std::unordered_map<std::string, std::vector<size_t>> subjectPointer;
        std::string str;
        size_t i{};
        while(std::getline(fin, str)){
            ++i;
            std::stringstream line(str);
            std::string word;

            while(line>>word){
                if(subjectPointer.find(word)==subjectPointer.end()){
                    subjectPointer[word].back();
                }
                else{
                    subjectPointer[word];
                }
            }
        }
    }catch(std::exception &e){
        std::cerr<<"Caught "<<e.what();
    }
}