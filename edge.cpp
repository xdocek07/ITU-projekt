#include "edge.h"

Edge::Edge(QGraphicsItem *from, QGraphicsItem *to, QString label)
    : from{from},
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



