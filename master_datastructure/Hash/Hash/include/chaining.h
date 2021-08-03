#include <stdio.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* previous;
};

class HashChaining 
{
    private:
        Node* H[10];
        int HashFunction(int key)
        {
            return(key%10);
        }
    public:
        HashChaining()
        {
            for (int i=0; i<10; i++)
                H[i] = NULL;
        }
        Node* NewNode(int key);
        Node* Search(int key);
        void inSearch(int key);
};