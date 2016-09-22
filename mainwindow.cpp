#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_filterBtn_clicked()
{
    QString input = ui->inputText->document()->toPlainText();

    QStringList keys = input.split(QRegExp("[\n ]"),QString::SkipEmptyParts);
    keys.removeDuplicates();
    ui->outputText->clear();
    foreach (QString key, keys) {
        ui->outputText->append(key);
    }

}
