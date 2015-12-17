#include "undo.h"
#include "model.h"
#include <QDebug>

AddNodeCommand::AddNodeCommand(Model* model, Node *node, QUndoCommand *parent)
    : QUndoCommand(parent),
      model(model),
      node(node)
{

}

void AddNodeCommand::undo()
{
    qDebug() << "fuck undo";
    //model->DeleteSceneItems(ID);
}

void AddNodeCommand::redo()
{
   model->addNode(node);
}


DeleteSceneCommand::DeleteSceneCommand(Model *model, int id, QUndoCommand *parent)
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
}
