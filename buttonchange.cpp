#include "buttonchange.h"
#include "ui_buttonchange.h"

buttonChange::buttonChange(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::buttonChange)
{
    ui->setupUi(this);
}

buttonChange::~buttonChange()
{
    delete ui;
}
