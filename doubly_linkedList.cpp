#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int item;
    Node *next;
    Node *prev;
    Node()
    {
        item = 0;
        next = NULL;
        prev = NULL;
    }
};

class linkedList
{
public:
    Node *first;
    Node *last;
    linkedList()
    {
        first = NULL;
        last = NULL;
    }
    bool isEmpty()
    {
        return first == NULL;
    }
    void destroy()
    {
        Node *temp;
        while (first != NULL)
        {
            temp = first;
            first = first->next;
            delete temp;
        }
        last = NULL;
    }
    int count()
    {
        int counter = 0;
        if (isEmpty())
        {
        }
        else
        {
            Node *temp = first;
            while (temp != NULL)
            {
                counter++;
                temp = temp->next;
            }
        }
        return counter;
    }
    void insertFirst(int value)
    {
        Node *newNode = new Node;
        newNode->item = value;
        if (isEmpty())
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            first->prev = newNode;
            newNode->next = first;
            first = newNode;
        }
    }
    void insertLast(int value)
    {
        Node *newNode = new Node;
        newNode->item = value;
        if (isEmpty())
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
    }
    void insertAt(int index, int value)
    {
        if (index < 0 || index > count())
        {
            cout << "out of range...!" << endl;
        }
        else
        {
            if (index == 0)
            {
                insertFirst(value);
            }
            else if (index == count())
            {
                insertLast(value);
            }
            else
            {
                Node *newNode = new Node;
                newNode->item = value;
                Node *temp = first;
                index--;
                while (index--)
                {
                    temp = temp->next;
                }
                Node *ins = temp->next;
                newNode->next = ins;
                newNode->prev = temp;
                ins->prev = newNode;
                temp->next = newNode;
            }
        }
    }
    void removeFirst()
    {
        if (isEmpty())
        {
            cout << "the list is empty!" << endl;
        }
        else
        {
            if (count() == 1)
            {
                delete first;
                first = last = NULL;
            }
            else
            {
                Node *del = first;
                first = first->next;
                first->prev = NULL;
                delete del;
            }
        }
    }
    void removeLast()
    {
        if (isEmpty())
        {
            cout << "the list is empty!" << endl;
        }
        else
        {
            if (count() == 1)
            {
                delete last;
                first = last = NULL;
            }
            else
            {
                Node *del = last;
                last = last->prev;
                if (last != NULL)
                {
                    last->next = NULL;
                }
                delete del;
            }
        }
    }
    void removeNthNode(int index)
    {
        if (index < 0 || index > count())
        {
            cout << "out of range...!" << endl;
        }
        else
        {
            if (index == 0)
            {
                removeFirst();
            }
            else if (index == count())
            {
                removeLast();
            }
            else
            {
                index--;
                Node *temp = first;
                while (index--)
                {
                    temp = temp->next;
                }
                Node *del = temp->next;
                del->next->prev = temp;
                temp->next = del->next;
                delete del;
            }
        }
    }
    int search(int value)
    {
        int index = 0;
        if (isEmpty())
        {
            index = -1;
        }
        else
        {
            Node *temp = first;
            while (temp->item != value)
            {
                temp = temp->next;
                index++;
            }
        }
        return index;
    }
    void remove(int value)
    {
        int index = search(value);
        removeNthNode(index);
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "the list is already empty" << endl;
        }
        else
        {
            Node *temp = first;
            while (temp != NULL)
            {
                cout << temp->item << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void reverseDisplay()
    {
        if (isEmpty())
        {
            cout << "the list is already empty" << endl;
        }
        else
        {
            Node *temp = last;
            while (temp != NULL)
            {
                cout << temp->item << " ";
                temp = temp->prev;
            }
            cout << endl;
        }
    }
};

int main()
{
    linkedList list1;
    list1.insertFirst(1);
    list1.insertLast(5);
    list1.insertAt(1, 3);
    list1.insertFirst(0);
    list1.removeNthNode(1);
    list1.removeFirst();
    list1.removeLast();
    list1.display();
    cout << list1.count();
}
