#ifndef NODE_H
#define NODE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QColor>
#include <QString>
#include "edge.h"

class Edge;

class Node : public QGraphicsItem
{
public:
    Node(const unsigned int id, const QString label, const QColor color = Qt::gray);
    ~Node();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    std::vector<Edge *> getEdges() const;
    void setEdges(const std::vector<Edge *> &value);
    void addEdge(Edge *edge) {edges.push_back(edge);}

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    const unsigned int id;
    QString label;
    QColor color;
    QRectF rect;

    std::vector<Edge *> edges;
};

#endif // NODE_H
