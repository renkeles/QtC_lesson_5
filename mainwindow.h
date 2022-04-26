#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aboutprogram.h"
#include "buttonchange.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_triggered();

    void on_openReadOnly_triggered();

    void on_save_triggered();

    void on_exit_triggered();

    void on_create_triggered();

    void on_aboutProgram_triggered();

    void on_buttons_triggered();

    void on_treeViewShow_triggered();

private:
    Ui::MainWindow *ui;
    aboutProgram *aboutPr;
    buttonChange *btnCh;

};
#endif // MAINWINDOW_H
