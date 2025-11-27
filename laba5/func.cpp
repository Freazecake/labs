#include <iostream>

int get_status()
{
    int status;
    std::cout << "enter a way to integrate the function:\n\
    1-left rectangle formula\n\
    2-right rectangle formula\n\
    3-average rectangle formula\n\
    4-trapezoid formula\n\
    5-Simpson's formula (parabolic trapezoids)\n";
    std::cout << "your choice: ";
    if (!(std::cin >> status))
        throw "you need to enter a number\n";
    return status;
}

double getEpsilon()
{
    std::cout << "enter the precision: ";
    double e{};
    if (!(std::cin >> e))
    {
        throw "you need to enter a number\n";
    }
    if (e < 0 || e > 1)
    {
        throw "you need to enter a number between 0 and 1\n";
    }
    return e;
}

void enterBorders(double &a, double &b)
{
    std::cout << "enter borders: ";
    if (!(std::cin >> a >> b))
    {
        throw "you need to enter numbers";
    }
    if (a > b)
        std::swap(a, b);
}