#include <iostream>
using namespace std;
// SINGLY CIRCULAR 

struct SNode
{
    string name;
    SNode* next;
};

class SinglyCircular
{
    SNode* head;

public:
    SinglyCircular()
    {
        head = NULL;
    }

    // Insert at end
    void insert(string name)
    {
        SNode* newNode = new SNode;
        newNode->name = name;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        SNode* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    // Delete student
    void remove(string name)
    {
        if (head == NULL)
            return;

        // Only one student
        if (head->name == name && head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        SNode* temp = head;
        SNode* prev = NULL;

        do
        {
            if (temp->name == name)
                break;

            prev = temp;
            temp = temp->next;

        } while (temp != head);

        if (temp == head && temp->name != name)
        {
            cout << "Student not found!" << endl;
            return;
        }

        if (temp == head)
        {
            SNode* last = head;

            while (last->next != head)
            {
                last = last->next;
            }

            head = head->next;
            last->next = head;
            delete temp;
        }
        else
        {
            prev->next = temp->next;
            delete temp;
        }
    }

    // Display circle
    void display()
    {
        if (head == NULL)
        {
            cout << "Circle is empty!" << endl;
            return;
        }

        SNode* temp = head;

        cout << "Singly Circular: ";

        do
        {
            cout << temp->name << " ";
            temp = temp->next;

        } while (temp != head);

        cout << endl;
    }
};


//  DOUBLY CIRCULAR 

struct DNode
{
    string name;
    DNode* prev;
    DNode* next;
};

class DoublyCircular
{
    DNode* head;

public:
    DoublyCircular()
    {
        head = NULL;
    }

    // Insert at end
    void insert(string name)
    {
        DNode* newNode = new DNode;
        newNode->name = name;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        DNode* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }

    // Delete student
    void remove(string name)
    {
        if (head == NULL)
            return;

        DNode* temp = head;

        do
        {
            if (temp->name == name)
                break;

            temp = temp->next;

        } while (temp != head);

        if (temp->name != name)
        {
            cout << "Student not found!" << endl;
            return;
        }

        // Only one student
        if (temp->next == temp)
        {
            delete temp;
            head = NULL;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        if (temp == head)
            head = temp->next;

        delete temp;
    }

    // Display circle
    void display()
    {
        if (head == NULL)
        {
            cout << "Circle is empty!" << endl;
            return;
        }

        DNode* temp = head;

        cout << "Doubly Circular: ";

        do
        {
            cout << temp->name << " ";
            temp = temp->next;

        } while (temp != head);

        cout << endl;
    }
};


//  MAIN 

int main()
{
    SinglyCircular s;

    cout << "SINGLY CIRCULAR LINKED LIST" << endl;

    s.insert("A");
    s.display();

    s.insert("B");
    s.display();

    s.insert("C");
    s.display();

    s.remove("B");
    s.display();

    s.remove("A");
    s.display();


    cout << "\nDOUBLY CIRCULAR LINKED LIST" << endl;

    DoublyCircular d;

    d.insert("A");
    d.display();

    d.insert("B");
    d.display();

    d.insert("C");
    d.display();

    d.remove("B");
    d.display();

    d.remove("A");
    d.display();

    return 0;
}