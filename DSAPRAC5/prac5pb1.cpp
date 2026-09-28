#include <iostream>
using namespace std;

struct Node
{
    string song;
    Node* prev;
    Node* next;
};

class Playlist
{
    Node* head;

public:
    Playlist()
    {
        head = NULL;
    }

    // Add song at beginning
    void insertBeginning(string song)
    {
        Node* newNode = new Node;
        newNode->song = song;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
    }

    // Add song at end
    void insertEnd(string song)
    {
        Node* newNode = new Node;
        newNode->song = song;
        newNode->next = NULL;

        if (head == NULL)
        {
            newNode->prev = NULL;
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert after a specific song
    void insertAfter(string givenSong, string newSong)
    {
        Node* temp = head;

        while (temp != NULL && temp->song != givenSong)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Song not found!" << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->song = newSong;

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    // Delete first song
    void deleteFirst()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
    }

    // Count songs
    int countSongs()
    {
        int count = 0;
        Node* temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Display playlist
    void display()
    {
        Node* temp = head;

        cout << "Playlist: ";

        while (temp != NULL)
        {
            cout << temp->song << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Playlist p;

    p.insertBeginning("Song1");
    p.display();

    p.insertEnd("Song2");
    p.display();

    p.insertEnd("Song3");
    p.display();

    p.insertAfter("Song2", "Song4");
    p.display();

    p.deleteFirst();
    p.display();

    cout << "Total songs: " << p.countSongs() << endl;

    p.insertAfter("Song10", "Song5");

    return 0;
}