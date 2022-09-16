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
        Node *next = NULL;
    }
};

void insert2tail(int data, Node *&head)
{
    Node *newNode = new Node(data);
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

int main()
{
    Node *head = NULL;

    insert2tail(10, head);
    insert2tail(20, head);
    insert2tail(50, head);
    insert2tail(100, head);
    insert2tail(1, head);
    insert2tail(2, head);
    insert2tail(3, head);

    display(head);
    display(head);
    return 0;
}