#include "garaj.h"
#include "ui_garaj.h"

Garaj::Garaj(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Garaj)
{
    ui->setupUi(this);

    SetConnection();
    SetDrivers();
    SetCars();
    SetFuels();
    updel = new UpdateDelete(this->drivers, this->fuels);
    connect(this, SIGNAL(sendData(Shipping*)), updel, SLOT(recieveData(Shipping*)));
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Id" << "Car" << "Driver" << "Fuel" << "Mialege" << "Date");
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->setColumnWidth(0, 50);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    SetTableItems();
}

Garaj::~Garaj()
{
    delete ui;
}
//add window
void Garaj::on_pushButton_clicked()
{
    Add * addWindow = new Add();
    addWindow->show();
}

//vodili
void Garaj::on_pushButton_2_clicked()
{
    QTableWidget *table = new QTableWidget();
    table->setColumnCount(3);
    table->setShowGrid(true);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setHorizontalHeaderLabels(QStringList() << "Name" << "Surname" << "Birthdate");
    table->resize(355, 300);
    table->setColumnWidth(0, 50);

    int count = 0;
    for(Driver driver : this->drivers) {
        table->insertRow(count);
        table->setItem(count, 0, new QTableWidgetItem(QString::fromStdString(driver.name)));
        table->setItem(count, 1, new QTableWidgetItem(QString::fromStdString(driver.surname)));
        table->setItem(count, 2, new QTableWidgetItem(QString::fromStdString(driver.birthdate)));
        count++;
    }
    table->show();
}

//korchi
void Garaj::on_pushButton_3_clicked()
{
    QTableWidget *table = new QTableWidget();
    table->setColumnCount(2);
    table->setShowGrid(true);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setHorizontalHeaderLabels(QStringList() << "Number" << "Brand");
    table->resize(205, 300);
    int count = 0;
    for(Car car : this->cars) {
        table->insertRow(count);
        table->setItem(count, 0, new QTableWidgetItem(QString::fromStdString(car.number)));
        table->setItem(count, 1, new QTableWidgetItem(QString::fromStdString(car.brand)));
        count++;
    }
    table->show();
}

//solyara
void Garaj::on_pushButton_4_clicked()
{
    QTableWidget *table = new QTableWidget();
    table->setColumnCount(2);
    table->setShowGrid(true);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setHorizontalHeaderLabels(QStringList() << "Id" << "Brand");
    table->resize(255, 300);
    table->setColumnWidth(0, 50);

    int count = 0;
    for(Fuel fuel : this->fuels) {
        table->insertRow(count);
        table->setItem(count, 0, new QTableWidgetItem(QString::number(fuel.id)));
        table->setItem(count, 1, new QTableWidgetItem(QString::fromStdString(fuel.brand)));
        count++;
    }
    table->show();
}

void Garaj::on_tableWidget_cellDoubleClicked(int row, int column)
{
    int id, driverId, fuelId, mialege;
    string carNumber, date;

    id = ui->tableWidget->item(row, 0)->text().toInt();
    carNumber = ui->tableWidget->item(row, 1)->text().toStdString();
    driverId = ui->tableWidget->item(row, 2)->text().toInt();
    fuelId = ui->tableWidget->item(row, 3)->text().toInt();
    mialege = ui->tableWidget->item(row, 4)->text().toInt();
    date = ui->tableWidget->item(row, 5)->text().toStdString();

    QString str = "SELECT Brand FROM Car WHERE Number = '%1'";
    str = str.arg(QString::fromStdString(carNumber));
    QSqlQuery query;
    query.exec(str);
    QSqlRecord rec;
    rec = query.record();
    query.next();
    string brand = query.value(rec.indexOf("Brand")).toString().toStdString();
    Car *car = new Car(carNumber, brand);

    str = "SELECT Brand FROM Fuel WHERE Id = '%1'";
    str = str.arg(QString::number(fuelId));
    query.exec(str);
    rec = query.record();
    query.next();
    brand = query.value(rec.indexOf("Brand")).toString().toStdString();
    Fuel *fuel = new Fuel(fuelId, brand);

    str = "SELECT * FROM Driver WHERE Id = '%1'";
    str = str.arg(QString::number(driverId));
    query.exec(str);
    rec = query.record();
    query.next();
    string name = query.value(rec.indexOf("Name")).toString().toStdString();
    string surname = query.value(rec.indexOf("Surname")).toString().toStdString();
    string birthdate = query.value(rec.indexOf("Birthdate")).toString().toStdString();
    Driver *driver = new Driver(driverId, name, surname, birthdate);

    Shipping *shipping = new Shipping(id, car, driver, fuel, mialege, date);

    emit sendData(shipping);
    updel->show();
}

//perevozki
void Garaj::SetTableItems()
{
    if(sbd.open()) {
        QString str = "SELECT * FROM Shipping";
        QSqlQuery query;
        bool b = query.exec(str);
        if(!b)
            qDebug() << query.lastError();
        else {
            QSqlRecord rec = query.record();
            int count = 0;
            while(query.next()) {
                int id = query.value(rec.indexOf("Id")).toInt();
                QString car = query.value(rec.indexOf("Car")).toString();
                int driver = query.value(rec.indexOf("Driver")).toInt();
                int fuel = query.value(rec.indexOf("Fuel")).toInt();
                int mialege = query.value(rec.indexOf("Mialege")).toInt();
                QString date = query.value(rec.indexOf("Date")).toString();

                ui->tableWidget->insertRow(count);

                ui->tableWidget->setItem(count, 0, new QTableWidgetItem(QString::number(id)));
                ui->tableWidget->setItem(count, 1, new QTableWidgetItem(car));
                ui->tableWidget->setItem(count, 2, new QTableWidgetItem(QString::number(driver)));
                ui->tableWidget->setItem(count, 3, new QTableWidgetItem(QString::number(fuel)));
                ui->tableWidget->setItem(count, 4, new QTableWidgetItem(QString::number(mialege)));
                ui->tableWidget->setItem(count, 5, new QTableWidgetItem(date));
                count++;
            }
        }
    }
}

void Garaj::SetConnection()
{
    sbd = QSqlDatabase::addDatabase("QSQLITE");
    sbd.setDatabaseName("D:\\SQLiteManager\\lab07.sqlite");
    if(!sbd.open()){
        qDebug() << sbd.lastError().text();
    }
}

//update
void Garaj::on_pushButton_6_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->model()->removeRows(0, ui->tableWidget->rowCount());
    SetTableItems();
}

void Garaj::SetDrivers()
{
    drivers.clear();
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
            drivers.push_back(driver);
        }
    }
}

void Garaj::SetCars()
{
    cars.clear();
    QString str = "SELECT * FROM Car";

    QSqlQuery query;
    bool b = query.exec(str);
    if(!b)
        qDebug() << query.lastError();
    else {
        QSqlRecord rec = query.record();
        while(query.next()) {
            QString number = query.value(rec.indexOf("Number")).toString();
            QString brand = query.value(rec.indexOf("Brand")).toString();

            Car car(number.toStdString(), brand.toStdString());
            cars.push_back(car);
        }
    }
}

void Garaj::SetFuels()
{
    fuels.clear();
    QString str = "SELECT * FROM Fuel";

    QSqlQuery query;
    bool b = query.exec(str);
    if(!b)
        qDebug() << query.lastError();
    else {
        QSqlRecord rec = query.record();
        while(query.next()) {
            int id = query.value(rec.indexOf("Id")).toInt();
            QString brand = query.value(rec.indexOf("Brand")).toString();

            Fuel fuel(id, brand.toStdString());
            fuels.push_back(fuel);
        }
    }
}
