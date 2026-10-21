
#include <iostream>
using namespace std;

int main() {
    int hash[10];
    int n, x;

    for (int i = 0; i < 10; i++)
        hash[i] = -1;

    cout << "Enter number of student IDs (max 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter student ID: ";
        cin >> x;

        int h1 = x % 10;
        int h2 = 7 - (x % 7);
        int j = 0;

        while (j < 10) {
            int index = (h1 + j * h2) % 10;

            if (hash[index] == -1) {
                hash[index] = x;
                break;
            }

            j++;
        }

        if (j == 10)
            cout << "Hash table is full or no slot found!\n";
    }

    cout << "\nHash table:\n";
    for (int i = 0; i < 10; i++)
        cout << i << " : " << hash[i] << endl;

    return 0;
}
