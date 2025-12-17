#include "../include/Flowerbed.hpp"

Flowerbed::Flowerbed(size_t num, std::string _shape, std::list<std::string> _flowers)\
         : number(num), shape(_shape), flowers(_flowers)
{
}

Flowerbed::~Flowerbed(){}

