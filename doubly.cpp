#include <iostream>
using namespace std;

class Dnode
{
public:
    int data;
    Dnode *prev;
    Dnode *next;

    Dnode(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

void insertAtTail(Dnode *&head, int data)
{
    Dnode *newNode = new Dnode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Dnode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtHead(Dnode *&head, int data)
{
    Dnode *newNode = new Dnode(data);
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void display(Dnode *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void reverseDisplay(Dnode *head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }

    // backtrucking
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->prev;
    }
    cout<<endl;
}

int main()
{
    Dnode *head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 5);
    insertAtTail(head, 3);

    insertAtTail(head, 8);
    insertAtTail(head, 100);
    display(head);

    reverseDisplay(head);
}