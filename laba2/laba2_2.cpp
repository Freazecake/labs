#include <iostream>
#include <cmath>
#include <cstdint>

void calcDigits(int64_t num, int *digits, int &digitNumber)
{
    while (num > 0)
    {
        digits[digitNumber] = num % 10;
        ++digitNumber;
        num /= 10;
    }
}

bool IsArmstrongNumber(int64_t num)
{
    int digitNumber{};
    int digits[20];
    calcDigits(num, digits, digitNumber);
    int64_t sum{};
    for (size_t i = 0; i < digitNumber; ++i)
    {
        sum += pow(digits[i], digitNumber);
    }
    return sum == num;
}

int main()
{
    try
    {
        int64_t n;
        bool IsOneNumber = 0;
        std::cout << "enter upper bound: ";
        if (!(std::cin >> n))
            throw "you need to enter a number\n";
        if (n<0)    throw "number shold be positive";
        for (size_t i = 1; i <= n; ++i)
        {
            if (IsArmstrongNumber(i))
            {
                if (!IsOneNumber)
                {
                    IsOneNumber = 1;
                    std::cout << "Armstrong numbers: ";
                }
                std::cout << i << " ";
            }
        }
    }
    catch (const char *msg)
    {
        std::cout << msg;
    }
}