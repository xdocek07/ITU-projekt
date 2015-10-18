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

    std::vector<std::shared_ptr<QGraphicsItem>> &getItems() {return items;}
    std::vector<std::shared_ptr<Edge>> &getEdges() {return edges;}

private:

    std::vector<std::shared_ptr<QGraphicsItem>> items;
    std::vector<std::shared_ptr<Edge>> edges;

    unsigned int itemId;
};

#endif // MODEL_H
