#include <iostream>
using namespace std;

int main()
{
    int book[] = {1, 2, 3, 1, 3, 56, 88, 456, 44, 8,8};
    int n = sizeof(book) / sizeof(book[0]);

    cout << "Books borrowed more than once: ";

    for (int i = 0; i < n; i++)
    {
        bool alreadyChecked = false;

        // Check if this book was already processed
        for (int j = 0; j < i; j++)
        {
            if (book[i] == book[j])
            {
                alreadyChecked = true;
                break;
            }
        }

        if (alreadyChecked)
            continue;

        int count = 0;

        // Count occurrences of the current book
        for (int j = 0; j < n; j++)
        {
            if (book[i] == book[j])
                count++;
        }

        if (count > 1)
            cout << book[i] << " ";
    }

    return 0;
}