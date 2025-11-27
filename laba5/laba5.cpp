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
        std::cout << msg;
    }
    try
    {
        secondIntegral();
    }
    catch (const char *msg)
    {
        std::cout << msg;
    }
    try
    {
        thirdIntegral();
    }
    catch (const char *msg)
    {
        std::cout << msg;
    }
}