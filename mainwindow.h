#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_choosePathButton_clicked();

    void on_recognizeButton_clicked();

private:
    QString pathToImage;
    QString pathToPython = "python";
    QString pathToProgram = "D:/Programming/SignRecognize/SignRecognize/main.py";
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
