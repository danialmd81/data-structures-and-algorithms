#include <iostream>

using namespace std;

void printItems(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << endl;
    }

    for (int j = 0; j < n; j++)
    {
        cout << j << endl;
    }
}

int main()
{

    printItems(10);
}
