#include <iostream>
using namespace std;
#define Size 5
int stackArr[Size];
int top = -1;
bool isEmpty()
{
    return top == -1;
}
bool isFull()
{
    return top == Size-1;
}
void push(int value)
{
    if(isFull())
    {
        cout<<"Stack is full! Cannot push"<<value<<endl;
    }
    else
    {
        top++;
        stackArr[top] = value;
        cout<<value<<" pushed into stack."<<endl;
    }
}
int pop()
{
    if(isEmpty())
    {
        cout<<"Stack is Empty! cannot pop."<<endl;
        return -1;
    }
    else
    {
        int poppedValue = stackArr[top];
        top--;
        return poppedValue;
    }
}
int peek()
{
    if(isEmpty())
    {
        cout<<"Stack is Empty! No top element."<<endl;
        return -1;
    }
    else
    {
        return stackArr[top];
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    cout<<"Top Element: "<<peek()<<endl;
    cout<<"Popped: "<<pop()<<endl;
    cout<<"Popped: "<<pop()<<endl;
    cout<<peek();
    return 0;
}
