#include "aboutprogram.h"
#include "ui_aboutprogram.h"

aboutProgram::aboutProgram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutProgram)
{
    ui->setupUi(this);
}

aboutProgram::~aboutProgram()
{
    delete ui;
}
