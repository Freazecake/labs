#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>

int get_status()
{
    int status;
    std::cout << "enter a way to enter array:\n\
    1-enter from keybord\n\
    2-enter random numbers\n\
    3-enter random numbers using the Mersenne vortex method\n";
    std::cout << "your choice: ";
    if (!(std::cin >> status))
        throw "you need to enter a number\n";
    return status;
}

template <typename T>
void keyboard_input(T &arr, int size)
{
    std::cout << "enter your array elements:\n";
    for (int i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            if (!(std::cin >> arr[i][j]))
            {
                throw "invalid input\n";
            }
        }
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
void rand_input(T &arr, int size)
{
    srand(time(0));
    int a, b;
    enterBorders(a, b);
    for (int i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            arr[i][j] = a + rand() % (b - a + 1);
        }
    }
}

template <typename T>
void new_rand_input(T &arr, int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    int a, b;
    enterBorders(a, b);
    std::uniform_int_distribution<> dist(a, b);
    for (int i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            arr[i][j] = dist(gen);
        }
    }
}

template <typename T>
int MaxElementInPositiveColumn(T &arr, int size)
{
    bool IsPos;
    int mx = -1;
    for (size_t j = 0; j < size; ++j)
    {
        IsPos = 1;
        for (size_t i = 0; i < size; ++i)
        {
            if (arr[i][j] < 0)
            {
                IsPos = 0;
                break;
            }
        }
        if (IsPos)
        {
            for (size_t i = 0; i < size; ++i)
            {
                if (arr[i][j] > mx)
                    mx = arr[i][j];
            }
        }
    }
    return mx;
}

int ArrayType()
{
    std::cout << "enter array type:\n\
    1-array new\n\
    2-std::vector\nYour choice: ";
    int status;
    if (!(std::cin >> status))
        throw "You need to enter a number 1 or 2";
    if (status < 1 && status > 2)
        throw "You need to enter a number 1 or 2";
    return status;
}

template <typename T>
void ArrayInputMethod(T &arr, int &size, bool &IskeyboardInput)
{
    switch (int status = get_status(); status)
    {
    case 1:
        keyboard_input(arr, size);
        IskeyboardInput = 1;
        break;
    case 2:
        rand_input(arr, size);
        break;
    case 3:
        new_rand_input(arr, size);
        break;
    default:
        throw "you entered wrong number!!!\n";
    }
}

template <typename T>
int SumOfNegative(T &arr, int size)
{
    int sum = 0;
    int n{};
    for (size_t i = 0; i < size; ++i)
    {
        ++n;
        for (int j = size - 1; j >= size - n; --j)
        {
            if (arr[i][j] < 0)
            {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}

template <typename T>
void print_matrix(T &arr, int size)
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
            std::cout << arr[i][j] << ' ';
        std::cout << std::endl;
    }
}

template <typename T>
void func(T arr, int size)
{
    bool IskeybordInput = 0;

    ArrayInputMethod(arr, size, IskeybordInput);
    if (!IskeybordInput)
    {
        std::cout << "received array:\n";
        print_matrix(arr, size);
    }
    int mx = MaxElementInPositiveColumn(arr, size);
    if (mx == -1)
    {
        std::cout << "there is no positive columns in the matrix\n";
    }
    else
    {
        std::cout << "Max element of the matrix in positive column is: " << mx << '\n';
    }
    int sum = SumOfNegative(arr, size);
    if (sum == 0)
    {
        std::cout << "there is no negative elements in the matrix's lower right triangle\n";
    }
    else
    {
        std::cout << "Sum of negstive elements of the matrix's lower right triangle is: " << sum << '\n';
    }
}

// template<typename T>
// T generateArray(int size) {
//     if (ArrayType()==2) {
//         std::vector<std::vector<int>> arr (size, std::vector<int>(size));
//         return arr;
//     }
//     else {
//         int** arr = new int*[size];
//         for(size_t i=0;i<size;++i){
//             arr[i] = new int[size];
//         }
//         return arr;
//     }
// }

int main()
{
    try
    {
        int size;
        std::cout << "enter size of the matrix: ";
        std::cin >> size;
        if (!std::cin >> size)
        {
            throw "you need to enter a number\n";
        }

        switch (ArrayType())
        {
        case 1:
            int **arr = new int *[size];
            for (size_t i = 0; i < size; ++i)
            {
                arr[i] = new int[size];
            }
            func(arr, size);
            break;
        case 2:
            std::vector<std::vector<int>> arr(size, std::vector<int>(size));
            func(arr, size);
            break;
        }
    }
    catch (const char *msg)
    {
        std::cout << msg;
    }
}