#pragma once

#include <vector>
#include <string>
#include <list>
#include <fstream>

class Flowerbed{
    public:
        size_t number;
        std::string shape;
        std::list<std::string> flowers;
    public:
        Flowerbed(size_t, std::string, std::list<std::string>);
        ~Flowerbed();
};