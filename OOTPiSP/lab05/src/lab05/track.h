#ifndef TRACK_H
#define TRACK_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Track;
}

class Track : public QDialog
{
    Q_OBJECT

public:
    explicit Track(QWidget *parent = nullptr);
    ~Track();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Track *ui;
};

#endif // TRACK_H
