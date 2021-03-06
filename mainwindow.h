#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "encryptionwindow.h"
#include "decryptionwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Encrypt_clicked();
    void on_Decrypt_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
