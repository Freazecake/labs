#include "firstIntegral.h"
#include "secondIntegral.h"
#include "thirdIntegral.h"

int main()
{
    try
    {
        firstIntegral();
    }
    catch (const char *msg)
    {
        std::cout << msg<<std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    try
    {
        secondIntegral();
    }
    catch (const char *msg)
    {
        std::cout << msg<<std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    try
    {
        thirdIntegral();
    }
    catch (const char *msg)
    {
        std::cout << msg<<std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}