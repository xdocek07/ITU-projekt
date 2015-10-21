#include "edge.h"
#include <QDebug>

Edge::Edge(const unsigned int id, QGraphicsItem *from, QGraphicsItem *to, QString label)
    : id{id},
      from{from},
      to{to},
      label{label}
{
}

Edge::~Edge()
{

}

QString Edge::getLabel() const
{
    return label;
}

void Edge::setLabel(const QString &value)
{
    label = value;
}
QGraphicsItem *Edge::getFrom() const
{
    return from;
}

void Edge::setFrom(QGraphicsItem *value)
{
    from = value;
}
QGraphicsItem *Edge::getTo() const
{
    return to;
}

void Edge::setTo(QGraphicsItem *value)
{
    to = value;
}

QRectF Edge::boundingRect() const
{

}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(!widget){
        return;
    }

    if(option){
        qDebug() << "Paint option: " << option;
    }


    QPointF start(from->boundingRect().center());
    QPointF end(to->boundingRect().center());
    painter->setBrush(Qt::black);


    painter->drawLine(start, end);

    QPointF labelPos = QPointF((abs(start.x() - end.x()) / 2), (abs(start.y() - end.y()) / 2));
    painter->drawText(labelPos, label);
}

void Edge::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void Edge::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}

void Edge::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{

}



