#include "node.h"

Node::Node(const QString label, const QColor color)
    : label{label}
{
    setFlag(QGraphicsItem::ItemIsMovable);

    this->color = color;
    this->color.setAlpha(160);
}

Node::~Node()
{

}

QRectF Node::boundingRect() const
{
    return QRectF(10, 10, 50, 50);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush brush(Qt::green);

    /*
    QLinearGradient g(rect.topLeft(), rect.bottomRight());
    g.setColorAt(0, c.dark(150));
    g.setColorAt(0.5, c.light(200));
    g.setColorAt(1, c.dark(150));
*/
    painter->setBrush(color);
    painter->drawEllipse(rect);
    //painter->fillRect(rect, brush);
    painter->drawText(rect, Qt::AlignCenter, label);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}
