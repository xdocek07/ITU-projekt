#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workplace.h"
#include <QDebug>
#include <stdio.h>
#include <QPixmap>

#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

/*  ACTIONS */
    QAction *actionNew = new QAction(tr("New Project"), this);
    actionNew->setShortcut(QKeySequence(tr("Ctrl+N")));
    connect(actionNew, SIGNAL(triggered()), SLOT(newWorkspace()));

    QAction *actionOpen= new QAction(tr("Open Project"), this);
    actionOpen->setShortcut(QKeySequence(tr("Ctrl+O")));
    connect(actionOpen, SIGNAL(triggered()), SLOT(openExistingWorkspace()));

    QAction *actionSave = new QAction(tr("Save Project"), this);
    actionSave->setShortcut(QKeySequence(tr("Ctrl+S")));
    connect(actionSave, SIGNAL(triggered()), SLOT(saveWorkspace()));

    QAction *actionExport= new QAction(tr("Export"), this);
    actionExport->setShortcut(QKeySequence(tr("Ctrl+Shift+E")));
    connect(actionExport, SIGNAL(triggered()), this, SLOT(exportWorkspace()));

    QAction *actionQuit = new QAction(tr("Quit"), this);
    actionQuit->setShortcut(QKeySequence(tr("Ctrl+Q")));
    connect(actionQuit, SIGNAL(triggered()), SLOT(QuitApp()));

    QAction *actionUndo = new QAction(tr("Undo"), this);
    actionUndo->setShortcut(QKeySequence(tr("Ctrl+Z")));
    connect(actionUndo, SIGNAL(triggered()), SLOT(on_undoButton_clicked()));

    QAction *actionRedo = new QAction(tr("Redo"), this);
    actionRedo->setShortcut(QKeySequence(tr("Ctrl+Y")));
    connect(actionRedo, SIGNAL(triggered()), SLOT(on_redoButton_clicked()));

    QAction *addNew = new QAction(tr("Insert new"), this);
    addNew->setShortcut(QKeySequence(tr("Ctrl+Shift+N")));
    connect(addNew, SIGNAL(triggered()), this, SLOT(addNewNode()));

    QAction *deleteItems = new QAction(tr("Delete selected item"), this);
    deleteItems->setShortcut(QKeySequence::Delete);
    connect(deleteItems, SIGNAL(triggered()), this, SLOT(deleteSceneItems()));

    QAction *actionRotate = new QAction(tr("Rotate"), this);
    actionRotate->setShortcut(QKeySequence(tr("Ctrl+R")));
    //connect(actionRotate, SIGNAL(triggered()), SLOT(Rotate()));

/*  MENU BAR */
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(actionNew);
    fileMenu->addSeparator();
    fileMenu->addAction(actionOpen);
    fileMenu->addAction(actionSave);
    fileMenu->addAction(actionExport);
    fileMenu->addSeparator();
    fileMenu->addAction(actionQuit);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(actionUndo);
    editMenu->addAction(actionRedo);
    editMenu->addSeparator();
    editMenu->addAction(addNew);
    editMenu->addSeparator();
    editMenu->addAction(deleteItems);
    editMenu->addSeparator();
    editMenu->addAction(actionRotate);

/*  TOOL BOX */

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(this->width() - 10, this->height() - 15);
    model = new Model();
    model->loadTest();

    updateScene();

    setWindowTitle("Workflow diagram editor");

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

void MainWindow::QuitApp()
{
    QApplication::quit();
}

void saveWorkspace()
{
    //bude s aukladat iba file s insertmi a tie sa potom zas cele nacitaju? ci?
}

void openExistingWorkspace()
{
    //viz saveWorkspace
}

void newWorkspace()
{
    //add tab & new workspace
}

void MainWindow::exportWorkspace()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export", QCoreApplication::applicationDirPath(), "PNG (*.png)"); //"BMP (*.bmp);;JPEG (*.jpg *.jpeg);;
    if(!fileName.isNull())
    {
        QPixmap pixMap = this->ui->graphicsView->grab();
        qDebug() << fileName;
        pixMap.save(fileName, "PNG");
    }
}

void MainWindow::on_redoButton_clicked()
{
    //redo implementace
}

void MainWindow::on_undoButton_clicked()
{
    //undo implementace
}
/*
void MainWindow::Rotate()
{
    //rotate item
}
*/
void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    double newScale = arg1.left(arg1.indexOf(tr("%"))).toDouble()/100.0;
    QMatrix oldMatrix = this->ui->graphicsView->matrix();
    this->ui->graphicsView->resetMatrix();
    this->ui->graphicsView->translate(oldMatrix.dx(),oldMatrix.dy());
    this->ui->graphicsView->scale(newScale, newScale);
}
