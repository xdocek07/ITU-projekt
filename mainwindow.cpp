#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdio.h>
#include <QPixmap>

#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(this->width() - 10, this->height() - 15);
    //m_undoStack = new QUndoStack(this);
    //QUndoGroup *m_undoGroup = new QUndoGroup(this);

/*  ACTIONS */
    QAction *actionNew = new QAction(tr("New Project"), this);
    actionNew->setShortcut(QKeySequence(tr("Ctrl+W")));
    connect(actionNew, SIGNAL(triggered()), this, SLOT(newWorkspace()));

    QAction *actionOpen= new QAction(tr("Open Project"), this);
    actionOpen->setShortcut(QKeySequence(tr("Ctrl+O")));
    connect(actionOpen, SIGNAL(triggered()), this, SLOT(openExistingWorkspace()));

    QAction *actionSave = new QAction(tr("Save Project"), this);
    actionSave->setShortcut(QKeySequence(tr("Ctrl+S")));
    connect(actionSave, SIGNAL(triggered()), this, SLOT(saveWorkspace()));

    QAction *actionExport= new QAction(tr("Export as PNG"), this);
    actionExport->setShortcut(QKeySequence(tr("Ctrl+Shift+E")));
    connect(actionExport, SIGNAL(triggered()), this, SLOT(exportWorkspace()));

    QAction *actionQuit = new QAction(tr("Quit"), this);
    actionQuit->setShortcut(QKeySequence(tr("Ctrl+Q")));
    connect(actionQuit, SIGNAL(triggered()), this, SLOT(QuitApp()));

    QAction *actionUndo = new QAction(tr("Undo"), this);
    actionUndo->setShortcut(QKeySequence(tr("Ctrl+Z")));
    connect(actionUndo, SIGNAL(triggered()), this, SLOT(on_undoButton_clicked()));

    QAction *actionRedo = new QAction(tr("Redo"), this);
    actionRedo->setShortcut(QKeySequence(tr("Ctrl+Y")));
    connect(actionRedo, SIGNAL(triggered()), this, SLOT(on_redoButton_clicked()));
    /*
    addNew = new QAction(tr("Insert new"), this);
    addNew->setShortcut(QKeySequence(tr("Ctrl+N")));
    connect(addNew, SIGNAL(triggered()), this, SLOT(addNewNode()));
    */
    QAction *ADDitemAction = new QAction(tr("Add new item"), this);
    ADDitemAction->setShortcut(QKeySequence(tr("Ctrl+N")));
    connect(ADDitemAction, SIGNAL(triggered()), this, SLOT(addNewNode()));

    QAction *ADDconnectionAction = new QAction(tr("Add new connection"), this);
    connect(ADDconnectionAction, SIGNAL(triggered()), this, SLOT(addNewConnection()));

    QAction *ADDtextAction = new QAction(tr("Add text"), this);
    connect(ADDtextAction, SIGNAL(triggered()), this, SLOT(addText()));

    QAction *deleteItems = new QAction(tr("Delete selected item"), this);
    deleteItems->setShortcut(QKeySequence::Delete);
    connect(deleteItems, SIGNAL(triggered()), this, SLOT(deleteSceneItems()));


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

    insertMenu = editMenu->addMenu(tr("&Insert New"));
    insertMenu->addAction(ADDitemAction);
    insertMenu->addAction(ADDconnectionAction);
    insertMenu->addAction(ADDtextAction);

    editMenu->addSeparator();
    editMenu->addAction(deleteItems);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(this->width() - 10, this->height() - 15);
    model = new Model();
    model->loadTest(scene);

/*  COLOR COMBO */
    QPixmap px(15,15);
    px.fill(QColor(Qt::white));
    QIcon icon(px);
    ui->colorCombo->addItem(icon, "White");

    px.fill(QColor(Qt::black));
    icon.addPixmap(px);
    ui->colorCombo->addItem(icon, "Black");

    px.fill(QColor(Qt::gray));
    icon.addPixmap(px);
    ui->colorCombo->addItem(icon, "Gray");

    px.fill(QColor(Qt::red));
    icon.addPixmap(px);
    ui->colorCombo->addItem(icon, "Red");

    px.fill(QColor(Qt::green));
    icon.addPixmap(px);
    ui->colorCombo->addItem(icon, "Green");

    px.fill(QColor(Qt::blue));
    icon.addPixmap(px);
    ui->colorCombo->addItem(icon, "Blue");

    px.fill(QColor(Qt::yellow));
    icon.addPixmap(px);
    ui->colorCombo->addItem(icon, "Yellow");

/*  ToolBox */

    updateScene();

    undoAction = model->undoStack()->createUndoAction(model, tr("&Undo"));
    redoAction = model->undoStack()->createRedoAction(model, tr("&Redo"));
    undoAction->setShortcut(QKeySequence(tr("Ctrl+Z")));
    redoAction->setShortcut(QKeySequence(tr("Ctrl+Y")));

   /*
    QAction *undoAction = model->m_undoGroup->createUndoAction(this);
    QAction *redoAction = model->m_undoGroup->createRedoAction(this);
    undoAction->setShortcut(QKeySequence(tr("Ctrl+Z")));
    redoAction->setShortcut(QKeySequence(tr("Ctrl+Y")));
    */

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

    //m_undoGroup->setActiveStack(m_undoStack);
    for(auto item : model->getNodes())
    {
         scene->addItem(item.second);
         item.second->setScene(scene);
    }

    for(auto item : model->getEdges())
    {
         scene->addItem(item.second);
    }
}

void MainWindow::addNewNode()
{
   qDebug() << "hello from addNewNode";
   Node *node = model->addNode();
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

void MainWindow::newWorkspace()
{
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    delete model;
    model = new Model();
}

void MainWindow::openExistingWorkspace()
{

}

void MainWindow::saveWorkspace()
{

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

void MainWindow::addNewItem()
{
    //add new item implementace
    return addNewNode();
}

void MainWindow::addNewConnection()
{
    //add new connection implementace
}

void MainWindow::addText()
{
    //add text implementace
}

void MainWindow::on_redoButton_clicked()
{
    //redo implementace
    if(model->undoStack()->canRedo()){
        model->undoStack()->redo();
    }
    else{
        qDebug() << "Nothing to redo here";
    }
}

void MainWindow::on_undoButton_clicked()
{
    //undo implementace
    if(model->undoStack()->canUndo()){
        model->undoStack()->undo();
    }
    else{
        qDebug() << "Nothing to undo here";
    }
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    double newScale = arg1.left(arg1.indexOf(tr("%"))).toDouble()/100.0;
    QMatrix oldMatrix = this->ui->graphicsView->matrix();
    this->ui->graphicsView->resetMatrix();
    this->ui->graphicsView->translate(oldMatrix.dx(),oldMatrix.dy());
    this->ui->graphicsView->scale(newScale, newScale);
}

void MainWindow::on_colorCombo_currentTextChanged(const QString &arg1)
{
    // implementacia zmeny farby objektu!!!!    
}
