#include <iostream>

using namespace std;

#define SIZE 5

template <typename T>
class Stack
{
private:
	int top;
	T container[SIZE];

public:
	Stack()
	{
		top = -1;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = 0;
		}
	}

	void Push(T data)
	{
		if (top >= SIZE-1)
		{
			cout << "Stack Overflow" << endl;
		}
		else
		{
			container[++top] = data;
		}
	}

	void Pop()
	{
		if (Empty())
		{
			cout << "Stack is Empty" << endl;
		}
		else
		{
			top--;
		}
	}

	bool Empty()
	{
		if (top <= -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int& Size()
	{
		return top;
	}

	T& Top()
	{
		return container[top];
	}

};

bool CheckBracket(string content)
{
	Stack<char> stack;

	for (char& ch : content)
	{
		if (ch == '(' || ch == '[' || ch == '{')
		{
			stack.Push(ch);
		}
		else if (ch == ')' || ch == ']' || ch == '}')
		{
			if (stack.Empty())
			{
				return false;
			}
			char top = stack.Top();
			stack.Pop();

			if ((ch == ')' && top != '(') ||
				(ch == ']' && top != '[') ||
				(ch == '}' && top != '{'))
			{
				return false;
			}
		}
		//if (content.length() <= 0)
		//{
		//	return false;
		//}
	}

	return stack.Empty();
}


int main()
{
	Stack<int> stack;

	// stack.Push(10);
	// stack.Push(20);
	// stack.Push(30);
	// stack.Push(40);
	// stack.Push(50);

	string test1 = "{[()]}";
	string test2 = "{[(])}";
	string test3 = "{[()()]()}";

	string test4 = "";

	cout << "Test 1 : " << (CheckBracket(test1) ? "True" : "False") << endl;
	cout << "Test 2 : " << (CheckBracket(test2) ? "True" : "False") << endl;
	cout << "Test 3 : " << (CheckBracket(test3) ? "True" : "False") << endl;

	// cout << "Test 4 : " << (CheckBracket(test4) ? "True" : "False") << endl;


	while (stack.Empty() != true)
	{
		cout << stack.Top() << endl;

		stack.Pop();
	}

	return 0;
}


//#include <iostream>
//
//using namespace std;
//
//#define SIZE 5;
//
//template <typename T>
//class Stack
//{
//private:
//	int top;
//	int size;
//
//	T container[SIZE];
//
//public:
//	Stack()
//	{
//		top = -1;
//
//		for (int i = 0; i < SIZE; i++)
//		{
//			container[i] = 0;
//		}
//	}
//
//
//	void Push(T data)
//	{
//		if (top >= SIZE)
//		{
//			cout << "Stack Overflow" << endl;
//		}
//		else
//		{
//			container[++top] = data;
//		}
//
//
//	}
//
//	void Pop()
//	{
//		if (Empty())
//		{
//			cout << "Stack is Empty" << endl;
//		}
//		else
//		{
//			top--;
//		}
//	}
//
//	bool Empty()
//	{
//		if (top <= -1)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	int& Size()
//	{
//		return top;
//	}
//
//	T& Top() // 제일 위(top) 의 값을 반환
//	{
//		return container[top];
//	}
//
//};
//
//
//int main()
//{
//	Stack<int> stack;
//	stack.Push(10);
//	stack.Push(20);
//	stack.Push(30);
//
//	return 0;
//}





