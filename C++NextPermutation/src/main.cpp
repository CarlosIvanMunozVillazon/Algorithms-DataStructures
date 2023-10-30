#include <bits/stdc++.h>

using namespace std;

vector<int> nextPermutation(vector<int> v);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> test;

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);

    for (auto x : test)
    {
        cout << x << " ";
    }

    cout << "\n";
    vector<int> testPerm = test;
    for (int i = 0; i < 119; i++)
    {
        testPerm = nextPermutation(testPerm);
        for (auto x : testPerm)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}

vector<int> nextPermutation(vector<int> v)
{
    int sizeVector = v.size();
    vector<int> returnVector = v;
    int j = sizeVector - 2; // start at the penultimate element of the array.

    // find the last pair of elements for which a[j] < a[j+1]
    // not greater than or equal because we assume every element is different.
    while (returnVector[j] > returnVector[j + 1])
    {
        j--;
    }

    // find the least value to the right of the j position which is greater than the element it its position
    // considering that to the right hand side im always going to maintain the array sorted in ascending form
    // basta con encontrar el primer valor que es mayor que a[j]
    int k = sizeVector - 1;
    while (returnVector[j] > returnVector[k])
    {
        k--;
    }

    // Swap the least element greater than v[j]
    int value = returnVector[k];
    returnVector[k] = returnVector[j];
    returnVector[j] = value;

    // Reorder everything on the right in ascending order
    for (int i = j + 1; j < sizeVector; j++)
    {
        for (int r = i; r < sizeVector - 1; r++)
        {
            if (returnVector[r] > returnVector[r + 1])
            {
                value = returnVector[r];
                returnVector[r] = returnVector[r + 1];
                returnVector[r + 1] = value;
            }
        }
    }

    return returnVector;
}