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
    items.push_back(std::make_shared<Node>(++itemId, "fuckit", Qt::green));
    items.push_back(std::make_shared<Node>(++itemId, "ITU", Qt::red));
    items.push_back(std::make_shared<Node>(++itemId, "flow"));

    edges.push_back(std::make_shared<Edge>(items.at(0).get(), items.at(1).get(), "fuckinflow"));
}
