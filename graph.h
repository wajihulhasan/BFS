#include<iostream>
#include"LinkedList.h"
#include"Queue.h"
using namespace std;


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