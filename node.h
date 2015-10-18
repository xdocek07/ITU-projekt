#ifndef NODE_H
#define NODE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QColor>
#include <QString>

class Node : public QGraphicsItem
{
public:
    Node(const QString label, const QColor color = Qt::gray);
    ~Node();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    QString label;
    QColor color;
};

#endif // NODE_H
