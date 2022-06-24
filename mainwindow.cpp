#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

int count=0;
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

void MainWindow::on_pushButton_clicked()
{
    QString str=ui->lineEdit->text()+" "+ui->lineEdit_2->text();
    ui->listWidget->addItem(str);
    count++;
    ui->label_4->clear();
    ui->label_4->setNum(count);
}

void MainWindow::on_pushButton_2_clicked()
{
    int selectedRows;
    foreach (QModelIndex mi, ui->listWidget->selectionModel()->selectedIndexes()){
        selectedRows=mi.row();
    }
    ui->listWidget->takeItem(selectedRows);
    count--;
    ui->label_4->clear();
    ui->label_4->setNum(count);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString str=ui->lineEdit->text()+" "+ui->lineEdit_2->text();
    QList<QListWidgetItem *> list;
    list.append(ui->listWidget->findItems(str, Qt::MatchContains));
    if (list.count()!=0) {
    ui->listWidget_2->addItem(list.at(0)->text());
    list.clear();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    Dialog dialog;
    dialog.show();
    dialog.exec();
    QString str3=dialog.loginpass;
    QList<QListWidgetItem *> list;
    list.append(ui->listWidget->findItems(str3, Qt::MatchContains));
    if (list.count()!=0) {
    ui->listWidget_3->addItem(list.at(0)->text());
    list.clear();
    ui->label_5->setText("Well");
    }
    else {
        ui->label_5->setText("Not found");
        ui->listWidget_4->addItem(str3);
    }
}
