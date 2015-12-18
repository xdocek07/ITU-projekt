#ifndef EDGE_H
#define EDGE_H

#include <QString>
#include <QGraphicsItem>
#include "node.h"

class Node;

class Edge : public QGraphicsItem
{
public:
    Edge(const unsigned int id, Node *from, Node *to, QString label = "");
    ~Edge();

    QString getLabel() const;
    void setLabel(const QString &value);

    Node *getFrom() const;
    void setFrom(Node *value);

    Node *getTo() const;
    void setTo(Node *value);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool isActive() const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
    const unsigned int id;
    bool active;
    Node *from;
    Node *to;
    QString label;
    QGraphicsTextItem *labelItem;
    QRectF rect;
};

#endif // EDGE_H
