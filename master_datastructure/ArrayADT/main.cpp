#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "string.h"
#include "ADT.h"
using namespace std;
int main()
{
    ADT<float> arr1(10);
    arr1.Insert(0,1.5);
    arr1.Insert(1,2.7);
    arr1.Append(3.6);
    arr1.Append(5);
    arr1.Append(6);
    arr1.Delete(0);
    arr1.Display();
    std::cout << "Size = " << arr1.GetSize() << " Length = " << arr1.GetLength() << "\n";
    std::cout << arr1.LinearSearch(4) << "\n";
    std::cout << arr1.BinarySearch(5) << "\n";
    std::cout << arr1.RBinarySearch(0,arr1.GetLength() - 1,6) << "\n";
    std::cout << arr1.Sum() << "\n";
    std::cout << arr1.RSum(arr1.GetLength() - 1) << "\n";
    std::cout << "Max: " << arr1.Max() << "\n";
    ADT<float> arr2(10);
    arr1.Reverse();
    arr1.Display();
    arr1.Shift_left(6);
    arr1.Display();
    arr1.Rotate_left(3);
    arr1.Display();
    std::cout << "Size = " << arr1.GetSize() << " Length = " << arr1.GetLength() << "\n";
}