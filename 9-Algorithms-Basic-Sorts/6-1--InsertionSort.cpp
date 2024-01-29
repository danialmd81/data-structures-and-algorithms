#include <iostream>

using namespace std;

void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        for (int j = i - 1; j > -1 && temp < array[j]; j--) // j>-1 should come sooner than other conditions beacause when other condition execute it will make error
        {
            array[j + 1] = array[j];
            array[j] = temp;
        }
    }
}

int main()
{

    int myArray[] = {6, 4, 2, 5, 1, 3};

    int size = sizeof(myArray) / sizeof(myArray[0]);

    insertionSort(myArray, size);

    for (auto value : myArray)
    {
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6

     */
}
