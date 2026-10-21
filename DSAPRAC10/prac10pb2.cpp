
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> hash[10];
    int n, x;

    cout << "Enter number of book codes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter book code: ";
        cin >> x;

        int index = x % 10;
        hash[index].push_back(x);
    }

    cout << "\nShelf contents:\n";
    for (int i = 0; i < 10; i++) {
        cout << i << " : ";
        for (int x : hash[i])
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
