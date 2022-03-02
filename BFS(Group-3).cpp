#include <iostream>
#include"Queue.h"
#include"Node.h"
#include"LinkedList.h"
#include"graph.h"
using namespace std;



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