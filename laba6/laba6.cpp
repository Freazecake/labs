#include <cstdint>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <type_traits>
#include <vector>

int get_type_status()
{
    int status{};
    std::cout << "enter a vector type:\n"
                 "    1-int vector\n"
                 "    2-double vector\n"
                 "    3-string vector\n"
                 "your choice: ";
    if (!(std::cin >> status))
        throw "you need to enter a number\n";
    return status;
}

int get_status()
{
    int status{};
    std::cout << "enter input mode:\n"
                 "    1-keyboard input -> write to file\n"
                 "    2-random generate -> write to file\n"
                 "    3-read from file -> print to console\n"
                 "your choice: ";
    if (!(std::cin >> status))
        throw "you need to enter a number\n";
    return status;
}

void fileChecking(std::ifstream &fin)
{
    if (!fin.good())
        throw "file doesnt exist";
    if (!fin)
        throw "file error";
    if (fin.peek() == EOF)
        throw "file is empty";
}

int32_t enter_size()
{
    std::cout << "enter size of your vector: ";
    int32_t size{};
    if (!(std::cin >> size))
        throw "you need to enter a number";
    if (size <= 0)
        throw "size must be positive";
    return size;
}

int32_t enter_string_size(int32_t i)
{
    std::cout << "enter size of your string number " << i + 1 << ": ";
    int32_t size{};
    if (!(std::cin >> size))
        throw "you need to enter a number";
    if (size <= 0)
        throw "size must be positive";
    return size;
}

void enterBorders(int &a, int &b)
{
    std::cout << "enter borders: ";
    if (!(std::cin >> a >> b))
        throw "you need to enter numbers";
    if (a > b)
        std::swap(a, b);
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
void keyboard_input(std::vector<T> &arr, int32_t size)
{
    arr.resize(size);
    std::cout << "enter your array elements:\n";
    for (int32_t i = 0; i < size; ++i)
    {
        if (!(std::cin >> arr[i]))
            throw "invalid input\n";
    }
}

void keyboard_input(std::vector<std::string> &arr, int32_t size)
{
    arr.resize(size);
    std::cout << "enter your array elements:\n";
    std::cin.ignore();
    for (int32_t i = 0; i < size; ++i)
        std::getline(std::cin, arr[i]);
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
void new_rand_input(std::vector<T> &arr, int32_t size)
{
    arr.resize(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    int a{}, b{};
    enterBorders(a, b);
    std::uniform_int_distribution<> dist(a, b);
    for (int32_t i = 0; i < size; ++i)
        arr[i] = static_cast<T>(dist(gen));
}

void new_rand_input(std::vector<std::string> &arr, int32_t size)
{
    arr.resize(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 94);
    for (int32_t i = 0; i < size; ++i)
    {
        int32_t s_size = enter_string_size(i);
        for (int32_t j = 0; j < s_size; ++j)
            arr[i] += ' ' + dist(gen);
    }
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
void file_input(std::vector<T> &arr, std::ifstream &fin)
{
    fileChecking(fin);
    T temp;
    while (fin >> temp)
    {
        arr.push_back(temp);
    }
}

void file_input(std::vector<std::string> &arr, std::ifstream &fin)
{
    fileChecking(fin);
    std::string temp;
    while (getline(fin, temp))
    {
        arr.push_back(temp);
    }
}

template <typename T>
void insert_sort(std::vector<T> &arr, int32_t size)
{
    for (int32_t i = 0; i < size; ++i)
    {
        for (int32_t j = i; j > 0 && arr[j - 1] > arr[j]; --j)
        {
            std::swap(arr[j], arr[j - 1]);
        }
    }
}

template <typename T>
void write_to_file(const std::vector<T> &arr, std::ofstream &fout)
{
    for (const auto &v : arr)
        fout << v << '\n';
}

template <typename T>
void print_array(const std::vector<T> &arr)
{
    for (const auto &v : arr)
        std::cout << v << '\n';
}

template <typename T>
void ArrayInputMethod(std::vector<T> &arr)
{
    switch (int status = get_status(); status)
    {
    case 1:
    {
        int32_t size = enter_size();
        keyboard_input(arr, size);
        std::ofstream fout("out.txt");
        fout << "Unsorted vector:\n";
        write_to_file(arr, fout);
        fout << "----------------------------------------------------------\n";
        insert_sort(arr, size);
        fout << "Sorted vector:\n";
        write_to_file(arr, fout);
        fout.close();
        break;
    }
    case 2:
    {
        int32_t size = enter_size();
        new_rand_input(arr, size);
        std::ofstream fout("out.txt");
        fout << "Unsorted vector:\n";
        write_to_file(arr, fout);
        fout << "----------------------------------------------------------\n";
        insert_sort(arr, size);
        fout << "Sorted vector:\n";
        write_to_file(arr, fout);
        fout.close();
        break;
    }
    case 3:
    {
        std::ifstream fin("in.txt");
        file_input(arr, fin);
        fin.close();
        std::cout << "Unsorted vector:\n";
        print_array(arr);
        std::cout << "----------------------------------------------------------\n";
        int32_t size = arr.size();
        insert_sort(arr, size);
        std::cout << "Sorted vector:\n";
        print_array(arr);
        break;
    }
    default:
        throw "unknown input mode";
    }
}

int main()
{
    try
    {
        switch (int status = get_type_status(); status)
        {
        case 1:
        {
            std::vector<int32_t> arr;
            ArrayInputMethod(arr);
            break;
        }
        case 2:
        {
            std::vector<double> arr;
            ArrayInputMethod(arr);
            break;
        }
        case 3:
        {
            std::vector<std::string> arr;
            ArrayInputMethod(arr);
            break;
        }
        default:
            std::cout << "unknown type\n";
        }
    }
    catch (const char *msg)
    {
        std::cout << msg;
    }
    return 0;
}
