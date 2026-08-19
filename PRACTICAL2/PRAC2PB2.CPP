#include <iostream>
using namespace std;

// Recursive Binary Search
void recursiveSearch(int A[], int start, int end, int x)
{
    if (start > end)
    {
        cout << "Recursive Search: Book is not in the catalog."
             << endl;
        return;
    }

    int mid = (start + end) / 2;

    if (A[mid] == x)
    {
        cout << "Recursive Search: Book found at position "
             << mid + 1 << endl;
        return;
    }

    if (x < A[mid])
    {
        recursiveSearch(A, start, mid - 1, x);
    }
    else
    {
        recursiveSearch(A, mid + 1, end, x);
    }
}

// Iterative Binary Search
void iterativeSearch(int A[], int n, int x)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (A[mid] == x)
        {
            cout << "Iterative Search: Book found at position "
                 << mid + 1 << endl;
            return;
        }

        if (x < A[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << "Iterative Search: Book is not in the catalog."
         << endl;
}

int main()
{
    int book[] = {2, 4, 5, 7, 9, 15, 45, 55, 62, 71};
    int target = 45;

    int n = sizeof(book) / sizeof(book[0]);

    // Iterative approach
    iterativeSearch(book, n, target);

    // Recursive approach
    recursiveSearch(book, 0, n - 1, target);

    return 0;
}