#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <vector>
#include <map>
#include <QGraphicsItem>
#include <QString>
#include "node.h"
#include "edge.h"
#include <QUndoStack>
#include <QObject>
#include "undo.h"



class Model : public QObject
{

public:
    Model();
    ~Model();

    void loadTest();

    std::map<int, Node *> &getNodes() {return nodes;}
    std::map<int, Edge *> &getEdges() {return edges;}

    Edge *addEdge(Node *from, Node *to, QString label = "");
    unsigned int getAutoincrement() {return ++itemId;}

    Node *addNode(const QString label = "", const QColor color = Qt::gray, int x = 0, int y = 0, int len = 20);
    Node *addNode(Node *node);
    void saveAction(QUndoCommand *newCommand);
    QUndoStack *undoStack() const {return m_undoStack;}

private:    
    std::map<int, Node *> nodes;
    std::map<int, Edge *> edges;
    unsigned int itemId;
    Node *previous;
    QUndoStack *m_undoStack;

};

#endif // MODEL_H
