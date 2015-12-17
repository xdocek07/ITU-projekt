#include "model.h"

Model::Model()
    : itemId{0}
{
    previous = nullptr;
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

    addEdge(n1, n2, "fuckinflow");
}

void Model::addEdge(Node *from, Node *to, QString label)
{
    int i = ++itemId;
    edges[i] = new Edge(i, from, to, label);
    from->addEdge(edges[i]);
    to->addEdge(edges[i]);
}
