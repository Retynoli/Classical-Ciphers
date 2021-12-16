#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Hello");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Encrypt_clicked()
{
    EncryptionWindow * encryption = new EncryptionWindow;
    encryption->show();
//    this->hide();
}

void MainWindow::on_Decrypt_clicked()
{
    DecryptionWindow * decryption = new DecryptionWindow;
    decryption->show();
//    this->hide();
}
