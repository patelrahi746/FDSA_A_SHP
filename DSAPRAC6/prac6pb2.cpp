#include <iostream>
using namespace std;

struct Node
{
    string page;
    Node* next;
};

class Browser
{
    Node* top;

public:
    Browser()
    {
        top = NULL;
    }

    // Visit a new page
    void visit(string page)
    {
        Node* newNode = new Node;

        newNode->page = page;
        newNode->next = top;

        top = newNode;

        cout << "Visited: " << page << endl;
        cout << "Current page: " << top->page << endl;
    }

    // Go back
    void back()
    {
        if (top == NULL)
        {
            cout << "No page history!" << endl;
            return;
        }

        cout << "Going back from: " << top->page << endl;

        Node* temp = top;
        top = top->next;

        delete temp;

        if (top == NULL)
            cout << "No page history left." << endl;
        else
            cout << "Current page: " << top->page << endl;
    }
};

int main()
{
    Browser b;

    b.visit("Google");
    b.visit("YouTube");
    b.visit("GitHub");

    b.back();
    b.back();
    b.back();

    b.back();   // No history left

    return 0;
}