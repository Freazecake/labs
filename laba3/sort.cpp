#pragma once

#include <iostream>
#include "project1_helper.cpp"

void bubble_sort(int *arr, int size)
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

void insert_sort(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j)
        {
            std::swap(arr[j], arr[j - 1]);
        }
    }
}

void selection_sort(int *arr, int size)
{ 
    int mn;
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

int partition(int *arr, int start, int end)
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
void quick_sort(int *arr, int start, int end)
{
    if (end <= start)
    {
        return;
    }
    int x = partition(arr, start, end);
    quick_sort(arr, start, x - 1);
    quick_sort(arr, x + 1, end);
}

void merge_sort(int *arr, int size)
{
    int x = size / 2;
    if (size < 2)
    {
        return;
    }
    int *arr1 = new int[x], *arr2 = new int[size - x];
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
    delete[] arr1;
    delete[] arr2;
}

void counting_sort(int *arr, int size)
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

void heapify(int *arr, int size, int i)
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

void heap_sort(int *arr, int size)
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

void put_in_array(int *arr, int &i, int n)
{
    arr[i] = n;
    ++i;
}
void take_from_array(int *arr, int j, int *a, int size)
{
    for (int i = 0; i < j; ++i)
    {
        arr[size + i] = a[i];
    }
}

void radix_sort(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < 0)
        {
            std::cout << "all elements of the array are not positive\n";
            return;
        }
    }
    int max = 0;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int w = 0;
    while (max > 0)
    {
        ++w;
        max /= 10;
    }
    for (int j = 0; j < w; ++j)
    {
        int *arr0 = new int [size]{}, i0{};
        int *arr1 = new int [size]{}, i1{};
        int *arr2 = new int [size]{}, i2{};
        int *arr3 = new int [size]{}, i3{};
        int *arr4 = new int [size]{}, i4{};
        int *arr5 = new int [size]{}, i5{};
        int *arr6 = new int [size]{}, i6{};
        int *arr7 = new int [size]{}, i7{};
        int *arr8 = new int [size]{}, i8{};
        int *arr9 = new int [size]{}, i9{};
        for (int i = 0; i < size; ++i)
        {
            int pw = pow(10, j);
            switch ((arr[i] % (pw * 10)) / pw)
            {
            case 0:
                put_in_array(arr0, i0, arr[i]);
                break;
            case 1:
                put_in_array(arr1, i1, arr[i]);
                break;
            case 2:
                put_in_array(arr2, i2, arr[i]);
                break;
            case 3:
                put_in_array(arr3, i3, arr[i]);
                break;
            case 4:
                put_in_array(arr4, i4, arr[i]);
                break;
            case 5:
                put_in_array(arr5, i5, arr[i]);
                break;
            case 6:
                put_in_array(arr6, i6, arr[i]);
                break;
            case 7:
                put_in_array(arr7, i7, arr[i]);
                break;
            case 8:
                put_in_array(arr8, i8, arr[i]);
                break;
            case 9:
                put_in_array(arr9, i9, arr[i]);
                break;
            }
        }
        int i = 0;
        take_from_array(arr, i0, arr0, i);
        i += i0;
        take_from_array(arr, i1, arr1, i);
        i += i1;
        take_from_array(arr, i2, arr2, i);
        i += i2;
        take_from_array(arr, i3, arr3, i);
        i += i3;
        take_from_array(arr, i4, arr4, i);
        i += i4;
        take_from_array(arr, i5, arr5, i);
        i += i5;
        take_from_array(arr, i6, arr6, i);
        i += i6;
        take_from_array(arr, i7, arr7, i);
        i += i7;
        take_from_array(arr, i8, arr8, i);
        i += i8;
        take_from_array(arr, i9, arr9, i);
        delete[] arr0;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        delete[] arr5;
        delete[] arr6;
        delete[] arr7;
        delete[] arr8;
        delete[] arr9;
    }
}

void shell_sort(int *arr, int size)
{
    int temp = size / 2;
    for (int i = temp; i > 0; i /= 2)
    {
        for (int j = i; j < size; ++j)
        {
            int k = j;
            while (arr[k] < arr[k - i] && k > i - 1)
            {
                std::swap(arr[k], arr[k - i]);
                k -= i;
            }
        }
    }
}

int get_sort_method()
{
    int status;
    std::cout << "enter a way to sort array:\n\
    1-bubble sort\n\
    2-insert sort\n\
    3-selection sort\n\
    4-quick sort\n\
    5-merge sort\n\
    6-heap sort\n\
    7-radix sort(only for positive)\n\
    8-counting sort(only for numbers from 0 to 99)\n\
    9-shell sort\n";
    std::cout << "your choice: ";
    std::cin >> status;
    return status;
}

void ArraySortMethod(int *arr, int size, bool &IsGoodNumber)
{
    switch (int status = get_sort_method(); status)
    {
    case 1:
        bubble_sort(arr, size);
        break;
    case 2:
        insert_sort(arr, size);
        break;
    case 3:
        selection_sort(arr, size);
        break;
    case 4:
        quick_sort(arr, 0, size - 1);
        break;
    case 5:
        merge_sort(arr, size);
        break;
    case 6:
        heap_sort(arr, size);
        break;
    case 7:
        radix_sort(arr, size);
        break;
    case 8:
        counting_sort(arr, size);
        break;
    case 9:
        shell_sort(arr, size);
        break;
    default:
        std::cout << "you entered wrong number!!!\n";
        IsGoodNumber = 0;
        break;
    }
    if (IsGoodNumber)
    {
        print_array(arr, size);
    }
}

void bubbleSortByFrequency(int *freq, int *value, int j)
{
    for (int i = 0; i < j - 1; ++i)
    {
        for (int k = i + 1; k < j; ++k)
        {
            if (freq[i] < freq[k] || (freq[i] == freq[k] && value[i] > value[k]))
            {
                std::swap(freq[i], freq[k]);
                std::swap(value[i], value[k]);
            }
        }
    }
}

void arrayCompletion(int *freq, int *value, int *arr, int &j, int size)
{
    for (int i = 0; i < size;)
    {
        value[j] = arr[i];
        while (i < size && arr[i] == value[j])
        {
            ++freq[j];
            ++i;
        }
        ++j;
    }
}

void finalSort(int *freq, int *value, int *arr, int j)
{
    int k = 0;
    for (int i = 0; i < j; ++i)
    {
        while (freq[i] != 0)
        {
            arr[k] = value[i];
            --freq[i];
            ++k;
        }
    }
}

int *fs(int *freq, int *value, int *arr, int j)
{
    int k = 0;
    for (int i = 0; i < j; ++i)
    {
        while (freq[i] != 0)
        {
            arr[k] = value[i];
            --freq[i];
            ++k;
        }
    }
    return arr;
}