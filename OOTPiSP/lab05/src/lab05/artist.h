#ifndef ARTIST_H
#define ARTIST_H

#include <QDialog>
#include <QtSql>
#include <mainwindow.h>

namespace Ui {
class Artist;
}

class Artist : public QDialog
{
    Q_OBJECT

public:
    explicit Artist(QWidget *parent = nullptr);
    ~Artist();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Artist *ui;
};

#endif // ARTIST_H
