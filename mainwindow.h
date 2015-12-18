#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QToolBox>
#include <QToolButton>
#include <QComboBox>
#include <QButtonGroup>
#include "model.h"
#include "node.h"

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

/*private slots:
    void bringToFront();
    void sendToBack();
*/
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    Model *model;

    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionExport;
    QAction *actionQuit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *deleteItems;
    //QAction *addNew;
    QAction *ADDitemAction;
    QAction *ADDconnectionAction;
    QAction *ADDtextAction;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *insertMenu;

    //QComboBox *sceneScaleCombo;

protected slots:
    void addNewNode();
    void deleteSceneItems();
    void resizeEvent(QResizeEvent* event);

private slots:
    void QuitApp();
    //void newWorkspace();
    //void openExistingWorkspace();
    //void saveWorkspace();
    void addNewItem();
    void addNewConnection();
    void addText();
    void exportWorkspace();
    void on_redoButton_clicked();
    void on_undoButton_clicked();
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void on_colorCombo_currentTextChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
