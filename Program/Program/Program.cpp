#include <iostream>

using namespace std;

template <typename T>

class CirclLinkedList
{

private:
	int size;

public:
	struct Node
	{
		T data;
		Node * next;
	};

	Node * head;

    CirclLinkedList()
	{
		size = 0;
		head = nullptr;
	}


    void PushBack(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;

            newNode->next = head;
        }
        else
        {
            newNode->next = head->next;

            head->next = newNode;

            head = newNode;

            //Node* temp = head;
            //while (temp->next != head)
            //{
            //    temp = temp->next;
            //}
            //temp->next = newNode;
            //newNode->next = head;
        }

        size++;
    }

    void PushFront(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;

            head->next = head;  
        }
        else
        {
            newNode->next = head->next;

            head->next = newNode;
        }

        size++;
    }

    void PopFront()
    {
        if (head == nullptr)
        {
            cout << "Circle Linked List is empty" << endl;
        }

        Node* deleteNode = head->next;

        if (head == deleteNode)
        {
            head = nullptr;
        }
        else
        {
            head->next = deleteNode->next;
        }
        delete deleteNode;

        size--;
    }

    void PopBack()
    {
        // if (head == nullptr)
        // {
        //     cout << "Circle Linked List is empty" << endl;
        // }
        // else
        // {
        //     Node* currentNode = head;
        //     Node* deleteNode = head;
        // 
        //     if (head == head->next)
        //     {
        //         head = nullptr;
        //     }
        //     else
        //     {
        //         for (int i = 0; i < size - 1; i++)
        //         {
        //             currentNode = currentNode->data;
        //         }
        // 
        //     }
        // }

        if (head == nullptr)
        {
            cout << "Circle Linked List is empty" << endl;
        }

        Node* currentNode = head->next;
        Node* previousNode = head;
        
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            while (currentNode->next != head->next)
            {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
            previousNode->next = head->next;
            head = previousNode;
            delete currentNode;
        }
         delete currentNode;
         size--;
    }

    void Show()
    {
        if (head != nullptr)
        {
            Node* currentNode = head->next;
            for (int i = 0; i < size; i++)
            {
                cout << currentNode->data << endl;
                currentNode = currentNode->next;
            }

        }

        //if (head == nullptr)
        //{
        //    return;
        //}

        // Node* currentNode = head;
        // do
        // {
        //     cout << currentNode->data << endl;
        //     currentNode = currentNode->next;
        // } while (currentNode != head);
    }

    int& Size()
    {
        return size;
    }
};


int main()
{
    CirclLinkedList<int> circleLinkedList;

    // circleLinkedList.PushFront(50);

    circleLinkedList.PushBack(10);
    circleLinkedList.PushBack(20);
    circleLinkedList.PushBack(30);

    circleLinkedList.PushFront(50);

    circleLinkedList.PopFront();
    circleLinkedList.PopBack();

    circleLinkedList.Show();

	return 0;
}