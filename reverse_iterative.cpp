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

void insertTail(int value, Node *&head)
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

void reverse_iterative(Node *&head)
{
    Node *cur = head;
    Node *pre = NULL;
    while (cur != NULL)
    {
        Node *nxt = cur->next; // keep next
        cur->next = pre; // reverse link

        pre = cur; // update
        cur = nxt; // update
    }
    head = pre;
}

int main()
{
    Node *head = NULL;

    insertTail(20, head);
    insertTail(56, head);
    insertTail(2, head);
    insertTail(4, head);
    insertTail(9, head);

    display(head);

    reverse_iterative(head);
    display(head);
}