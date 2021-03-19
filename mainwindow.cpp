#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rsa_encrypt.h"
#include <QDebug>
#include "rsa_decrypt.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click_encrypt()
{
    rsa_encrypt enc;
    this->result = enc.rsaEncrept(alphabet,ui->textEdit->toPlainText());
    if(result->value(0)!="-1")
    {
       setTextEditString();
       this->d = enc.getD();
       this->n = enc.getN();
    }
}

void MainWindow::click_decrypt()
{
     rsa_decrypt dec;
     decodString = dec.rsaDecrept(result,alphabet,d,n);
     ui->textEdit_3->setText(*decodString);
}

void MainWindow::setTextEditString()
{
    for(int i=0;i<result->length();i++)
    {
        ui->textEdit_2->append(result->value(i));
    }
}

