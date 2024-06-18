#include <iostream>

using namespace std;

#define SIZE 5

template <typename T>
class CircleQueue
{
private:

    int rear;
    int front;
    int size;

    T container[SIZE];

public:
    CircleQueue()
    {
        size = 0;
        rear = 0;
        front = 0;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }

};

int main()
{


    return 0;
}