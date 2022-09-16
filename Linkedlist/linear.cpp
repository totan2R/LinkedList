#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *next;
};

void display(node *n)
{
    while (n != NULL)
    {
        cout << n->value << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    // create Nodes
    node *head = new node(); // heap/dynamic memory points location to head
    node *second = new node();
    node *third = new node();
    node *fourth = new node();
    node *tail = new node();

    // assign values
    head->value = 1;
    second->value = 2;
    third->value = 3;
    fourth->value = 4;
    tail->value = 5;

    // link with memory address
    head->next = second; //second is reference/memory address and *second means values.
    second->next = third;
    third->next = fourth;
    fourth->next = tail;
    tail->next = NULL;

    // display
    display(head);
}