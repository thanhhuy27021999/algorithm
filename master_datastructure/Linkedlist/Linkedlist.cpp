#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* pnext;
};
class Linkedlist
{
    private:
        Node* Head;
        Node* Tail;
    public:
        Node* New(int x);
        Node* Create();
        Node* Inseart(int x, int index);
        Node* Inseartlast(int x);
        void  Display();
        Node* GetInter() const
        {
            return this->Head;
        }
};
Node* Linkedlist::Create()
{
    this->Head = NULL;
    this->Tail = NULL;
    return this->Head;
}
Node* Linkedlist::New(int x)
{
    Node* p = new Node;
    p->data = x;
    p->pnext = NULL;
    return p;
}
Node* Linkedlist::Inseart(int x, int index)
{
    Node* t = this->Head;
    Node* temp = New(x);
    for (int i = 0; i < index - 1; i++)
    {
        t = t->pnext;
    }
    temp->pnext = t->pnext;
    t->pnext = temp;
}
void Linkedlist::Display()
{
    Node* p = this->Head;
    while (p != NULL)
    {
        std::cout << p->data << " ";
        p = p->pnext;
    }
    std::cout << endl;
    
}
Node* Linkedlist::Inseartlast(int x)
{
    if (Head == NULL)
    {
        Head = New(x);
        Tail = Head;
    }
    else
    {
        Node* temp = New(x);
        Tail->pnext = temp;
        Tail = temp;
    }
}
int main()
{
    Linkedlist object1;
    Node* temp = object1.Create();
    for (int  i = 0; i < 10; i++)
    {
        object1.Inseartlast(i);
    }
    object1.Inseart(100, 1);
    object1.Display();
}
