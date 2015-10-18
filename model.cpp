#include "model.h"

Model::Model()
{
}

Model::~Model()
{

}

void Model::loadTest()
{
    items.push_back(std::make_shared<Node>("fuckit", Qt::green));
    items.push_back(std::make_shared<Node>("ITU", Qt::red));
    items.push_back(std::make_shared<Node>("flow"));

    edges.push_back(std::make_shared<Edge>(items.at(0).get(), items.at(1).get(), "fuckinflow"));
}
