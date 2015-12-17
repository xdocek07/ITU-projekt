#include "model.h"
#include <QUndoStack>
#include <QDebug>
#include <QUndoGroup>
#include <QAction>

Model::Model()
    : nodes{},
      edges{}
{
    previous = nullptr;
    itemId = 0;



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

    n1 =  addNode("fuckit", Qt::green, 50, 50, 30);

    n2 = addNode("ITU", Qt::red, 90, 90, 40);

    n3 = addNode("flow");

    n4 = addNode("ITU2", Qt::yellow, 95, 95, 80);

    addEdge(n1, n2, "fuckinflow");
}

Node *Model::addNode(const QString label, const QColor color, int x, int y, int len)
{
    unsigned int id = ++itemId;
    qDebug() << id << '\n';

    Node *node = new Node(id, label, color, x, y, len);
    qDebug() << node;
    //nodes[id] = node;

    AddNodeCommand *a = new AddNodeCommand(this, node);
    saveAction(a);

    return node;
}

Node *Model::addNode(Node *node)
{
    unsigned int id = node->getId();
    nodes[id] = node;
    return nodes[id];
}

void Model::addEdge(Node *from, Node *to, QString label)
{
    int i = ++itemId;
    edges[i] = new Edge(i, from, to, label);
    from->addEdge(edges[i]);
    to->addEdge(edges[i]);
}

void Model::saveAction(QUndoCommand *newCommand)
{
    m_undoStack->push(newCommand);
}
