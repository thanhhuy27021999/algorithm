#include <stdio.h>
#include "chaining.h"
using namespace std;

Node* HashChaining::NewNode(int key)
{
    Node* p = new Node;
    p->data = key;
    p->next = NULL;
    p->previous = NULL;
    return p;
}
void HashChaining::inSearch(int key)
{
    int temp = HashFunction(key);
    Node* p;
    Node* q = NULL;
    Node* t = NewNode(key);
    p = H[temp];
    if (H[temp] == NULL)
    {
        H[temp] = t;
    }
    else
    {
        while(p && p->data <= key)
        {
            q = p;
            p = p->next;
        }
        if (p == H[temp])
        {
            t->next = p;
            H[temp] = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
Node* HashChaining::Search(int key)
{
    int temp = HashFunction(key);
    Node* p = H[temp];
    while (p != NULL)
    {
        if (p->data != key )
        {
            p = p->next;
        }
        else
            return p;
    }
    return NULL;
}