#include "model.h"
#include <QUndoStack>
#include <QDebug>
#include <QUndoGroup>
#include <QAction>

Model::Model()
    : nodes{},
      edges{}
{
    current = nullptr;
    previous = nullptr;
    itemId = 0;
    m_undoStack = new QUndoStack(this);
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

void Model::loadTest(QGraphicsScene *scene)
{
    Node *n1, *n2, *n3, *n4;

    n1 =  addNode("HELLO", Qt::green, 50, 50, 30);
    scene->addItem(n1);
    n1->setScene(scene);

    n2 = addNode("ITU", Qt::red, 90, 90, 40);
    n2->setScene(scene);
    scene->addItem(n2);

    n3 = addNode("flow");
    n3->setScene(scene);
    scene->addItem(n3);

    n4 = addNode("WORLD", Qt::yellow, 95, 95, 80);
    n4->setScene(scene);
    scene->addItem(n4);

    addEdge(n1, n2, "edge flow");
}

Node *Model::addNode(const QString label, const QColor color, int x, int y, int len)
{
    unsigned int id = getAutoincrement();
    Node *node = new Node(id, label, color, x, y, len);
    //qDebug() << node;
    //nodes[id] = node;

    QUndoCommand *a = new AddNodeCommand(this, node->getId());
    //qDebug() << node->getId();
    //nodes[id] = node;

    //saveAction(a);
    this->undoStack()->push(a);
    return node;
}

Node *Model::addNode(Node *node)
{
    unsigned int id = node->getId();
    nodes[id] = node;
    return nodes[id];
}

Edge *Model::addEdge(Node *from, Node *to, QString label)
{
    int i = ++itemId;
    edges[i] = new Edge(i, from, to, label);
    from->addEdge(edges[i]);
    to->addEdge(edges[i]);

    return edges[i];
}

void Model::saveAction(QUndoCommand *newCommand)
{
    m_undoStack->push(newCommand);
}
