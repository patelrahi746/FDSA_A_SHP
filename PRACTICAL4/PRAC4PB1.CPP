#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;
void front(int x)
{
    Node *n = new Node;
    n->data = x;
    n->next = head;
    head = n;
}
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

void display()
{
    Node *p = head;
   while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    front(10);
    display();

    end(20);
    display();

    end(30);
    display();

    pos(15, 2);
    display();

    return 0;
}