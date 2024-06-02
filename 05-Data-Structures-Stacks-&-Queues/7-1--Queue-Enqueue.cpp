#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *first;
    Node *last;
    int length;

public:
    Queue(int value)
    {
        Node *newNode = new Node(value);
        first = newNode;
        last = newNode;
        length = 1;
    }

    ~Queue()
    {
        Node *temp = first;
        while (first)
        {
            first = first->next;
            delete temp;
            temp = first;
        }
    }

    void printQueue()
    {
        Node *temp = first;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getFirst()
    {
        if (first == nullptr)
        {
            cout << "First: nullptr" << endl;
        }
        else
        {
            cout << "First: " << first->value << endl;
        }
    }

    void getLast()
    {
        if (last == nullptr)
        {
            cout << "Last: nullptr" << endl;
        }
        else
        {
            cout << "Last: " << last->value << endl;
        }
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    bool isEmpty()
    {
        if (length == 0)
            return true;
        return false;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }
};

int main()
{

    Queue *myQueue = new Queue(1);

    cout << "Queue before enqueue(2):\n";
    cout << "------------------------\n";
    myQueue->printQueue();
    cout << endl;

    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLength();

    myQueue->enqueue(2);

    cout << "\n\nQueue after enqueue(2):\n";
    cout << "-----------------------\n";
    myQueue->printQueue();
    cout << endl;

    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLength();

    /*
        EXPECTED OUTPUT:

        Queue before enqueue(2):
        ------------------------
        1

        First: 1
        Last: 1
        Length: 1


        Queue after enqueue(2):
        -----------------------
        1
        2

        First: 1
        Last: 2
        Length: 2

    */
}
