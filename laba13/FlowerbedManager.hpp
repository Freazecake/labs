#pragma once

#include "Flowerbed.hpp"

class FlowerbedManager{
    private:
        std::vector<Flowerbed> data;
        void getDataFromFile(std::ifstream&);
    public:
        FlowerbedManager(const std::vector<Flowerbed>&);
        FlowerbedManager(std::ifstream&);
        ~FlowerbedManager();

        void dataSort();
        void print();
        void printFlowers(std::vector<std::string>&);

        std::vector<std::string> getAllFlowers();
        std::vector<size_t> findFlowerbedWIthNoFlower(std::string);
        std::vector<std::string> findFlowerInEveryFlowerbed();
        size_t numberOfFlowerbedsWithNumberOfFlowers(size_t);
        void renameFlower(std::string, std::string);
};