#include <iostream>
#include<fstream>
#include<type_traits>
#include<cstdint>
#include<random>
#include<vector>

int get_type_status(){
    int status;
    std::cout << "enter a vector type:\n\
    1-int vector\n\
    2-double vector\n\
    3-char* vector\n";
    std::cout << "your choice: ";
    if (!(std::cin >> status))
        throw "you need to enter a number\n";
    return status;
}

void fileChecking(std::ifstream &fin)
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

int get_status()
{
    int status;
    std::cout << "enter a input data:\n\
    1-input from keybord and output in file\n\
    2-input random numbers and output in file\n\
    3-inputfrom file and output in terminal\n";
    std::cout << "your choice: ";
    if (!(std::cin >> status))
        throw "you need to enter a number\n";
    return status;
}

template <typename T> void keyboard_input(std::vector<T> &arr)
{
    static_assert(std::is_arithmetic_v<T>);
    std::cout << "enter your array elements:\n";
    T n;
    while(std::cin){
        if (!(std::cin >> n))
            throw "invalid input\n";
        arr.push_back(n);
    }
}

void keyboard_input(std::vector<char *> &arr, int size)
{
    std::cout << "enter your array elements:\n";
    std::cin.ignore();
    for (int i = 0; i < size; ++i)
    {
        std::cin.getline(arr[i], 10000);
    }
}

void enterBorders(int &a, int &b)
{
    std::cout << "enter borders: ";
    if (!(std::cin >> a >> b))
    {
        throw "you need to enter numbers";
    }
    if (a > b)
        std::swap(a, b);
}

template <typename T>
void new_rand_input(std::vector<T> &arr, int32_t size)
{
    static_assert(std::is_arithmetic_v<T>);
    std::random_device rd;
    std::mt19937 gen(rd());
    int a, b;
    enterBorders(a, b);
    std::uniform_int_distribution<> dist(a, b);
    for (int i = 0; i < size; ++i)
    {
        arr[i] = dist(gen);
    }
}

int32_t enter_size(){
    std::cout<<"enter size of you vector: ";
    int32_t size;
    if(!(std::cin>>size))
        throw "you need to enter a number";
}

template <typename T>
void ArrayInputMethod(std::vector<T> &arr)
{
    switch (int status = get_status(); status)
    {
    case 1:
        keyboard_input(arr);
        break;
    case 2:{
        int32_t size = enter_size();
        new_rand_input(arr, size);
        break;
    }
    case 3:{
        std::ifstream fin("in.txt");
        std::ofstream fout("out.txt");
        fileChecking(fin);
        file_input(fin);
        break;
    }
        
    }
}

int main()
{
    try
    {
        
        switch (int status = get_type_status(); status)
        {
        case 1:{
            std::vector<int32_t> arr;
            ArrayInputMethod(arr);
            break;
        }
        case 2:{
            std::vector<double> arr;
            ArrayInputMethod(arr);
            break;
        }
        case 3:{
            std::vector<char *> arr;
            ArrayInputMethod(arr);
            break;
        }  
        }
    }
    catch (const char *msg)
    {
        std::cout << msg;
    }
}