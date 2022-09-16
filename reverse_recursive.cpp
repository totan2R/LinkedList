#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insert2tail(int value, Node *&head)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *recursive(Node *head)
{
    if (head->next == NULL)
        return head; //2. 2nd recursion: head->data = 50;

    //1. 3th recursion take last element of the linkedlist
    Node *newHead = recursive(head->next); // newhead->data = 100;

    head->next->next = head; //2. 2nd recursion: reverse link
    head->next = NULL;

    return newHead; // every recursion it will return newhead->data = 100;
}

int main()
{
    Node *head = NULL;

    insert2tail(10, head);
    insert2tail(20, head);
    insert2tail(50, head);
    insert2tail(100, head);

    display(head);
    head = recursive(head);
    display(head);
}