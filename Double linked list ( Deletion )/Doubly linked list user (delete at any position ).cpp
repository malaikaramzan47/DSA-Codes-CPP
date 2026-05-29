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

void deleteAtPosition(Node *&head)
{
    int pos;
    cout << "Enter the position to delete: ";
    cin >> pos;
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;

        delete temp;
        return;
    }
    Node *current = head;
    int count = 1;
    while (current != nullptr && count < pos)
    {
        current = current->next;
        count++;
    }
    current->prev->next = current->next;
    if (current->next != nullptr)
    {
        current->next->prev = current->prev;
    }
    delete current;
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
    cout << "Original Doubly Linked List" << endl;
    display(head);
    cout<<endl;
    deleteAtPosition(head);
    cout << "Doubly Linked List "<<endl;;
    display(head);

    return 0;
}
