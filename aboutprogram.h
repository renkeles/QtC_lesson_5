#ifndef ABOUTPROGRAM_H
#define ABOUTPROGRAM_H

#include <QDialog>

namespace Ui {
class aboutProgram;
}

class aboutProgram : public QDialog
{
    Q_OBJECT

public:
    explicit aboutProgram(QWidget *parent = nullptr);
    ~aboutProgram();

private:
    Ui::aboutProgram *ui;
};

#endif // ABOUTPROGRAM_H
