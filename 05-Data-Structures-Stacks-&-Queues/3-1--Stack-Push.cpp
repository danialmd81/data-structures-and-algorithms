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

class Stack
{
private:
    Node *top;
    int height;

public:
    Stack(int value)
    {
        Node *newNode = new Node(value);
        top = newNode;
        height = 1;
    }

    ~Stack()
    {
        Node *temp = top;
        while (top)
        {
            top = top->next;
            delete temp;
            temp = top;
        }
    }

    void printStack()
    {
        Node *temp = top;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getTop()
    {
        if (top == nullptr)
        {
            cout << "Top: nullptr" << endl;
        }
        else
        {
            cout << "Top: " << top->value << endl;
        }
    }

    void getHeight()
    {
        cout << "Height: " << height << endl;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }
};

int main()
{

    Stack *myStack = new Stack(2);

    cout << "Stack before push(1):\n";
    cout << "---------------------\n";
    myStack->printStack();
    cout << endl;

    myStack->getTop();
    myStack->getHeight();

    myStack->push(1);

    cout << "\n\nStack after push(1):\n";
    cout << "--------------------\n";
    myStack->printStack();
    cout << endl;

    myStack->getTop();
    myStack->getHeight();

    /*
        EXPECTED OUTPUT:

        Stack before push(1):
        --------------------
        2

        Top: 2
        Height: 1


        LL after prepend(1):
        --------------------
        1
        2

        Top: 1
        Height: 2

    */
}
