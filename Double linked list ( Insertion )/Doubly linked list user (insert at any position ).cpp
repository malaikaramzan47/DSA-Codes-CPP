#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void insertAtStart(Node *&head, int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->prev = nullptr;
    temp->next = head;
    if (head != nullptr)
    {
        head->prev = temp;
    }
    head = temp;
}

void insertAtPosition(Node *&head)
{
    int pos , value;
    cout << "Enter position to insert: ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> value;
    Node *temp = new Node();
    temp->data = value;
    temp->prev = nullptr;
    temp->next = nullptr;
    if (pos == 1)
    {
        temp->next = head;
        if (head != nullptr)
            head->prev = temp;
        head = temp;
        return;
    }
    Node *current = head;
    int count = 1;
    while (current != nullptr && count < pos - 1)
    {
        current = current->next;
        count++;
    }
    temp->next = current->next;
    if (current->next != nullptr)
    {
        current->next->prev = temp;
    }
    current->next = temp;
    temp->prev = current;
}

void createList(Node *&head)
{
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        insertAtStart(head, value);
    }
}

void display(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data <<endl;
        head = head->next;
    }
}

int main()
{
    Node *head = nullptr;
    createList(head);
    cout << "Original Doubly Linked List "<<endl;
    display(head);
    cout<<endl;
    insertAtPosition(head);
    cout << "Doubly Linked List "<<endl;
    display(head);

    return 0;
}
