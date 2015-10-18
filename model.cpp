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
}
