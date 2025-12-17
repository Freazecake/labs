#include "../include/FlowerbedManager.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>

#define thisShittyPants this

FlowerbedManager::FlowerbedManager(const std::vector<Flowerbed> &a) : data(a){}
FlowerbedManager::FlowerbedManager(std::ifstream &fin) {
    thisShittyPants->getDataFromFile(fin);
}

FlowerbedManager::~FlowerbedManager(){
}

void FlowerbedManager::getDataFromFile(std::ifstream &fin){
    std::string line;
    while(getline(fin, line)){
        size_t num;
        std::string shape;
        std::list<std::string> flowers;
        std::string temp;
        size_t n = line.size(), i{};
        bool IsTrue = false;
        while(i<n){
            if(!IsTrue){
                num = std::stoi(line, &i);
                ++i;
                while(i<n && !isalpha(line[i])){
                    ++i;
                }
                while(i<n && line[i]!=';'){
                    shape+=line[i];
                    ++i;
                }
                IsTrue=true;
            }
            else{
                while(i<n && !isalpha(line[i])){
                    ++i;
                }
                while(i<n && line[i]!=','){
                    temp+=line[i];
                    ++i;
                }
                flowers.push_back(temp);
                temp.clear();
            }
            ++i;
        }
        Flowerbed data_temp(num, shape, flowers);
        data.push_back(data_temp);
    }
}

void FlowerbedManager::dataSort(){
    std::sort(data.begin(), data.end(), [](const Flowerbed &a, const Flowerbed &b){
        if(a.shape == b.shape){
            return a.number > b.number;
        }
        return a.shape < b.shape;
    });
}

std::vector<std::string> FlowerbedManager::getAllFlowers(){
    std::vector<std::string> flowers;
    for(auto i : data){
        for(auto j : i.flowers){
            auto it = find(flowers.begin(), flowers.end(), j);
            if(it==flowers.end()){
                flowers.push_back(j);
            }
        }
    }
    std::sort(flowers.begin(), flowers.end());
    return flowers;
}

std::vector<size_t> FlowerbedManager::findFlowerbedWIthNoFlower(std::string flower){
    std::vector<size_t> result;
    for(auto i : data){
        bool IsHere = false;
        for(auto j : i.flowers){
            if(j==flower){
                IsHere=true;
                break;
            }
        }
        if(!IsHere){
            result.push_back(i.number);
        }
    }
    return result;
}

std::vector<std::string> FlowerbedManager::findFlowerInEveryFlowerbed(){
    std::vector<std::string> result;
    std::vector<std::string> flowers = getAllFlowers();
    for(auto flower : flowers){
        bool IsGood=false;
        for(auto i : data){
            for(auto j : i.flowers){
                if(j == flower){
                    IsGood=true;
                    break;
                }
                else{
                    IsGood=false;
                }
            }
            if(!IsGood){
                break;
            }
        }
        if(IsGood){
            result.push_back(flower);
        }        
    }
    return result;
}

size_t FlowerbedManager::numberOfFlowerbedsWithNumberOfFlowers(size_t num){
    size_t number{};
    for(auto i : data){
        if(i.flowers.size()==num){
            ++number;
        }
    }
    return number;
}

void FlowerbedManager::renameFlower(std::string name, std::string new_name){
    for(auto &i : data){
        for(auto &j : i.flowers){
            if(j == name){
                j=new_name;
            }
        }
    }
}

void FlowerbedManager::print(){
    for(auto i : data){
        std::cout<<i.number<<". Shape: "<<i.shape<<", Flowers: ";
        for(auto j : i.flowers){
            std::cout<<j<<' ';
        }
        std::cout<<'\n';
    }
}

void FlowerbedManager::printFlowers(std::vector<std::string>& flowers){
    std::cout<<"Flowers: ";
    for(auto i : flowers){
        std::cout<<i<<' ';
    }
    std::cout<<'\n';
}