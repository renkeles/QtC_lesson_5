#ifndef BUTTONCHANGE_H
#define BUTTONCHANGE_H

#include <QDialog>

namespace Ui {
class buttonChange;
}

class buttonChange : public QDialog
{
    Q_OBJECT

public:
    explicit buttonChange(QDialog *parent = nullptr);
    ~buttonChange();

private:
    Ui::buttonChange *ui;
};

#endif // BUTTONCHANGE_H
