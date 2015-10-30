#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <vector>
#include <QGraphicsItem>
#include "node.h"
#include "edge.h"

class Model
{

public:
    Model();
    ~Model();

    void loadTest();

    std::vector<Node *> &getNodes() {return nodes;}
    std::vector<Edge *> &getEdges() {return edges;}
private:
    std::vector<Node *> nodes;
    std::vector<Edge *> edges;
    unsigned int itemId;
};

#endif // MODEL_H
