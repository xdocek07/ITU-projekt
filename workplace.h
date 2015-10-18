#ifndef WORKPLACE_H
#define WORKPLACE_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class Workplace : public QWidget
{
    Q_OBJECT
public:
    explicit Workplace(QWidget *parent = 0);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // WORKPLACE_H
