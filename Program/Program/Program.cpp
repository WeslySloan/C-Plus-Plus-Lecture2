#include <iostream>

using namespace std;

template <typename T>
class BinarySearchTree
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;

	};

	Node* root;

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    Node* Root()
    {
        return root;
    }

	Node* CreateNode(T data)
	{
		Node* newNode = new Node();
		newNode->data = data;
		newNode->left = nullptr;
		newNode->right = nullptr;

		return newNode;
	}

	void Insert(T data)
	{
		if (root == nullptr)
		{
			root = CreateNode(data);
		}
		else
		{
			Node* currentNode = root;

			while (currentNode != nullptr)
			{
				if (currentNode->data == data)
				{
					return;
				}
				else if (currentNode->data > data)
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = CreateNode(data);
						break;
					}
					else
					{
						currentNode = currentNode->left;
					}
				}
				else
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = CreateNode(data);
						break;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}

			}
		}
	}

	bool Find(T data)
	{
		Node * currentNode = root;

		if (currentNode == nullptr)
		{
			return false;
		}
		else
		{
			if (currentNode->data == data)
			{
				return true;
			}
			else
			{
				if (currentNode->data > data)
				{
					currentNode = currentNode->left;
				}
				else
				{
					currentNode = currentNode->right;
				}
			}
		}
	}

	void Destroy(Node* root)
	{
		if (root != nullptr)
		{
			Destroy(root->left);
			Destroy(root->right);
			delete root;
		}
	}

	~BinarySearchTree()
	{
		Destroy(root);
	}

	void Inorder(Node* root)
	{
		if (root != nullptr)
		{
			Inorder(root->left);
			cout << root->data << " ";
			Inorder(root->right);
		}
	}

    /*void Insert(T data)
    {
        if (root == nullptr)
        {
            root = CreateNode(data);
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr)
        {
            parent = current;
            if (data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        if (data < parent->data)
        {
            parent->left = CreateNode(data);
        }
        else
        {
            parent->right = CreateNode(data);
        }
    }

    void Inorder(Node* root)
    {
        if (root != nullptr)
        {
            Inorder(root->left);
            cout << root->data << " ";
            Inorder(root->right);
        }
    }

    void Inorder()
    {
        Inorder(root);
    }*/
};
int main()
{
    BinarySearchTree<int> binarysearchtree;

    binarysearchtree.Insert(40);
    binarysearchtree.Insert(80);
    binarysearchtree.Insert(70);
    binarysearchtree.Insert(60);
    binarysearchtree.Insert(50);

    binarysearchtree.Insert(20);
    binarysearchtree.Insert(30);

	cout << binarysearchtree.Find(20) << endl;

    binarysearchtree.Inorder(binarysearchtree.Root());


	return 0;
}


