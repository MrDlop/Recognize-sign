#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QProcess>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_choosePathButton_clicked()
{
    QDir file = QFileDialog::getOpenFileName(nullptr, "Directory Dialog", "",
                     tr("Images (*.png *.PNG *.JPG *.jpe  *.jpeg *.jfif *.jpg *.JPE *.JPEG)"));
    this->pathToImage = file.path();
    ui->imageView->setPixmap(QPixmap(this->pathToImage));
}

void MainWindow::on_recognizeButton_clicked()
{
    QProcess p;
    QStringList params;
    params << pathToProgram;
    p.start(pathToPython, params);
    p.waitForFinished(-1);
    QString p_stdout = p.readAll();
    ui->typeOfSign->setText(p_stdout);
}
