#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QFontDialog>
#include <QSettings>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent, const QString &fileName)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionCopy->setEnabled(false);
    ui->actionPaste->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);

    QFont font = QSettings(this).value("VIEWF").value<QFont>();
    ui->textEdit->setFont(font);

    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified()));

    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionCut, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    connect(ui->actionCopy, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    connect(ui->actionPaste, SIGNAL(triggered()), ui->textEdit, SLOT(paste()));
    connect(ui->actionUndo, SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered()), ui->textEdit, SLOT(redo()));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(SetEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(SetEnabled(bool)));
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(SetEnabled(bool)));
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(SetEnabled(bool)));

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(saveFileAs()));
    //setAttribute(Qt::WA_DeleteOnClose);

    loadFile(fileName);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    MainWindow *editor = new MainWindow();
    editor->show();
}

void MainWindow::documentModified() {
    if (!isWindowModified())
        setWindowTitle(QString(windowTitle() + "*"));
    setWindowModified(true);
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if (isWindowModified()){
        switch(QMessageBox::warning(this,
                                    "Document Modified",
                                    "The document has been modified, do you want to close it? You will lose all your changes.",
                                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Close)){
        case(QMessageBox::Yes):
            saveFile();
            e->accept();
            break;
        case(QMessageBox::No):
            e->accept();
            break;
        case(QMessageBox::Close):
            e->ignore();
            break;
        }
    }
    else {
        e->accept();
    }
}

void MainWindow::on_actionSelectFont_triggered()
{
    bool checked = false;
    QFont font = QFontDialog::getFont(&checked, ui->textEdit->font());
    if (checked) {
        ui->textEdit->setFont(font);
        QSettings settings(this);
        settings.setValue("VIEWF", font); //sho eta
    }
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "you are awesome");
}

void MainWindow::loadFile(const QString &fileName)
{
    if (fileName.isEmpty()) {
        setFileName(fileName);
        return;
    }
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        ui->textEdit->setText(stream.readAll());
        file.close();
        setFileName(fileName);
        setWindowModified(false);
    }
    else {
        QMessageBox::warning(this, "Error", "File is not found.");
        setFileName(QString());
    }
}

void MainWindow::setFileName(const QString &fileName)
{
    m_fileName = fileName;
    setWindowTitle(QString("%1[*] - %2")
                   .arg(m_fileName.isNull()?"untitled":QFileInfo(m_fileName).fileName())
                   .arg(QApplication::applicationName()));
}
void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
    "Open document", QDir::currentPath(), "Text documents (*.txt)");
    if (fileName.isNull()) return;
    if (m_fileName.isNull() && !isWindowModified()) loadFile(fileName);
    else {
        MainWindow *window = new MainWindow(this, fileName);
        window->show();
    }
}

bool MainWindow::saveFileAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save document",
    m_fileName.isNull()?QDir::currentPath():m_fileName, "Text documents (*.txt)");
    if (fileName.isNull()) return false;
    setFileName(fileName);
    return saveFile();
}

bool MainWindow::saveFile()
{
    if (m_fileName.isNull()) return saveFileAs();
    QFile file(m_fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
       QTextStream stream(&file);
       stream << ui->textEdit->toPlainText();
       file.close();
       setWindowModified(false);
       return true;
    }
    else {
        QMessageBox::warning(this, "Error", "File is not found.");
        setFileName(QString());
        return false;
    }
}
