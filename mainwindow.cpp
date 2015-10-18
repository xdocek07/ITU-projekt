#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workplace.h"

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
}


