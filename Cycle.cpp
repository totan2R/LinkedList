#include <iostream>
using namespace std;

// Floyed's Cycle Detection Algorithm

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

void makeCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *startCycle;

    int count = 1;

    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startCycle = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startCycle;
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

void CycleRemoval(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast!= slow);


    fast = head;
    while (fast->next != slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
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
    makeCycle(head, 4);
    cout << detectCycle(head) << endl;

    CycleRemoval(head);
    cout << detectCycle(head) << endl;
}