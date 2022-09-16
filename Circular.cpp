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
        newNode->next = head;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void insert2head(int data, Node *&head)
{
    Node *newNode = new Node(data);
    newNode->next = head;

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = newNode;
    temp->next = newNode;
}

bool detectCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow->next == fast->next)
            return true;
    }
    return false;
}

void deletion2head(Node *&head)
{
    Node *temp = head;
    Node *delNode = head;
    if(temp != NULL)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        delete delNode;
    }
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

void CircularDisplay(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "Linked list is empty!" << endl;
        return;
    }

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
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
    insert2head(333, head);

    // display(head);

    cout << detectCycle(head) << endl;
    deletion2head(head);
    CircularDisplay(head);
}