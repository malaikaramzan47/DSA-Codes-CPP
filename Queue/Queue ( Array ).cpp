#include <iostream>
using namespace std;

#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

bool isEmpty()
{
    return (front == -1 || front > rear);
}

bool isFull()
{
    return (rear == MAX - 1);
}

void enqueue(int value)
{
    if (isFull())
    {
        cout << "Queue Overflow! Cannot insert."<<endl;
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
    cout << value << " inserted into queue."<<endl;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Underflow! Cannot delete."<<endl;
        return;
    }
    cout << queue[front] << " removed from queue."<<endl;
    front++;
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty."<<endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice, value;
    do {
        cout << "\n--- Queue Menu ---"<<endl;
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Display"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting program."<<endl;
                break;
            default:
                cout << "Invalid choice!"<<endl;
        }
    } while (choice != 4);

    return 0;
}
