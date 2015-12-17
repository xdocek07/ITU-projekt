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

<<<<<<< HEAD
    void addEdge(Node *from, Node *to, QString label = "");
=======
    unsigned int getAutoincrement() {return ++itemId;}

    Node *addNode(const QString label = "", const QColor color = Qt::gray, int x = 0, int y = 0, int len = 20);
    Node *addNode(Node *node);
    void addEdge(Node *from, Node *to, QString label = "");
    void saveAction(QUndoCommand *newCommand);

    QUndoStack *undoStack() const {return m_undoStack;}
>>>>>>> 912a5a30c8ea52f3491e17d21039fa5e3c18bca7

private:    
    std::map<int, Node *> nodes;
    std::map<int, Edge *> edges;
    unsigned int itemId;
    Node *previous;
<<<<<<< HEAD
=======
    QUndoStack *m_undoStack;
>>>>>>> 912a5a30c8ea52f3491e17d21039fa5e3c18bca7
};

#endif // MODEL_H
