#include <iostream>
#include <cstdlib>
#include <random>
#include "project1_helper.cpp"
#include "sort.cpp"

const int MAX_SIZE = 100;

void check_size(int size)
{
    if (MAX_SIZE < size || size < 0){
        throw "wrong array size\n";
    }
}

void sort_by_frequency(int *arr, int size)
{
    bool IsGoodNumber = 1;
    ArraySortMethod(arr, size, IsGoodNumber);
    int* freq = new int [size]{};
    int* value = new int [size];
    int j = 0;
    arrayCompletion(freq, value, arr, j, size);
    bubbleSortByFrequency(freq, value, j);
    // finalSort(freq, value, arr, j);
    std::cout << "sorted by frequency array: ";
    print_array(fs(freq, value, arr, j), size);
    delete[] freq;
    delete[] value;
}

int main()
{
    bool IsGoodNumber = 1;
    bool IskeybordInput = 0;
    int arr[MAX_SIZE];
    int size;
    try
    {
        std::cout << "enter array size: ";
        std::cin >> size;
    if(!std::cin >> size)
    {
        throw "you need to enter a number!!!\n";
    }
    check_size(size);
        ArrayInputMethod(arr, size, IskeybordInput, IsGoodNumber);
        if (IsGoodNumber)
        {
            if (!IskeybordInput)
            {
                std::cout<<"received array: ";
                print_array(arr, size);
            }
            std::cout<<"the sum of array elements with even number: "<< sum_even_number(arr, size) <<'\n';
            try{
                std::cout<<"the sum of array elements between 2 zero elements: "<<sum_between_zero_elements(arr, size) << '\n';
                std::cout<<"the sum of array elements between first 2 positive elements: "<<sum_between_positive(arr, size)<<'\n';
            }
            catch(const char* msg){
                std::cout<<msg;
            }
            std::cout<<"the maximum modulo element of the array: "<<max_abs_element(arr, size)<<'\n';
            negative_sort(arr, size);
            sort_by_frequency(arr, size);
        
    }
   } catch(const char* msg)
   {
        std::cout << msg;
   }
    return 0;
}