// linked list insertion, deletion, searching, display, delete

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head, *tail;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int n)
    {
        node *temp = new node;
        temp->data = n;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }

    void display()
    {
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void insert_start(int n)
    {
        node *temp = new node;
        temp->data = n;
        temp->next = head;
        head = temp;
    }

    void insert_position(int pos, int n)
    {
        node *pre = new node;
        node *cur = new node;
        node *temp = new node;
        cur = head;
        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        temp->data = n;
        pre->next = temp;
        temp->next = cur;
    }

    void delete_first()
    {
        node *temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }

    void delete_last()
    {
        node *current = new node;
        node *previous = new node;
        current = head;
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        tail = previous;
        previous->next = NULL;
        delete current;
    }

    void delete_position(int pos)
    {
        node *current = new node;
        node *previous = new node;
        current = head;
        for (int i = 1; i < pos; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
    }

    void search(int value)
    {
        int pos = 0;
        bool flag = false;
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            pos++;
            if (temp -> data == value)
            {
                flag = true;
                cout << "Element " << value << " is found at position " << pos << endl;
            }
            temp = temp->next;
        }
        if (!flag)
        {
            cout << "Element " << value << " not found" << endl;
        }
    }
};

int main()
{
    linked_list a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.display();
    cout << endl;
    a.insert_start(0);
    a.display();
    cout << endl;
    a.insert_position(3, 10);
    a.display();
    cout << endl;
    a.delete_first();
    a.display();
    cout << endl;
    a.delete_last();
    a.display();
    cout << endl;
    a.delete_position(3);
    a.display();
    cout << endl;
    a.search(10);
    a.search(100);
    return 0;
}