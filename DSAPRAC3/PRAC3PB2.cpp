#include <iostream>
using namespace std;
void sortColors(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
     while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
     cout << "Enter elements (only 0, 1, 2): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sortColors(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}