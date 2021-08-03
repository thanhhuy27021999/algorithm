#include <iostream>
using namespace std;
void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(int A[], int n)
{
    int flag = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (A[j] > A[j+1])
            {
                Swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
}
void SelectSort(int A[],int n)
{
    int j, k, i;
    for ( i = 0; i < n-1; i++)
    {
        for (j=k=i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        Swap(&A[i], &A[k]);
    }
}
void InsertSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i-1;
        int x = A[i];
        while (A[j] < x && j > -1)
        {
            Swap(&A[j], &A[j+1]);
            j--;
        }
        A[j+1] = x;
    }
}
int main()
{
    int A[] = {7, 6, 4, 3, 4, 5, 8, 9, 10}, n=9;
    //BubbleSort(A,n);
    //SelectSort(A,n);
    InsertSort(A,n);
    for(int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << endl;
}