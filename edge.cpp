#include "edge.h"
#include <QDebug>

Edge::Edge(const unsigned int id, Node *from, Node *to, QString label)
    : id{id},
      from{from},
      to{to},
      label{label}
{
    active = false;
    rect = QRectF(from->x(), from->y(), to->x(), to->y());
    labelItem = new QGraphicsTextItem(this);
    labelItem->setTextInteractionFlags(Qt::TextInteractionFlag::TextEditable);
    labelItem->setPos(rect.center().x(), rect.center().y() + 2);
    labelItem->setPlainText(label);
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
    //return QRectF(0, 0, 2 * abs(from->x() - to->x()), 2 * abs(from->y() - to->y()));
    return QRectF(from->sceneBoundingRect().center(), to->sceneBoundingRect().center());
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if(!widget){
        return;
    }

    if(option){
        //qDebug() << "Paint option: " << option;
    }

    //rect = QRectF(from->x(), from->y(), to->x(), to->y());

    QPointF start(from->sceneBoundingRect().center());
    QPointF end(to->sceneBoundingRect().center());
    painter->setBrush(Qt::black);



    painter->drawLine(start, end);

    /* @todo funkce na vypocet orientace?
    painter->drawLine(end - QPoint(0, 20), end);
    painter->drawLine(end + QPoint(20, 0), end);
    */

    QPointF labelPos = QPointF(start.x() + (abs(start.x() - end.x())), start.y() + (abs(start.y() - end.y()))) / 2.0;
    //painter->drawText(labelPos, label);

    labelItem->setPos(labelPos);
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

bool Edge::isActive() const
{
    return active;
}


