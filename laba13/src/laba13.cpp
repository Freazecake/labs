#include "../include/FlowerbedManager.hpp"
#include <iostream>

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

int main(){
    try{
        std::ifstream fin("in.txt");
        checkInputFile(fin);
        FlowerbedManager data(fin);
        fin.close();
        data.dataSort();
        std::vector<std::string> flowers = data.getAllFlowers();
        data.printFlowers(flowers);
        std::string flower;
        std::cout<<"Enter a flower to find: ";
        getline(std::cin, flower);
        std::vector<size_t> flowerbeds = data.findFlowerbedWIthNoFlower(flower);
        if(!flowerbeds.empty()){
            std::cout<<"This flower is not in ";
        for(const auto &i : flowerbeds){
            std::cout<<i<<' ';
        }
        std::cout<<"flowerbeds\n";
        }
        else{
            std::cout<<"There is no such flower in the flowerbeds\n";
        }
        std::vector<std::string> temp = data.findFlowerInEveryFlowerbed();
        if(temp.empty()){
        std::cout<<"there is no flower that is in each flowerbed\n";
        }
        else{
            std::cout<<"Flowers that are in each flowerbed:\n";
            data.printFlowers(temp);
        }
        size_t number;
        std::cout<<"enter number of flowers on flowerbeds: ";
        if(!(std::cin>>number)){
            throw "you need to enter a number!";
        }
        std::cout<<"Number of flowerbeds with "<<number<<" flowers: "<<data.numberOfFlowerbedsWithNumberOfFlowers(number)<<'\n';
        std::string new_name, name;
        std::cout<<"enter previous name of the flower: ";
        std::cin.ignore();
        getline(std::cin, name);
        std::cout<<"enter new name for the flower: ";
        getline(std::cin, new_name);
        data.renameFlower(name, new_name);
        data.print();
    }catch(const char* msg){
        std::cout<<msg;
    }
    return 0;
}