#ifndef EDGE_H
#define EDGE_H

#include <QString>
#include <QGraphicsItem>
#include "node.h"

class Edge : public QGraphicsItem
{
public:
    Edge(const unsigned int id, QGraphicsItem *from, QGraphicsItem *to, QString label = "");
    ~Edge();

    QString getLabel() const;
    void setLabel(const QString &value);

    QGraphicsItem *getFrom() const;
    void setFrom(QGraphicsItem *value);

    QGraphicsItem *getTo() const;
    void setTo(QGraphicsItem *value);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
    const unsigned int id;
    QGraphicsItem *from;
    QGraphicsItem *to;
    QString label;
};

#endif // EDGE_H
