#include "edge.h"
#include <QDebug>

Edge::Edge(const unsigned int id, Node *from, Node *to, QString label)
    : id{id},
      from{from},
      to{to},
      label{label}
{
    rect = QRectF(from->x(), from->y(), to->x(), to->y());
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
Node *Edge::getFrom() const
{
    return from;
}

void Edge::setFrom(Node *value)
{
    from = value;
}
Node *Edge::getTo() const
{
    return to;
}

void Edge::setTo(Node *value)
{
    to = value;
}

QRectF Edge::boundingRect() const
{
    return QRectF(from->x(), from->y(), to->x(), to->y());
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(!widget){
        return;
    }

    if(option){
        qDebug() << "Paint option: " << option;
    }

    rect = QRectF(from->x(), from->y(), to->x(), to->y());

    QPointF start(from->sceneBoundingRect().center());
    QPointF end(to->sceneBoundingRect().center());
    painter->setBrush(Qt::black);



    painter->drawLine(start, end);

    /* @todo funkce na vypocet orientace?
    painter->drawLine(end - QPoint(0, 20), end);
    painter->drawLine(end + QPoint(20, 0), end);
    */
    QPointF labelPos = QPointF(start.x() + ((start.x() - end.x()) / 2), start.y() + ((start.y() - end.y()) / 2));
    painter->drawText(labelPos, label);
}

void Edge::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
}

void Edge::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
}

void Edge::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{    
    update();
    QGraphicsItem::mouseDoubleClickEvent(event);
}



