#include<iostream>
#include"Node.h"
using namespace std;


class LinkedList
{
public:
    LinkedList()
    {
        setHead(NULL);
    }
    void addOnHead(int data)
    {
        if (isEmpty())
        {
            setHead(new Node(data));
        }
        else
        {
            Node *temp = new Node(data);
            temp->setNext(getHead());
            setHead(temp);
        }
    }
    void addOnTail(int data)
    {
        if (isEmpty())
        {
            addOnHead(data);
        }
        else
        {
            Node *temp = getHead();
            while (temp->getNext() != NULL)
            {
                temp = temp->getNext();
            }
            temp->setNext(new Node(data));
        }
    }
    void printList()
    {
        if (isEmpty())
        {
            cout << "The list is empty" << endl;
        }
        else
        {
            Node *temp = getHead();
            while (temp != NULL)
            {
                cout << temp->getData() << " ";
                temp = temp->getNext();
            }
            cout << endl;
        }
    }
    Node *searchNode(int key)
    {
        if (isEmpty())
        {
            return NULL;
        }
        else
        {
            Node *temp = getHead();
            while (temp != NULL && temp->getData() != key)
            {
                temp = temp->getNext();
            }
            return temp;
        }
    }

    bool isEmpty()
    {
        return getHead() == NULL;
    }
    Node *getHead() const
    {
        return head;
    }

private:
    void setHead(Node *head)
    {
        this->head = head;
    }

    Node *head;
};
