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
int getLength(Node *head)
{
    int count = 0;

    while (head != nullptr)
    {
        count++;
        head = head->next;
    }

    return count;
}

int main()
{
    Node *head = nullptr;
    insertAtStart(head,10);
    insertAtStart(head,20);
    insertAtStart(head,30);
    cout<<"Display linked list"<<endl;
    display(head);
    cout << "Length of the list: " << getLength(head);

    return 0;
}

