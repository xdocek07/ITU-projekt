#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workplace.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->workplace = new Workplace(this);
    ui->workplace->resize(300, 300);

}

MainWindow::~MainWindow()
{
    delete ui;
}
