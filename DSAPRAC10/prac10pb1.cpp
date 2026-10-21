
#include <iostream>
using namespace std;

int main() {
    int hash[10];
    int n, x;

    for (int i = 0; i < 10; i++)
        hash[i] = -1;

    cout << "Enter number of vehicles (max 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter registration number: ";
        cin >> x;

        int index = x % 10;
        int start = index;

        while (hash[index] != -1) {
            index = (index + 1) % 10;

            if (index == start) {
                cout << "Parking lot is full!\n";
                break;
            }
        }

        if (hash[index] == -1)
            hash[index] = x;
    }

    cout << "\nParking slots:\n";
    for (int i = 0; i < 10; i++)
        cout << i << " : " << hash[i] << endl;

    return 0;
}
