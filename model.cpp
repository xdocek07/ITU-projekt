#include "model.h"

Model::Model()
    : itemId{0}
{
}

Model::~Model()
{
    // clean objects referenced in maps
    for(auto node : nodes)
    {
         delete node.second;
    }
    for(auto edge : edges)
    {
         delete edge.second;
    }
}

void Model::loadTest()
{
    Node *n1, *n2, *n3, *n4;
    int i;
    n1 = new Node(i = ++itemId, "fuckit", Qt::green, 50, 50, 30);
    nodes[i] = n1;
    n2 = new Node(i = ++itemId, "ITU", Qt::red, 90, 90, 40);
    nodes[i] = n2;
    n3 = new Node(i = ++itemId, "flow");
    nodes[i] = n3;
    n4 = new Node(i = ++itemId, "ITU2", Qt::yellow, 95, 95, 80);
    nodes[i] = n4;

    Edge *e1;
    e1 = new Edge(i = ++itemId, n1, n2, "fuckinflow");
    edges[i] = e1;

    n1->addEdge(e1);
    n2->addEdge(e1);
}
