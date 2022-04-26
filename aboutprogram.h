#ifndef ABOUTPROGRAM_H
#define ABOUTPROGRAM_H

#include <QDialog>
#include <QTranslator>

namespace Ui {
class aboutProgram;
}

class aboutProgram : public QDialog
{
    Q_OBJECT

public:
    explicit aboutProgram(QDialog *parent = nullptr);
    ~aboutProgram();

    void setLanguage(int codeLanguage);

private:
    Ui::aboutProgram *ui;
    QTranslator qtranslator;
    void setDefaultLanguage();
};

#endif // ABOUTPROGRAM_H
