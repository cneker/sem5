#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double x1 = 0;
    double x2 = 0;
    double y1 = 0;
    double y2 = 0;
    int r=3;
    double q = 0;
    double a = 0;

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event) override;
};
#endif // MAINWINDOW_H
