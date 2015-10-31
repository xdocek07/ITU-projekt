#ifndef NODE_H
#define NODE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QColor>
#include <QString>
#include "edge.h"

class Edge;

class Node : public QGraphicsItem
{
public:
    Node(const unsigned int id, const QString label, const QColor color = Qt::gray, int x = 0, int y = 0, int len = 20);
    ~Node();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    std::vector<Edge *> &getEdges() {return edges;}
    void setEdges(const std::vector<Edge *> &value) {edges = value;}
    void addEdge(Edge *edge) {edges.push_back(edge);}
    int getDiameter() const {return diameter;}
    void setScene(QGraphicsScene *uiscene);
    const unsigned int getId() {return id;}
    bool isActive() const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) ;

    const unsigned int id;
    QGraphicsTextItem *labelItem;
    QString label;
    QColor color;
    QRectF rect;
    bool active;
    int diameter;

    std::vector<Edge *> edges;
    QGraphicsScene *scene;
};

#endif // NODE_H
