#include "artist.h"
#include "ui_artist.h"

Artist::Artist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Artist)
{
    ui->setupUi(this);
}

Artist::~Artist()
{
    delete ui;
}

void Artist::on_buttonBox_accepted()
{
    QString string = "INSERT INTO artist (name, country) VALUES ('%1', '%2');";
    QString name = ui->lineEdit->text();
    QString country = ui->lineEdit_2->text();
    string = string.arg(name).arg(country);
    QSqlQuery query;
    bool b = query.exec(string);
    if(!b)
        qDebug() << query.lastError();
}

