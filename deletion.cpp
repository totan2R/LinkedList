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

void delAthead(Node *&head)
{
    if (head != NULL)
    {
        Node *test = head;
        head = test->next;
    }
}

void delAttail(Node *&head)
{
    if (head != NULL && head->next != NULL)
    {
        Node *test = head;
        while (test->next->next != NULL)
        {
            test = test->next;
        }
        delete test->next->next;
        test->next = NULL;
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

void delAtpos(int pos, Node *&head)
{
    //if(head!= NULL && pos<= length);
    Node *temp = head;
    for(int i = 1; i<pos-1; i++)
    {
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
}

int main()
{
    Node *head = NULL;
    insert2tail(2, head);
    insert2tail(3, head);
    insert2tail(5, head);
    insert2tail(9, head);
    insert2tail(0, head);
    insert2tail(6, head);
    display(head);
    delAthead(head);
    display(head);
    delAttail(head);
    display(head);
    delAtpos(3, head);
    display(head);
}