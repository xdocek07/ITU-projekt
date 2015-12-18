#include "undo.h"
#include "model.h"
#include <QDebug>

AddNodeCommand::AddNodeCommand(Model* model, unsigned int id, QUndoCommand *parent)
    : QUndoCommand(parent),
      model(model),
      //node(node),
      nodeId(id)
{

}

void AddNodeCommand::undo()
{
    qDebug() << "fuck undo";
    //model->DeleteSceneItems(ID);
}

void AddNodeCommand::redo()
{
    qDebug() << "fuck redo";
   /*std::map<int, Node *> m = model->getNodes();
   Node *node = m[nodeId];
   model->addNode(node);*/
}

/*
DeleteSceneCommand::DeleteSceneCommand(Model *model, unsigned int id, QUndoCommand *parent)
    : QUndoCommand(parent)
{
   ID = id;
}

void DeleteSceneCommand::undo()
{
    //Model->AddNewNode(ID);
}

void DeleteSceneCommand::redo()
{
    //Model->DeleteSceneItems(ID);
}*/
