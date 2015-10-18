#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workplace.h"
#include <QDebug>
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    model = new Model();
    model->loadTest();

    updateScene();

    QAction *addNew = new QAction(tr("Add new"), this);
    addAction(addNew);
    addNew->setShortcut(QKeySequence(tr("Ctrl+N")));
    connect(addNew, SIGNAL(triggered()), this, SLOT(addNewNode()));
}

MainWindow::~MainWindow()
{
    for(auto i : scene->items())
    {
        delete i;
    }
    delete ui;
}

void MainWindow::updateScene()
{
    for(auto item : model->getItems())
    {
         scene->addItem(item.get());
    }

    for(auto edge : model->getEdges())
    {
        QPainter painter(this);
        QPen pen;
        pen.setBrush(QBrush(Qt::blue));
        scene->addLine((qreal)edge.get()->getFrom()->boundingRect().center().x(),
                       (qreal)edge.get()->getFrom()->boundingRect().center().y(),
                       (qreal)edge.get()->getTo()->boundingRect().center().x(),
                       (qreal)edge.get()->getTo()->boundingRect().center().y()
                       );
    }
}

void MainWindow::addNewNode()
{
    qDebug() << "fuck\n";
    scene->addItem(new Node(58, "fuckit", Qt::blue));
}


