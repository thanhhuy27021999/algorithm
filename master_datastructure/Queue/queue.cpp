#include <iostream>
using namespace std;

class Queue
{
    private:
        int Front;
        int Rear;
        int size;
        int* Q; // space for data
    public:
        Queue(int size);
        Queue();
        void enqueue(int x);
        int Dequeue();
        int GetSize() const
        {
            return size;
        }
        void Display();
        bool isEmpty();
};
Queue::Queue()
{
    this->Front = Rear = 0;
    this->size = 10;
    this->Q = new int[size];
}
Queue::Queue(int size)
{
    this->size = size;
    this->Front = this->Rear = 0;
    this->Q = new int[size];
}
void Queue::enqueue(int x)
{
    if((Rear + 1)%size == Front)
    {
        std::cout << "Queue is full \n";
    }
    else
    {
        Rear = (Rear + 1) % size;
        Q[Rear] = x;
    }
}
int Queue::Dequeue()
{
    if (Rear == Front)
    {
        std::cout << "Queue is empty /n";
        return -1;
    }
    else
    {
        Front = (Front + 1) % size;
        return Q[Front];
    }
}
bool Queue::isEmpty()
{
    if (Rear == Front)
        return true;
    return false;
}
void Queue::Display()
{
//    Front = (Front + 1) % size;
    while(1)
    {
        if (Front == Rear)
        {
            break;
        }
        else
        {
            Front = (Front + 1) % size;
            std::cout << Q[Front] << " ";
        }
    }
    std::cout << endl;
}
int main()
{
    Queue objec1(20);
    for (int i = 0; i < 19; i++)
    {           
        objec1.enqueue(i);
    }
    objec1.Display();
}