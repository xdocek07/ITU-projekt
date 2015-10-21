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

    std::vector<QGraphicsItem *> &getItems() {return items;}

private:
    std::vector<QGraphicsItem *> items;

    unsigned int itemId;
};

#endif // MODEL_H
