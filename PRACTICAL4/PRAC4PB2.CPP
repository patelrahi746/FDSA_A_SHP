#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Insert at front
void front(int x)
{
    Node *n = new Node;
    n->data = x;
    n->next = head;
    head = n;
}

// Insert at end
void end(int x)
{
    Node *n = new Node;
    n->data = x;
    n->next = NULL;

    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *p = head;

    while (p->next != NULL)
        p = p->next;

    p->next = n;
}

// Insert at position
void pos(int x, int k)
{
    if (k <= 1)
    {
        front(x);
        return;
    }

    Node *p = head;

    for (int i = 1; i < k - 1 && p != NULL; i++)
        p = p->next;

    if (p == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node *n = new Node;
    n->data = x;
    n->next = p->next;
    p->next = n;
}

// Delete by value
void del(int x)
{
    if (head == NULL)
        return;

    if (head->data == x)
    {
        Node *p = head;
        head = head->next;
        delete p;
        return;
    }

    Node *p = head;

    while (p->next != NULL && p->next->data != x)
        p = p->next;

    if (p->next != NULL)
    {
        Node *q = p->next;
        p->next = q->next;
        delete q;
    }
}

// Forward traversal
void forward()
{
    Node *p = head;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

// Reverse printing using recursion
void reverse(Node *p)
{
    if (p == NULL)
        return;

    reverse(p->next);
    cout << p->data << " ";
}

int main()
{
    front(10);
    end(20);
    end(30);
    pos(15, 2);

    cout << "Queue: ";
    forward();

    del(20);

    cout << "After deletion: ";
    forward();

    cout << "Reverse: ";
    reverse(head);
    cout << endl;

    cout << "Forward: ";
    forward();

    return 0;
}