#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertAtEnd(Node *&head, int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->next = nullptr;

    if (head == nullptr)
    {
        head = temp;
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = temp;
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
        insertAtEnd(head, value);
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
    cout<<endl;
    cout << "Linked List "<<endl;
    display(head);

    return 0;
}
