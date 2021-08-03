#include <stdio.h>
#include <iostream>
#include "chaining.h"
using namespace std;
int main()
{
    int arr[] = {10, 11, 20, 22, 100, 30, 21, 45, 67};
    HashChaining arg1;
    for (int i=0; i<9; i++)
    {
        arg1.inSearch(arr[i]);
    }
    Node* t = arg1.Search(200);
    if (t != NULL)
        std::cout << t->data << endl;
    else
        std::cout << "False \n";

}