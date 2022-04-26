#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QTextStream"
#include "buttonchange.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowIcon(QIcon(":/image/png/2944881_bug_seo_user_virus_icon.png"));
    ui->setupUi(this);
    aboutPr = new aboutProgram;
    btnCh = new buttonChange;

    aboutPr->setModal(true);
    btnCh->setModal(true);

    ui->treeViewShow->setChecked(true);

    //Templates Qt Style Sheets https://qss-stock.devsecstudio.com/

    QFile styleSheetFile(":/style/qss/Integrid.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    qApp->setStyleSheet(styleSheet);

    setDefaultLanguage();
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


void MainWindow::on_dark_triggered()
{
    QFile styleSheetFile(":/style/qss/Combinear.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    qApp->setStyleSheet(styleSheet);
}


void MainWindow::on_light_triggered()
{
    QFile styleSheetFile(":/style/qss/Integrid.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    qApp->setStyleSheet(styleSheet);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(btnCh->getCheckOpen())
    {
        if (e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_O)
        {
            MainWindow::on_open_triggered();
        }
    }else if(!btnCh->getCheckOpen())
    {
        if (e->key() == Qt::Key_F3)
        {
            MainWindow::on_open_triggered();
        }
    }

    if(btnCh->getCheckNew())
    {
        if (e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_N)
        {
            ui->MainPlainTextEdit->clear();
            ui->MainPlainTextEdit->setReadOnly(false);
        }
    }else if(!btnCh->getCheckNew())
    {
        if (e->key() == Qt::Key_F2)
        {
            ui->MainPlainTextEdit->clear();
            ui->MainPlainTextEdit->setReadOnly(false);
        }
    }

    if(btnCh->getCheckSave())
    {
        if (e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_S)
        {
            MainWindow::on_save_triggered();
        }
    }else if(!btnCh->getCheckSave())
    {
        if (e->key() == Qt::Key_F6)
        {
            MainWindow::on_save_triggered();
        }
    }

    if(btnCh->getCheckQuit())
    {
        if (e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_Q)
        {
            exit(0);
            //qApp->quit();
        }
    }else if(!btnCh->getCheckQuit())
    {
        if (e->key() == Qt::Key_F12)
        {
            exit(0);
        }
    }
}


void MainWindow::setDefaultLanguage()
{
    this->setWindowTitle(tr("Блокнот"));

    ui->file->setTitle(tr("Файл"));
        ui->create->setText(tr("Создать"));
        ui->open->setText(tr("Открыть"));
        ui->openReadOnly->setText(tr("Открыть для чтения"));
        ui->save->setText(tr("Сохранить"));
        ui->exit->setText(tr("Выход"));

    ui->view->setTitle(tr("Вид"));
        ui->treeViewShow->setText(tr("Проводник"));

    ui->options->setTitle(tr("Настройки"));
        ui->control->setTitle(tr("Управление"));
            ui->buttons->setText(tr("Кнопки"));
        ui->language->setTitle(tr("Язык"));
            ui->russian->setText(tr("Русский"));
            ui->english->setText(tr("English"));
        ui->theme->setTitle(tr("Темы"));
            ui->light->setText((tr("Светлая")));
            ui->dark->setText(tr("Тёмная"));

    ui->faq->setTitle(tr("Справка"));
        ui->aboutProgram->setText(tr("О программе"));
}

void MainWindow::on_russian_triggered()
{
    qtranslator.load(":/language/qm/QtLanguage_ru.qm");
    qApp->installTranslator(&qtranslator);
    btnCh->setLanguage(0);
    aboutPr->setLanguage(0);
    ui->retranslateUi(this);
}


void MainWindow::on_english_triggered()
{
    qtranslator.load(":/language/qm/QtLanguage_en.qm");
    qApp->installTranslator(&qtranslator);
    btnCh->setLanguage(1);
    aboutPr->setLanguage(1);
    ui->retranslateUi(this);
}




