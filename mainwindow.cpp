#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->slider, SIGNAL(valueChanged(int)),
            this, SLOT(setNumber()));
    connect(ui->dial, SIGNAL(valueChanged(int)),
            this, SLOT(setNumber()));
    connect(ui->sliderButton, SIGNAL(toggled(bool)),
            this, SLOT(setNumber()));
    connect(ui->dialButton, SIGNAL(toggled(bool)),
            this, SLOT(setNumber()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setNumber()
{
    if(ui->sliderButton->isChecked()) {
        ui->slider->setDisabled(false);
        ui->number->display(ui->slider->value());
    }
    if(ui->dialButton->isChecked()) {
        ui->dial->setDisabled(false);
        ui->number->display(ui->dial->value());
    }
}

void MainWindow::on_dial_valueChanged(int value)
{

}
