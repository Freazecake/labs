#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>
#include <random>

template<typename T>
void bubble_sort(std::vector<T>& arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template<typename T>
void insert_sort(std::vector<T>& arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j)
        {
            std::swap(arr[j], arr[j - 1]);
        }
    }
}

template<typename T>
void selection_sort(std::vector<T>& arr, int size)
{
    T mn;
    for (int i = 0; i < size; ++i)
    {
        mn = arr[i];
        int k{i};
        for (int j = i; j < size; ++j)
        {
            if (arr[j] < mn)
            {
                mn = arr[j];
                k = j;
            }
        }
        std::swap(arr[k], arr[i]);
    }
}

template<typename T>
int partition(std::vector<T>& arr, int start, int end)
{
    int i{start - 1}, j{};
    for (j = start; j < end; ++j)
    {
        if (arr[j] < arr[end])
        {
            ++i;
            std::swap(arr[j], arr[i]);
        }
    }
    ++i;
    std::swap(arr[j], arr[i]);
    return i;
}

template<typename T>
void quick_sort(std::vector<T>& arr, int start, int end)
{
    if (end <= start)
    {
        return;
    }
    int x = partition(arr, start, end);
    quick_sort(arr, start, x - 1);
    quick_sort(arr, x + 1, end);
}


template<typename T>
void merge_sort(std::vector<T>& arr, int size)
{
    int x = size / 2;
    if (size < 2)
    {
        return;
    }
    std::vector<T> arr1;
    std::vector<T> arr2;
    for (int i = 0; i < x; ++i)
    {
        arr1[i] = arr[i];
    }
    for (int i = x; i < size; ++i)
    {
        arr2[i - x] = arr[i];
    }
    merge_sort(arr1, x);
    merge_sort(arr2, size - x);
    int i{}, j{}, k{};
    while (i < x && j < size - x)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            ++i;
            ++k;
        }
        else
        {
            arr[k] = arr2[j];
            ++j;
            ++k;
        }
    }
    while (i < x)
    {
        arr[k] = arr1[i];
        ++i;
        ++k;
    }
    while (j < size - x)
    {
        arr[k] = arr2[j];
        ++j;
        ++k;
    }
}

void counting_sort(std::vector<int> &arr, int size)
{
    bool q = 1;
    int arr1[100] = {};
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < 0 || arr[i] > 99)
        {
            std::cout << "all elements of the array are not in the range of 0 to 99\n";
            return;
        }
    }
    for (int i = 0; i < size; ++i)
    {
        int w = arr[i];
        ++arr1[w];
    }
    int j = 0;
    for (int i = 0; i < 100; ++i)
    {
        while (arr1[i] != 0)
        {
            arr[j] = i;
            --arr1[i];
            ++j;
        }
    }
}

template<typename T>
void counting_sort(std::vector<T> &arr, int size){
    throw "Counting sort is only for integer numbers!";
}

template<typename T>
void heapify(std::vector<T>& arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * (i + 1);
    if (arr[largest] < arr[left] && left < size)
    {
        largest = left;
    }
    if (arr[largest] < arr[right] && right < size)
    {
        largest = right;
    }
    if (i != largest)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

template<typename T>
void heap_sort(std::vector<T> arr, int size)
{
    int temp = size / 2 - 1;
    for (int i = temp; i >= 0; --i)
    {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i >= 0; --i)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

template<typename T>
void shell_sort(std::vector<T>& arr, int size)
{
    int temp = size / 2;
    for (int i = temp; i > 0; i /= 2)
    {
        for (int j = i; j < size; ++j)
        {
            int k = j;
            while (k > i - 1 && arr[k] < arr[k - i])
            {
                std::swap(arr[k], arr[k - i]);
                k -= i;
            }
        }
    }
}