#include <iostream>
#include <math.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&head, int data)
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

void insertAtHead(Node *&head, int data) // https://stackoverflow.com/questions/20846904/in-c-what-is-this-for-node-head
{
    Node *newNode = new Node(data); // create new node
    newNode->next = head;           // point to head
    head = newNode;                 // change newNode to head
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

int length(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}

int string2digit(string str)
{
    int number = 0;
    int len = str.length();

    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (i < len - 1)
            {
                number += (str[i] - '0') * pow(10, len - 1 - i);
            }
            else
            {
                number += (str[i] - '0');
            }
        }
        else
        {
            return -1;
        }
    }
    return number;
}

int main()
{
    Node *head = NULL;
    string str = "";
    cout << "Enter (e) then Enter to exit\n";
    while (true)
    {
        cin >> str;
        int num = string2digit(str);
        if (num == -1)
        {
            break;
        }
        else
        {
            insertAtTail(head, num);
        }
    }

    // insertAtHead(head, 100);
    display(head);

    cout << "length of linked list: " << length(head) << endl;
}