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

int Search(int value, Node *head)
{
    for (int i = 0; head != NULL; i++)
    {
        if (head->data == value)
        {
            return i;
        }
        head = head->next;
    }
    return -1;
}

struct Test
{
    int position[1000];
};

Test searchByDuplicate(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int k = 1, count = 1;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            T.position[k] = count;
            k++;
        }
        temp = temp->next;
        count++;
    }
    T.position[0] = k;
    return T;
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
    insert2tail(2, head);
    insert2tail(3, head);
    insert2tail(2, head);
    insert2tail(2, head);
    insert2tail(3, head);
    insert2tail(2, head);
    display(head);

    cout << Search(30, head) << endl;

    Test T = searchByDuplicate(head, 2);
    int size = T.position[0];
    for(int i = 1; i<size; i++)
    {
        cout<<T.position[i]<<" ";
    }
    cout<<endl;
}