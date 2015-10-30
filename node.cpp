#include "node.h"
#include <QDebug>

Node::Node(const unsigned int id, const QString label, const QColor color, int x, int y, int len)
    : id{id},
      label{label},
      active{false},
      diameter{len}
{
    setFlag(QGraphicsItem::ItemIsMovable);

    this->color = color;
    this->color.setAlpha(160);

    rect = QRectF(0, 0, len, len);
}

Node::~Node()
{

}

QRectF Node::boundingRect() const
{
    return QRectF(0, 0, diameter, diameter);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(!widget){
        return;
    }

    if(option){
        qDebug() << "Paint option: " << option;
    }
    /*
    QBrush brush(Qt::green);
    QLinearGradient g(rect.topLeft(), rect.bottomRight());
    g.setColorAt(0, c.dark(150));
    g.setColorAt(0.5, c.light(200));
    g.setColorAt(1, c.dark(150));
    painter->fillRect(rect, brush);
    */
    QColor drawColor = active ? Qt::green : color;

    painter->setBrush(drawColor);
    painter->drawEllipse(rect);

    painter->drawText(rect, Qt::AlignCenter, label);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    active = true;
    qDebug() << "selected node " << id;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    active = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

void Node::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    label = QString("hello");
    qDebug() << "doubleclicked node " << id;


    for(auto e: edges)
    {
        e->update();
    }
    update();
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseMoveEvent(event);
}
