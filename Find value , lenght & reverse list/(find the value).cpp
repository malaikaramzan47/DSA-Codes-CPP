#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
void insertAtStart(Node *&head , int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->next = head;
    head = temp;
}
void display(Node *head)
{
    while(head != nullptr)
    {
        cout<<head->data<<endl;
        head = head->next;
    }
}
bool search(Node *head, int key)
{
    while (head != nullptr)
    {
        if (head->data == key)
        {
         return true;
        }
        head = head->next;
    }
    return false;
}

int main()
{
    Node *head = nullptr;
    insertAtStart(head,10);
    insertAtStart(head,20);
    insertAtStart(head,30);
    cout<<"Display linked list"<<endl;
    display(head);
    int value;
    cout << "Enter value to search: ";
    cin >> value;

    if (search(head, value))
    {
      cout << "Value Found";
    }
    else
    {
      cout << "Value Not Found";
    }

    return 0;
}
