#include <iostream>
#define SIZE 20
using namespace std;

class Queue
{
private:
    int items[SIZE], front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        if (front == 0 && rear == SIZE - 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    void enQueue(int element)
    {
        if (isFull())
        {
            cout << "Queue is full";
        }
        else
        {
            if (front == -1)
                front = 0;
            rear++;
            items[rear] = element;
        }
    }
    int frontElement()
    {
        if (!isEmpty())
        {
            return items[front];
        }
        return -1;
    }

    int deQueue()
    {
        int element;
        if (isEmpty())
        {
            return (-1);
        }
        else
        {
            element = items[front];
            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front++;
            }
            return (element);
        }
    }
};
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

class graph
{
    LinkedList *array;
    int size;
    void setSize(int size)
    {
        if (size > 5)
        {
            this->size = size;
        }
        else
        {
            this->size = 10;
        }
    }
    int getSize()
    {
        return size;
    }

public:
    graph(int size)
    {
        setSize(size);
        this->array = new LinkedList[getSize()];
    }
    void addEdge(int edge1, int edge2)
    {
        array[edge1].addOnTail(edge2);
    }

    void print()
    {
        for (int index = 0; index < getSize(); index += 1)
        {
            cout << "[" << index << "] -> ";
            array[index].printList();
            cout << endl;
        }
    }
    void BFS(int vertix)
    {
        cout << "BFS traversal of the graph is :";
        bool *visited = new bool[getSize()];
        for (int i = 0; i < getSize(); i++)
        {
            visited[i] = false;
        }
        Queue q;

        q.enQueue(vertix);
        visited[vertix] = true;
        while (!q.isEmpty())
        {

            vertix = q.frontElement();
            cout << vertix << " ";
            q.deQueue();
            Node *current = array[vertix].getHead();
            while (current != NULL)
            {
                if (!visited[current->getData()])
                {
                    visited[current->getData()] = true;
                    q.enQueue(current->getData());
                }
                current = current->getNext();
            }
        }
    }
};
int main()
{
    graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.print();
    g.BFS(2);
    cout << endl;
}