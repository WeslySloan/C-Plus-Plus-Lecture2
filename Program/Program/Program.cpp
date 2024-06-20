
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

class String
{
private:
    int size;
    char * container;


public:
    String()
    {
        size = 0;
        container = nullptr;
    }
    
    void operator = (const char* content)
    {
        int arraySize = strlen(content) + 1;



        if (container == nullptr)
        {
            container = new char[arraySize];

            for (int i = 0; i < arraySize; i++)
            {
                container[i] = content[i];
            }
        }
        else
        {
            char* newContainer = new char[arraySize];

            for (int i = 0; i < arraySize; i++)
            {
                newContainer[i] = content[i];
            }

            delete container;

            container = newContainer;
        }
        size = strlen(container);
    }

    int& Size()
    {
        // int len = strlen(container);
        return size;
    }

    char& operator [] (int index)
    {
        return container[index];
    }

    int Compare(const char * content)
    {
        if (content == container)
        {
            return 0;
        }
        else
        {

        }
    }

};

int main()
{
    // String string;
    // 
    // string = "Janna";
    // 
    // cout << "string의 크기 : " << string.Size() << endl;
    // 
    // string = "Alistar";
    // 
    // for (int i = 0; i < string.Size(); i++)
    // {
    //     cout << string[i] 
    // }

    string name;

    name.compare("qd");

    return 0;
}
