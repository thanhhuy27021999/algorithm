#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "string.h"
using namespace std;

/* declaration template class */
template<class T>
class ADT
{
private:
    T *A;
    int size;
    int length;
public:
    ADT(int size);
    ~ADT();
    void Insert(int index, T x);
    void Display();
    const int GetSize();
    const int GetLength();
    void Append(T x);
    void Delete(int index);
    int LinearSearch(T key);
    int BinarySearch(T key);
    int RBinarySearch(int left, int right, T key);
    T Get(int index);
    int Set(int index, T x);
    T Sum();
    T RSum(int n);
    T Max();
    void Reverse();
    int Shift_left(int n);
    void Rotate_left(int n);
    int Shift_right(int n);
    int IsSorted();
    void InsertSorted(T x);
    ADT<T>* MergeSort(ADT<T>* arr);
};

/* definition of template class*/
template<class T>
ADT<T>::ADT(int size)
{
    A = new T(size);
    this->size = size;
    this->length = 0;
}
template<class T>
ADT<T>::~ADT()
{
    delete []A;
}
template<class T>
void ADT<T>::Insert(int index, T x)
{
    if(index>=0 && index<=length)
    {
        for(int i=length-1;i>=index;i--)
        A[i+1] = A[i];
        A[index] = x;
        length++;
    }
    else
        std::cout <<"index is not right \n";
}
template<class T>
void ADT<T>::Display()
{
    for(int i=0;i<length;i++)
    {
        std::cout <<A[i]<<" ";
    }
    std::cout << "\n";
}
template<class T>
const int ADT<T>::GetSize()
{
    return this->size;
}
template<class T>
const int ADT<T>::GetLength()
{
    return this->length;
}
template<class T>
void ADT<T>::Append(T x)
{
    A[length] = x;
    length ++;
}
template<class T>
void ADT<T>::Delete(int index)
{
    if(index>=0 && index<=length-1)
    {
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        A[length - 1] = 0;
        length --;
    }
    else std::cout << "Index must be less than length \n";
}
template<class T>
int ADT<T>::LinearSearch(T key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            return i;
        }
    }
    return -1; /* Search not success */
}
template<class T>
int ADT<T>::BinarySearch(T key)
{
    int left = 0, right = length - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right)/2;
        if (A[mid] == key)
        {
            return mid;
        }
        else if (key < mid)
        {
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return -1;
}
template<class T>
int ADT<T>::RBinarySearch(int left, int right, T key)
{
    int mid;
    if(left <= right)
    {
        mid = (left + right)/2;
        if (A[mid] == key)
        {
            return mid;
        }
        else if (A[mid] < key)
        {
            RBinarySearch(mid + 1, right, key);
        }
        else RBinarySearch(left, mid - 1, key);
    }
    else return -1;
}
template<class T>
T ADT<T>::Get(int index)
{
    if(index >= 0 && index <= length - 1)
    {
        return A[index];
    }
    return -1;
}
template<class T>
int ADT<T>::Set(int index, T x)
{
    if (index >= 0 && index <= length - 1)
    {
        A[index] = x;
        return 1;
    }
    return -1;
}
template<class T>
T ADT<T>::Sum()
{
    int sum = 0;
    for (int  i = 0; i < length; i++)
    {
        sum = sum + A[i];
    }
    return sum;
}
template<class T>
T ADT<T>::RSum(int n)
{
    if (n == 0)
    {
        return A[0];
    }
    return RSum(n -1) + A[n];
}
template<class T>
T ADT<T>::Max()
{
    T max = 0;
    for (int i = 0; i < length; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}
template<class T>
void ADT<T>::Reverse()
{
    T temp;
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        temp = A[j];
        A[j] = A[i];
        A[i] = temp;
    }
}
template<class T>
int ADT<T>::Shift_left(int n)
{
    if(n > length)
    {
        std::cout << "Number of shift is more than length \n";
        return -1;
    }
    else
    {
        while(n > 0)
        {
            for(int i = 0;i < length - 1; i++)
            {
                A[i] = A[i+1];
            }
            A[length-1] = 0;
            n--;
        }
        return true;
    }
}
template<class T>
void ADT<T>::Rotate_left(int n)
{
    T temp = 0;
    while(n > 0)
    {
        temp = A[0];
        for(int i = 0;i < length - 1; i++)
        {
            A[i] = A[i+1];
        }
        A[length-1] = temp;
        n--;
    }
}
template<class T>
int ADT<T>::IsSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if(A[i] > A[i+1])
            return false;
    }
    return true;
}
template<class T>
void ADT<T>::InsertSorted(T x)
{
    int i = length - 1;
    if (length == size)
    {
        std::cout << "array has already been full \n ";
    }
    else
    {
        while (i >= 0 && A[i] > x)
        {
            A[i++] = A[i];
            i--;
        }
        A[i+1] = x;
        length++;   
    }
}
template<class T>
ADT<T>* ADT<T>::MergeSort(ADT<T>* arr)
{
    ADT<T>* arr2 = new ADT<T>(length + arr->length);
    int i = 0, j = 0, k = 0;
    while (i <= length - 1 && j <= arr->length - 1)
    {
        if (A[i] <= arr->A[j])
        {
            arr2->A[k++] = A[i++];
        }
        else
            arr2->A[k++] = A[j++];
    }
    for (; i <= length - 1; i++)
    {
        arr2.A[k] = A[i];
    }
    for (; j <= arr->length - 1; j++)
    {
        arr2->A[k] = arr->A[j];
    }
    arr2->length = length + arr->length;
    return arr2;
}
