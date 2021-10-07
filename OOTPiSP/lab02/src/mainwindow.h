#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, const QString &fileName = QString());
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *e);

private slots:
    void on_actionNew_triggered();
    void documentModified();

    void on_actionSelectFont_triggered();

    void on_actionAbout_triggered();

    void on_actionOpen_triggered();

    bool saveFile();
    bool saveFileAs();

private:
    Ui::MainWindow *ui;
    QString m_fileName;
    void loadFile(const QString &fileName);
    void setFileName(const QString &);
};
#endif // MAINWINDOW_H
