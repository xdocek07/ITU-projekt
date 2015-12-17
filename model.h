#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <vector>
#include <map>
#include <QGraphicsItem>
#include <QString>
#include "node.h"
#include "edge.h"

class Model
{

public:
    Model();
    ~Model();

    void loadTest();

    std::map<int, Node *> &getNodes() {return nodes;}
    std::map<int, Edge *> &getEdges() {return edges;}

    void addEdge(Node *from, Node *to, QString label = "");

private:    
    std::map<int, Node *> nodes;
    std::map<int, Edge *> edges;
    unsigned int itemId;
    Node *previous;
};

#endif // MODEL_H
