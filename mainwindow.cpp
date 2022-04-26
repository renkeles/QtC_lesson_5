#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QTextStream"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    aboutPr = new aboutProgram;
    btnCh = new buttonChange;

    aboutPr->setModal(true);
    btnCh->setModal(true);

    ui->treeViewShow->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete aboutPr;
    delete btnCh;
}


void MainWindow::on_open_triggered()
{
    QString filename = QFileDialog::getOpenFileName();
    if(filename.length())
    {
        QFile file(filename);
        if(file.open(QFile::ReadOnly | QFile::ExistingOnly))
        {
            QTextStream stream(&file);
            ui->MainPlainTextEdit->setPlainText(stream.readAll());
            ui->MainPlainTextEdit->setReadOnly(false);
            file.close();
        }
    }
}


void MainWindow::on_openReadOnly_triggered()
{
    QString filename = QFileDialog::getOpenFileName();
    if(filename.length())
    {
        QFile file(filename);
        if(file.open(QFile::ReadOnly))
        {
            QTextStream stream(&file);
            ui->MainPlainTextEdit->setPlainText(stream.readAll());
            ui->MainPlainTextEdit->setReadOnly(true);
            file.close();
        }
    }
}


void MainWindow::on_save_triggered()
{
    QString filename = QFileDialog::getSaveFileName();
        if(filename.length())
        {
            QFile file(filename);
            if(file.open(QFile::WriteOnly | QFile::NewOnly))
            {
                QTextStream stream(&file);
                stream << ui->MainPlainTextEdit->toPlainText();
                file.close();
            }
        }
}


void MainWindow::on_exit_triggered()
{
    exit(0);
}


void MainWindow::on_create_triggered()
{
    ui->MainPlainTextEdit->clear();
    ui->MainPlainTextEdit->setReadOnly(false);
}


void MainWindow::on_aboutProgram_triggered()
{
    aboutPr->show();
}


void MainWindow::on_buttons_triggered()
{
    btnCh->show();
}


void MainWindow::on_treeViewShow_triggered()
{
    if(!ui->treeViewShow->isChecked())
    {
        ui->treeFileView->hide();
    }else
    {
        ui->treeFileView->show();
    }
}

