#include <iostream>
#include <stack>
using namespace std;

stack<int> s1, s2;
void enqueue(int x)
{
    s1.push(x);
    cout << x << " inserted into queue."<<endl;
}

void dequeue()
{
    if (s1.empty() && s2.empty())
    {
        cout << "Queue Underflow! Queue is empty."<<endl;
        return;
    }
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    cout << s2.top() << " removed from queue."<<endl;
    s2.pop();
}

void display()
{
    if (s1.empty() && s2.empty())
    {
        cout << "Queue is empty."<<endl;
        return;
    }
    cout << "Queue elements: ";
    stack<int> temp = s2;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    stack<int> temp2 = s1;
    stack<int> rev;
    while (!temp2.empty())
    {
        rev.push(temp2.top());
        temp2.pop();
    }
    while (!rev.empty())
    {
        cout << rev.top() << " ";
        rev.pop();
    }
    cout << endl;
}

int main()
{
    int choice, value;
    do {
        cout << "\n--- Queue Using Stack ---"<<endl;
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Display"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
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
