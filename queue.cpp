// queue all operations in c++

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};

class Queue
{
    public:
        Node *front;
        Node *rear;
        Queue()
        {
            front = NULL;
            rear = NULL;
        }
        bool isEmpty()
        {
            if (front == NULL && rear == NULL)
                return true;
            else
                return false;
        }
        bool isFull()
        {
            Node *temp = new Node();
            if (temp == NULL)
                return true;
            else
            {
                delete temp;
                return false;
            }
        }
        void enqueue(int val)
        {
            if (isFull())
            {
                cout << "Queue is full" << endl;
                return;
            }
            else
            {
                Node *newNode = new Node();
                newNode->data = val;
                if (front == NULL)
                {
                    front = newNode;
                    rear = newNode;
                }
                else
                {
                    rear->next = newNode;
                    rear = newNode;
                }
            }
        }
        int dequeue()
        {
            if (isEmpty())
            {
                cout << "Queue is empty" << endl;
                return 0;
            }
            else
            {
                Node *temp = front;
                front = front->next;
                int x = temp->data;
                delete temp;
                return x;
            }
        }
        int count()
        {
            int count = 0;
            Node *temp = front;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
        void display()
        {
            if (isEmpty())
            {
                cout << "Queue is empty" << endl;
                return;
            }
            else
            {
                Node *temp = front;
                while (temp != NULL)
                {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
};

int main()
{
    Queue q1;
    int option, value;
    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            cout << "Dequeue Operation \nDequeued Value : " << q1.dequeue() << endl;
            break;
        case 3:
            if (q1.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty" << endl;
            break;
        case 4:
            if (q1.isFull())
                cout << "Queue is Full" << endl;
            else
                cout << "Queue is not Full" << endl;
            break;
        case 5:
            cout << "Count Operation \nCount of items in Queue : " << q1.count() << endl;
            break;
        case 6:
            cout << "Display Function Called - " << endl;
            q1.display();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}