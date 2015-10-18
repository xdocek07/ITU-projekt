#ifndef EDGE_H
#define EDGE_H

#include <QString>
#include <QGraphicsItem>
#include "node.h"

class Edge
{
public:
    Edge(QGraphicsItem *from, QGraphicsItem *to, QString label = "");
    ~Edge();

    QString getLabel() const;
    void setLabel(const QString &value);

    QGraphicsItem *getFrom() const;
    void setFrom(QGraphicsItem *value);

    QGraphicsItem *getTo() const;
    void setTo(QGraphicsItem *value);

private:
    QGraphicsItem *from;
    QGraphicsItem *to;
    QString label;
};

#endif // EDGE_H
