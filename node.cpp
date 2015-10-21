#include "node.h"
#include <QDebug>

Node::Node(const unsigned int id, const QString label, const QColor color)
    : id{id},
      label{label}
{
    setFlag(QGraphicsItem::ItemIsMovable);

    this->color = color;
    this->color.setAlpha(160);

    int x = rand() % 150;
    int y = rand() % 150;
    int z = rand() % 150;
    int w = rand() % 150;
    rect = QRectF(x, y, z, w);
}

Node::~Node()
{

}

QRectF Node::boundingRect() const
{
    return rect;
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

    painter->setBrush(color);
    painter->drawEllipse(rect);

    painter->drawText(rect, Qt::AlignCenter, label);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "selected node " << id;
    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
}

void Node::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    label = QString("hello");
    qDebug() << "doubleclicked node " << id;
    QGraphicsItem::mouseDoubleClickEvent(event);
    update();
    for(auto e: edges)
    {
        e->update();
    }
}
std::vector<Edge *> Node::getEdges() const
{
    return edges;
}

void Node::setEdges(const std::vector<Edge *> &value)
{
    edges = value;
}

