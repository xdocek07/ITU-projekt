#ifndef UNDO_H
#define UNDO_H

#include <QUndoCommand>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QColor>
#include <QString>
#include "edge.h"
#include "model.h"
#include "node.h"

class Model;

class AddNodeCommand : public QUndoCommand
{
public:
    AddNodeCommand(Model *model, Node *node,  QUndoCommand *parent = 0);
    void undo() Q_DECL_OVERRIDE;
    void redo() Q_DECL_OVERRIDE;

private:
    Model *model;
    Node *node;
};

class DeleteSceneCommand : public QUndoCommand
{
public:
    DeleteSceneCommand(Model *model, int id, QUndoCommand *parent = 0);
    void undo() Q_DECL_OVERRIDE;
    void redo() Q_DECL_OVERRIDE;

private:
    int ID;
};


#endif
