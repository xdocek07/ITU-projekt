#include "mainwindow.h"
#include "ui_mainwindow.h"
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

    QAction *deleteItems = new QAction(tr("Delete items"), this);
    deleteItems->setShortcut(QKeySequence::Delete);
    connect(deleteItems, SIGNAL(triggered()), this, SLOT(deleteSceneItems()));
    addAction(deleteItems);
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
         scene->addItem(item.second);

         item.second->setScene(scene);
         qDebug() << &scene ;
    }

    for(auto item : model->getEdges())
    {
         scene->addItem(item.second);
    }
}

void MainWindow::addNewNode()
{
    qDebug() << "fuck\n";
    Node *node = new Node(58, "", Qt::blue);

   scene->addItem(node);

   node->setScene(scene);
}

void MainWindow::deleteSceneItems()
{
    qDebug() << "deleting";
    /*
    for(auto item : scene->focusItem())
    {

        if(item->isActive())
        {
            qDebug() << item;
            item->setVisible(false);
            scene->removeItem(item);
            delete item;
        }
    }

    */
    if(scene->focusItem())
    {
        scene->focusItem()->setVisible(false);

        scene->removeItem(scene->focusItem());
        delete scene->focusItem();
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if(event)
    {
        ui->graphicsView->resize(this->width() - 10, this->height() - 15);
    }
}


