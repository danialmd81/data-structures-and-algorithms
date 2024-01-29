#include <iostream>

using namespace std;

// CREATE NODE CLASS HERE //
class Node
{
public:
    string key;
    int value;
    Node *next;
    Node(int value, string key)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable
{
private:
    // CREATE MEMBER VARIABLES HERE //
    static const int Size = 10;
    Node *dataMap[Size];

public:
    // ---------------------------------------------------
    //  Destructor code is similar to keys() function
    //  Watch that video to help understand how this works
    // ---------------------------------------------------
    ~HashTable()
    {
        for (int i = 0; i < Size; i++)
        {
            Node *head = dataMap[i];
            Node *temp = head;
            while (head)
            {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    }

    void printTable()
    {
        for (int i = 0; i < Size; i++)
        {
            cout << i << ":" << endl;
            if (dataMap[i])
            {
                Node *temp = dataMap[i];
                while (temp)
                {
                    cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                    temp = temp->next;
                }
            }
        }
    }
};

int main()
{

    HashTable *myHashTable = new HashTable();

    cout << "Hash Table: \n";
    myHashTable->printTable();

    /*
        EXPECTED OUTPUT:
        ----------------
        Hash Table:
        0:
        1:
        2:
        3:
        4:
        5:
        6:
        7:
        8:
        9:

    */
}
