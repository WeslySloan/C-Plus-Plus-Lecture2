﻿#include <iostream>

using namespace std;

template <typename T>
class Single/*<T>*/
{

private:
	int size;

	struct Node 
	{
		T data;
		Node * next;
	};

	Node * head;

public:
	SingleLinkedList()
	{
		size = 0;
		head = nullptr;
	}

	void PushFront(T data)
	{
		if (head == nullptr)
		{
			head = new Node;

			head->data = data;
			head->next = nullptr;
		}
		else 
		{
			Node* newNode = new Node;

			newNode->data = data;
			newNode->next = head;

			head = newNode;
		}
		size++;
	}

	void Show()
	{
		Node* currentNode = heaed;

		while (currentNode != nullptr)
		{
			cout << currentNode->data << endl;

			currentNode = currentNode->next;
		}
	}
};


int main()
{
	// Single<int> single;


	return 0;
}

