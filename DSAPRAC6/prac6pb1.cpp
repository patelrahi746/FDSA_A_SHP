#include <iostream>
using namespace std;

class Stack
{
    int arr[5];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    // Push operation
    void push(int tray)
    {
        if (top == 4)
        {
            cout << "Error: Stack is full!" << endl;
            return;
        }

        top++;
        arr[top] = tray;

        cout << "Tray placed: " << tray << endl;
        cout << "Top tray: " << arr[top] << endl;
    }

    // Pop operation
    void pop()
    {
        if (top == -1)
        {
            cout << "Error: Stack is empty!" << endl;
            return;
        }

        cout << "Tray taken: " << arr[top] << endl;
        top--;

        if (top == -1)
            cout << "Stack is empty" << endl;
        else
            cout << "Top tray: " << arr[top] << endl;
    }
};

int main()
{
    Stack s;

    s.push(101);
    s.push(102);
    s.push(103);

    s.pop();
    s.pop();

    s.pop();

    s.pop();   // Error: empty stack

    return 0;
}