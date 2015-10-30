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
    labelItem = new QGraphicsTextItem;
    labelItem->setTextInteractionFlags(Qt::TextInteractionFlag::TextEditable);
    labelItem->setPos(rect.x(), rect.y());
    labelItem->setPlainText(label);
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

    // prisun label
    labelItem->setX(scenePos().x() + diameter / 4);
    labelItem->setY(scenePos().y() + diameter / 4);

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

    // replaced by labelItem
    //painter->drawText(rect, Qt::AlignCenter, label);
}

void Node::setScene(QGraphicsScene *uiscene)
{
    scene = uiscene;
    if(scene && labelItem)
       scene->addItem(labelItem);
    else
       qDebug() << "scene;fuck sceneL";
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
