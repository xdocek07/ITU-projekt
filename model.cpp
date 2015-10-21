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
    items.push_back(new Node(++itemId, "fuckit", Qt::green));
    items.push_back(new Node(++itemId, "ITU", Qt::red));
    items.push_back(new Node(++itemId, "flow"));

    items.push_back(new Edge(++itemId, items[0], items[1], "fuckinflow"));
    Node *p = (Node *) items[0];
    p->addEdge((Edge *)items[3]);
    p =  (Node *) items[1];
    p->addEdge((Edge *)items[3]);
}
