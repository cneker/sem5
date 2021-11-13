#ifndef CD_H
#define CD_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Cd;
}

class Cd : public QDialog
{
    Q_OBJECT

public:
    explicit Cd(QWidget *parent = nullptr);
    ~Cd();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Cd *ui;
};

#endif // CD_H
