﻿#include <iostream>

#define SIZE 10

using namespace std;

template <typename T>
class AdjacencyList
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* link = nullptr)
		{
			this->data = data;
			next = link;
		}
	};

	int size; // 정점의 개수
	T vertex[SIZE]; // 정점의 집합
	Node* list[SIZE]; // 인접 리스트
public:
	AdjacencyList()
	{
		size = 0;

		for (int i = 0; i < SIZE; i++)
		{
			list[i] = NULL;
			vertex[i] = NULL;
		}
	}

	void Insert(T data)
	{
		if (size < SIZE)
		{
			vertex[size++] = data;
		}
		else
		{
			cout << "Graph is full!" << endl;
		}
	}

	void Connect(int u, int v)
	{
		if (size <= 0)
		{
			cout << "Adjacency List is Empty" << endl;
		}
		else if (u >= size || v >= size)
		{
			cout << "Index Out of Range" << endl;
		}
		else
		{
			list[u] = new Node(vertex[v], list[u]);
			list[v] = new Node(vertex[u], list[v]);
		}
	}

	void Show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << vertex[i] << " : ";
			Node* current = list[i];
			while (current != nullptr)
			{
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}
	}

	~AdjacencyList()
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (list[i] != nullptr)
			{
				delete list[i];
			}
		}
	}


};
int main()
{
#pragma region 인접 리스트
	// 그래프의 각 정점에 인접한 정점들을 연결 리스트로
	// 표현하는 방법입니다.

	// 장점
	// 그래프의 모든 간선의 수를 O(V + E)로 표현할 수 있습니다

	// 단점
	// 두 장점을 연결하는 간선을 조회하거나 정점의 차수를 알기
	// 위해서 정점의 인접 리스트를 모두 탐색해야 하므로,
	// 정점의 차수만큼의 시간이 필요합니다.

	AdjacencyList<char> adjancencyList;
	adjancencyList.Insert('A');
	adjancencyList.Insert('B');
	adjancencyList.Insert('C');
	adjancencyList.Insert('D');

	adjancencyList.Connect(0, 1);
	adjancencyList.Connect(0, 2);
	adjancencyList.Connect(2, 3);

	adjancencyList.Show();
#pragma endregion

	return 0;
}


