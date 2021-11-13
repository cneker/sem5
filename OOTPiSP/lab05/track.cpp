#include "track.h"
#include "ui_track.h"

Track::Track(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Track)
{
    ui->setupUi(this);
}

Track::~Track()
{
    delete ui;
}

void Track::on_buttonBox_accepted()
{
    QString cd_name = ui->lineEdit->text();
    QString title = ui->lineEdit_2->text();
    int duration = ui->lineEdit_3->text().toInt();
    int number = ui->lineEdit_4->text().toInt();

    QString str = "SELECT id FROM cd WHERE title = '%1';";
    str = str.arg(cd_name);

    QSqlQuery query;
    bool b = query.exec(str);
    if(!b)
        qDebug() << query.lastError();
    else{
        QSqlRecord rec = query.record();
        int cd_id = 0;
        if(query.next()){
            cd_id = query.value(rec.indexOf("id")).toInt();
            str = "SELECT id FROM track WHERE number = '%1' AND cdid = '%2';";
            str = str.arg(number).arg(cd_id);
            query.exec(str);
            if(!query.next()){
                str = "INSERT INTO track (cdid, number, title, duration) VALUES ('%1', '%2', '%3', '%4');";
                str = str.arg(cd_id).arg(number).arg(title).arg(duration);
                b = query.exec(str);
                if(!b)
                    qDebug() << query.lastError();
            }
        }
    }
}
