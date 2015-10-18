#include "workplace.h"

Workplace::Workplace(QWidget *parent) :
    QWidget(parent)
{
    setAutoFillBackground(true);
    setBackgroundRole(QPalette::Base);

    QPalette pal = palette();
    pal.setBrush(QPalette::Base, QPixmap(":/icons/background.png"));
    pal.setColor(QPalette::HighlightedText, Qt::red);
    setPalette(pal);
}


void Workplace::paintEvent(QPaintEvent *event)
{
    if(!event)
        return;
    /*
    scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);
    scene->addText("Hello, world!");
    QGraphicsItem *e = new QGraphicsEllipseItem(20, 20, 20, 20);
    e->setFlag(QGraphicsItem::ItemIsMovable);

    QPen p;

    e->setData(1, "fuck");
    scene->addItem(e);
    */
    QRegion paintRegion = event->region();
    QPainter painter(this);
    QPalette pal = palette();




    int left = 50;
    int top = 50;
    int width = 100;
    int height = 150;

    QRect rect(left, top, width, height);

    QPen pen = pal.text().color();
    pen.setWidth(2);
    painter.setPen(pen);

    QColor c = Qt::green;
    c.setAlpha(160);
    QLinearGradient g(rect.topLeft(), rect.bottomRight());
    g.setColorAt(0, c.dark(150));
    g.setColorAt(0.5, c.light(200));
    g.setColorAt(1, c.dark(150));

    painter.setBrush(g);

    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawEllipse(rect);
    painter.setRenderHint(QPainter::Antialiasing, false);

    // paint the resize handle
    /*
    painter.setPen(Qt::black);
    painter.setBrush(Qt::red);
    painter.drawRect(rect);
*/
    // paint the shape name
    //painter.setBrush(pal.text());

    painter.drawText(rect, Qt::AlignCenter, "fuckit");

    left = 150;
    top = 150;
    width = 100;
   height = 150;

    QRect rect2(left, top, width, height);

    painter.drawEllipse(rect2);
    painter.drawText(rect2, Qt::AlignCenter, "u");

    painter.drawLine(rect.center(), rect2.center());

}
