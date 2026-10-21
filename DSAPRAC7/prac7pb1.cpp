#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, size, capacity;

public:
    Queue(int n) {
        capacity = n;
        arr = new int[n];
        front = 0;  
        rear = -1;
        size = 0;
    }
    void join(int token) {
        if (size == capacity) {
            cout << "Error: Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = token;
        size++;

        cout << "Front token: " << arr[front] << endl;
    }

    void serve() {
        if (size == 0) {
            cout << "Error: Queue is empty" << endl;
            return;
        }

        cout << "Served token: " << arr[front] << endl;
        front = (front + 1) % capacity;
        size--;

        if (size > 0)
            cout << "Front token: " << arr[front] << endl;
        else
            cout << "Front token: None" << endl;
    }
};

int main() {
    int n;
    cout << "Enter queue capacity: ";
    cin >> n;
    Queue q(n);
    
    q.join(101);
    q.join(102);
    q.join(103);

    q.serve();
    q.join(104);
    q.serve();
    q.serve();
    q.serve();
    q.serve();

    return 0;
}