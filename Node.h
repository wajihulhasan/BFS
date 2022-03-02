#include<iostream>
using namespace std;

class Node
{
public:
    Node(int data)
    {
        setData(data);
        setNext(NULL);
    }
    void setData(int data)
    {
        this->data = data;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
    int getData()
    {
        return data;
    }
    Node *getNext()
    {
        return next;
    }

private:
    int data;
    Node *next;
};