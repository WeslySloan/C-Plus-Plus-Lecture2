#include <iostream>

#define SIZE 52

using namespace std;

class Trie
{
private:
	bool final;

	Trie * alphabet[SIZE];

public:
	Trie()
	{
		final = false;
		
		for (int i = 0; i < SIZE; i++)
		{
			alphabet[i] = nullptr;
		}
	}

	int checker(char c)
	{
		if (c >= 'A' && c <= 'Z')
		{
			return c - 'A';
		}
		else
		{
			return c - 'a' + 26;
		}
	}

	void Insert(const char * content)
	{
		Trie* node = this;
		for (int i = 0; content[i] != '\0'; i++)
		{
			int index = checker(content[i]);
			if (node->alphabet[index] == nullptr)
			{
				node->alphabet[index] = new Trie();
			}
			node = node->alphabet[index];
		}
		node->final = true; 
	}

	bool Find(const char* content)
	{
		Trie* node = this;

		for (int i = 0; content[i] != '\0'; i++)
		{
			int index = checker(content[i]);

			if (node->alphabet[index] == nullptr)
			{
				return false;
			}

			node = node->alphabet[index];
		}

		return node->final;
	}

	//void Insert(const char* content)
	//{
	//	if (*content == '\0')
	//	{
	//		final = true;
	//	}
	//	else
	//	{
	//		int index = 0;
	//		if (*content >= 'A' && *content <= 'Z')
	//		{
	//			index = *content - 'A';
	//		}
	//		else
	//		{
	//			index = *content - 'a';
	//		}
	//		
	//		if (alphabet[index] == nullptr)
	//		{
	//			alphabet[index] = new Trie();
	//			alphabet[index] -> Insert(content + 1);
	//		}
	//	}
	//}


	~Trie()
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (alphabet[i] == nullptr)
			{
				delete[] alphabet;
			}
		}
	}
};


int main()
{
	Trie trie;

	trie.Insert("APPLE");
	trie.Insert("Hello");

	if (trie.Find("APPLE") == 1)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}



	return 0;
}

