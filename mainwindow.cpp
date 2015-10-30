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
    ui->graphicsView->resize(this->width() - 10, this->height() - 15);
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
    for(auto item : model->getNodes())
    {
         scene->addItem(item);

         item->setScene(scene);
         qDebug() << &scene ;
    }

    for(auto item : model->getEdges())
    {
         scene->addItem(item);
    }
}

void MainWindow::addNewNode()
{
    qDebug() << "fuck\n";
    Node *node = new Node(58, "", Qt::blue);
    scene->addItem(node);
    node->setScene(scene);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if(event)
    {
        ui->graphicsView->resize(this->width() - 10, this->height() - 15);
    }
}


