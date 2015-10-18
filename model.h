#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <vector>
#include <QGraphicsItem>
#include "node.h"

class Model
{

public:
    Model();
    ~Model();

    void loadTest();

    std::vector<std::shared_ptr<QGraphicsItem> > &getItems() {return items;};

private:

     std::vector<std::shared_ptr<QGraphicsItem> > items;
};

#endif // MODEL_H
