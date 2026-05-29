#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node*top = NULL;

bool isEmpty()
{
    return top == NULL;
}
void push(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout<<value<<" pushed into stack."<<endl;
}
int pop()
{
    if(isEmpty())
    {
        cout<<"Stack is Empty! cannot pop."<<endl;
        return -1;
    }
    int poppedValue = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return poppedValue;
}
int peek()
{
    if(isEmpty())
    {
        cout<<"Stack is Empty! No top element."<<endl;
        return -1;
    }
    return top->data;
}

int main()
{
    push(10);
    push(20);
    push(30);
    cout<<"Top Element: "<<peek()<<endl;
    cout<<"Popped: "<<pop()<<endl;
    cout<<"Popped: "<<pop()<<endl;

    return 0;
}
