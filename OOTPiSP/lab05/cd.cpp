#include "cd.h"
#include "ui_cd.h"

Cd::Cd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cd)
{
    ui->setupUi(this);
}

Cd::~Cd()
{
    delete ui;
}

void Cd::on_buttonBox_accepted()
{
    QString title = ui->lineEdit->text();
    int year = ui->lineEdit_2->text().toInt();
    QString name = ui->lineEdit_3->text();

    QString str = "SELECT id FROM artist WHERE name = '%1';";
    str = str.arg(name);

    QSqlQuery query;
    bool b = query.exec(str);
    if(!b)
        qDebug() << query.lastError();
    else{
        QSqlRecord rec = query.record();
        int artistid = 0;
        if(query.next()){
            artistid = query.value(rec.indexOf("id")).toInt();
            str = "INSERT INTO cd (artistid, title, year) VALUES ('%1', '%2', '%3');";
            str = str.arg(artistid).arg(title).arg(year);
            b = query.exec(str);
            if(!b)
                qDebug() << query.lastError();
        }
    }
}

