#include "model.h"

Model::Model()
    : itemId{0}
{
}

Model::~Model()
{

}

void Model::loadTest()
{
    Node *n1, *n2, *n3;
    n1 = new Node(++itemId, "fuckit", Qt::green, 50, 50, 30);
    n2 = new Node(++itemId, "ITU", Qt::red, 90, 90, 40);
    n3 = new Node(++itemId, "flow");
    nodes.push_back(n1);
    nodes.push_back(n2);
    nodes.push_back(n3);

    Edge *e1;
    e1 = new Edge(++itemId, n1, n2, "fuckinflow");
    edges.push_back(e1);

    n1->addEdge(e1);
    n2->addEdge(e1);
}
