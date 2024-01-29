#include <iostream>

using namespace std;

void merge(int array[], int left, int mid, int right)
{
    int left_array_size = mid - left + 1;
    int right_array_size = right - mid;

    int left_array[left_array_size];
    int right_array[right_array_size];

    for (int i = 0; i < left_array_size; i++)
    {
        left_array[i] = array[left + i];
    }

    for (int j = 0; j < right_array_size; j++)
    {
        right_array[j] = array[mid + 1 + j]; // keep an eye on +1.
    }

    int i = 0, j = 0, index = left;
    while (i < left_array_size && j < right_array_size)
    {
        if (left_array[i] <= right_array[j])
        {
            array[index] = left_array[i];
            index++;
            i++;
        }
        else
        {
            array[index] = right_array[j];
            index++;
            j++;
        }
    }
    while (i < left_array_size)
    {
        array[index] = left_array[i];
        index++;
        i++;
    }
    while (j < right_array_size)
    {
        array[index] = right_array[j];
        index++;
        j++;
    }
}

int main()
{

    int myArray[] = {1, 3, 7, 8, 2, 4, 5, 6};

    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;
    int midIndex = (size / 2) - 1;

    merge(myArray, leftIndex, midIndex, rightIndex);

    for (auto value : myArray)
    {
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 7 8

     */
}
