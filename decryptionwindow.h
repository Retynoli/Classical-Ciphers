#ifndef DECRYPTIONWINDOW_H
#define DECRYPTIONWINDOW_H

#include <QWidget>
#include "decryption.h"

namespace Ui {
class DecryptionWindow;
}

class DecryptionWindow : public QWidget
{
    Q_OBJECT
    QString output = nullptr;


public:
    explicit DecryptionWindow(QWidget *parent = nullptr);
    ~DecryptionWindow();

private slots:
    void on_toDecrypt_clicked();

    void on_aEdit_editingFinished();
    void on_bEdit_editingFinished();
    void on_cEdit_editingFinished();
    void on_dEdit_editingFinished();
    void on_eEdit_editingFinished();
    void on_fEdit_editingFinished();
    void on_gEdit_editingFinished();
    void on_hEdit_editingFinished();
    void on_iEdit_editingFinished();
    void on_jEdit_editingFinished();
    void on_kEdit_editingFinished();
    void on_lEdit_editingFinished();
    void on_mEdit_editingFinished();
    void on_nEdit_editingFinished();
    void on_oEdit_editingFinished();
    void on_pEdit_editingFinished();
    void on_qEdit_editingFinished();
    void on_rEdit_editingFinished();
    void on_sEdit_editingFinished();
    void on_tEdit_editingFinished();
    void on_uEdit_editingFinished();
    void on_vEdit_editingFinished();
    void on_wEdit_editingFinished();
    void on_xEdit_editingFinished();
    void on_yEdit_editingFinished();
    void on_zEdit_editingFinished();

private:
    Ui::DecryptionWindow *ui;
};

#endif // DECRYPTIONWINDOW_H
