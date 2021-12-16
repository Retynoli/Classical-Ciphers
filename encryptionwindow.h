#ifndef ENCRYPTIONWINDOW_H
#define ENCRYPTIONWINDOW_H

#include <QWidget>
#include "encryption.h"

namespace Ui {
class EncryptionWindow;
}

class EncryptionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EncryptionWindow(QWidget *parent = nullptr);
    ~EncryptionWindow();

private slots:
    void on_toEncrypt_clicked();

private:
    Ui::EncryptionWindow *ui;
};

#endif // ENCRYPTIONWINDOW_H
