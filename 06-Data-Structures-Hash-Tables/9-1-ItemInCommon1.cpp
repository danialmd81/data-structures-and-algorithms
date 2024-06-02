#include <iostream>
#include <vector>

using namespace std;

bool itemInCommon(vector<int> vect1, vector<int> vect2)
{
    for (auto i : vect1)
    {
        for (auto j : vect2)
        {
            if (i == j)
                return true;
        }
    }
    return false;
}

int main()
{

    vector<int> vect1{1, 3, 5};

    vector<int> vect2{2, 4, 6};

    cout << itemInCommon(vect1, vect2);
}
