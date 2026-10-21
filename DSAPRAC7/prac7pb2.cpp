#include <iostream>
using namespace std;

class Queue {
    struct Node {
        string patient;
        Node* next;

        Node(string p) {
            patient = p;
            next = NULL;
        }
    };

    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void arrive(string patient) {
        Node* newNode = new Node(patient);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Front patient: " << front->patient << endl;
    }

    void attend() {
        if (front == NULL) {
            cout << "Error: No patients waiting" << endl;
            return;
        }

        cout << "Attended patient: " << front->patient << endl;

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == NULL)
            rear = NULL;

        if (front != NULL)
            cout << "Front patient: " << front->patient << endl;
        else
            cout << "Front patient: None" << endl;
    }
};

int main() {
    Queue q;

    q.arrive("Patient A");
    q.arrive("Patient B");
    q.arrive("Patient C");

    q.attend();
    q.arrive("Patient D");
    q.attend();
    q.attend();
    q.attend();
    q.attend();

    return 0;
}