#include "add.h"
#include "ui_add.h"

Add::Add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);

    set_drivers_combobox();
    set_fuel_combobox();
}

Add::~Add()
{
    delete ui;
}

//add
void Add::on_pushButton_2_clicked()
{
    QString string = "INSERT INTO Shipping (Car, Driver, Fuel, Mialege, Date) VALUES ('%1', '%2', '%3', '%4', '%5');";
    QString car = ui->comboBox_2->currentText();
    int driver = ui->comboBox->currentText().toInt();
    QString fuel = ui->comboBox_3->currentText();
    int mialege = ui->lineEdit_4->text().toInt();
    QString date = ui->lineEdit_5->text();
    int fuelId;
    QString str = "SELECT Id FROM Fuel WHERE Brand = '%1'";
    str = str.arg(fuel);
    QSqlQuery query;
    bool b = query.exec(str);
    QSqlRecord rec = query.record();
    query.next();
    fuelId = query.value(rec.indexOf("Id")).toInt();


    string = string.arg(car).arg(driver).arg(fuelId).arg(mialege).arg(date);
    b = query.exec(string);
    if(!b)
        qDebug() << query.lastError();
    this->close();
}

void Add::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->comboBox_2->clear();

    for(Driver driver : drivers)
    {
        if(driver.id == arg1.toInt())
        {
                for(Car car : driver.cars)
                {
                    ui->comboBox_2->addItem(QString::fromStdString(car.number));
                }
        }
    }
}

void Add::set_drivers_combobox()
{
        QString str = "SELECT * FROM Driver";
        QSqlQuery query;
        bool b = query.exec(str);
        if(!b)
            qDebug() << query.lastError();
        else {
            QSqlRecord rec = query.record();
            while(query.next()) {
                int id = query.value(rec.indexOf("Id")).toInt();
                QString name = query.value(rec.indexOf("Name")).toString();
                QString surname = query.value(rec.indexOf("Surname")).toString();
                QString birthdate = query.value(rec.indexOf("Birthdate")).toString();

                Driver driver(id, name.toStdString(), surname.toStdString(), birthdate.toStdString());
                driver.set_cars();

                drivers.push_back(driver);
                ui->comboBox->addItem(QString::number(driver.id));
            }
        }
}

void Add::set_fuel_combobox()
{
    QString str = "SELECT * FROM Fuel";
    QSqlQuery query;
    bool b = query.exec(str);
    if(!b)
        qDebug() << query.lastError();
    else {
        QSqlRecord rec = query.record();
        while(query.next()) {
            int id = query.value(rec.indexOf("Id")).toInt();
            QString name = query.value(rec.indexOf("Brand")).toString();

            Fuel fuel(id, name.toStdString());
            fuels.push_back(fuel);

            ui->comboBox_3->addItem(QString::fromStdString(fuel.brand));
        }
    }
}
//close button
void Add::on_pushButton_clicked()
{
    this->close();
}
