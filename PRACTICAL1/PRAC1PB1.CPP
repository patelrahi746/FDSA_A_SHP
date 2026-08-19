#include<iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter the number of items: ";
    cin >> n;

    int a[n];

    cout << "Enter the items in the display row: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter the number of hours: ";
    cin >> h;

    // If h is very large, only h % n rotations are needed
    int rotations = h % n;

    // Move the leftmost item to the rightmost position
    for(int j = 0; j < rotations; j++)
    {
        int temp = a[0];

        for(int i = 0; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }

        a[n - 1] = temp;
    }

    cout << "Final display order: ";

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}