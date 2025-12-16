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
        throw std::runtime_error("file doesnt exist");
    }
    if (!fin)
    {
        throw std::runtime_error("file error");
    }
    if (fin.peek() == EOF)
    {
        throw std::"file is empty";
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
                auto it = subjectPointer.find(word);
                if(it!=subjectPointer.end()){
                    it->second.push_back(i);
                }
                else{
                    subjectPointer.emplace(std::pair<std::string, std::vector<size_t>>(word, {i}));
                }
            }
        }fin.close();
        for(auto i : subjectPointer){
            fout<<i.first<< ": ";
            for (auto j : i.second){
                fout<<j<<" ";
            }
            fout<<'\n';
        }
        std::cout<<"All is Done!";
        fout.close();
    }catch(std::exception &e){
        std::cerr<<"Caught "<<e.what();
    }
    catch(const char *msg){
        std::cout<<msg;
    }
}