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

    vector<int> testPerm = nextPermutation(test);

    for (auto x : testPerm)
    {
        cout << x << " ";
    }

    cout << "\n";

    vector<int> testPerm2 = nextPermutation(testPerm);

    for (auto x : testPerm2)
    {
        cout << x << " ";
    }

    cout << "\n";
    return 0;
}

vector<int> nextPermutation(vector<int> v)
{
    int sizeVector = v.size();
    vector<int> returnVector = v;
    int j = sizeVector - 2; // start at the penultimate element of the array.

    // encontrar el ultimo par de elementos que aj < aj+1
    while (returnVector[j] > returnVector[j + 1]) // no mayor o igual pq ausmimos que todos los elementos son diferentes
    {
        j--;
    }

    // buscar el menor valor a la derecha de la posición j que es mayor que el elemento en su posicion
    int k = j + 1;
    // considerando que al lado derecho siempre voy a mantener el arreglo ordenado de forma creciente
    // basta con encontrar el primer valor que es mayor que a[j]
    while (returnVector[j] > returnVector[k])
    {
        k++;
    }

    // Intercambio el menor elemento mayor que a[j]
    int value = returnVector[k];
    returnVector[k] = returnVector[j];
    returnVector[j] = value;

    // Se reordena todo a la derecha en orden creciente
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