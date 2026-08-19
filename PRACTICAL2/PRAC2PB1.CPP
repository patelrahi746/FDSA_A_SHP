#include <iostream>
using namespace std;

// Iterative approach
void iterativeSearch(int A[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == x)
        {
            cout << "Iterative Search: Car found at position "
                 << i + 1 << endl;
            return;
        }
    }

    cout << "Iterative Search: Car is not in the parking lot."
         << endl;
}

// Recursive approach
void recursiveSearch(int A[], int n, int x, int i)
{
    if (i >= n)
    {
        cout << "Recursive Search: Car is not in the parking lot."
             << endl;
        return;
    }

    if (A[i] == x)
    {
        cout << "Recursive Search: Car found at position "
             << i + 1 << endl;
        return;
    }

    recursiveSearch(A, n, x, i + 1);
}

int main()
{
    int A[] = {2, 4, 3, 5, 6, 7, 8, 9};
    int x = 5;

    int n = sizeof(A) / sizeof(A[0]);

    // Iterative search
    iterativeSearch(A, n, x);

    // Recursive search
    recursiveSearch(A, n, x, 0);

    return 0;
}