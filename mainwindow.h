#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "model.h"
#include "node.h"
#include <QUndoGroup>
#include "undo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateScene();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Model *model;
    Node *previous;
    QAction *undoAction;
    QAction *redoAction;
    //QUndoStack *m_undoStack;

protected slots:
    void addNewNode();
    void deleteSceneItems();
    void resizeEvent(QResizeEvent* event);
};

#endif // MAINWINDOW_H
