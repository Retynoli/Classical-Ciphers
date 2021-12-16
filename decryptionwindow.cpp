#include "decryptionwindow.h"
#include "ui_decryptionwindow.h"

DecryptionWindow::DecryptionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DecryptionWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Decryption");
}

DecryptionWindow::~DecryptionWindow()
{
    delete ui;
}

void DecryptionWindow::on_toDecrypt_clicked()
{
    if (ui->textToDecrypt->toPlainText().isEmpty())
    {
        QMessageBox::warning(this, "Wrong input", "Please, enter the text");
        return;
    }

    Decryption cipher;
    QString plainText = ui->textToDecrypt->toPlainText();

    switch (ui->listOfCiphers->currentIndex())
    {
    case 0: output = cipher.AtbashCipher(plainText); break;
    case 1: output = cipher.ROT13(plainText); break;
    case 2: output = cipher.CaesarCipher(plainText); break;
    case 3: output = cipher.AffiliateCipher(plainText); break;
    case 4: output = cipher.SimpleReplacementCipher(plainText); break;
    case 5: output = cipher.PolibiyaCipher(plainText); break;
    case 6: output = cipher.SwapCipher(plainText); break;
    case 7: output = cipher.VigeneraCipher(plainText); break;
    }

    ui->textBrowser->setText(output);

    ui->AFreq->setText(QString::number(output.count('A') * 100.0 / output.length()));
    ui->BFreq->setText(QString::number(output.count('B') * 100.0 / output.length()));
    ui->CFreq->setText(QString::number(output.count('C') * 100.0 / output.length()));
    ui->DFreq->setText(QString::number(output.count('D') * 100.0 / output.length()));
    ui->EFreq->setText(QString::number(output.count('E') * 100.0 / output.length()));
    ui->FFreq->setText(QString::number(output.count('F') * 100.0 / output.length()));
    ui->GFreq->setText(QString::number(output.count('G') * 100.0 / output.length()));
    ui->HFreq->setText(QString::number(output.count('H') * 100.0 / output.length()));
    ui->IFreq->setText(QString::number(output.count('I') * 100.0 / output.length()));
    ui->JFreq->setText(QString::number(output.count('J') * 100.0 / output.length()));
    ui->KFreq->setText(QString::number(output.count('K') * 100.0 / output.length()));
    ui->LFreq->setText(QString::number(output.count('L') * 100.0 / output.length()));
    ui->MFreq->setText(QString::number(output.count('M') * 100.0 / output.length()));
    ui->NFreq->setText(QString::number(output.count('N') * 100.0 / output.length()));
    ui->OFreq->setText(QString::number(output.count('O') * 100.0 / output.length()));
    ui->PFreq->setText(QString::number(output.count('P') * 100.0 / output.length()));
    ui->QFreq->setText(QString::number(output.count('Q') * 100.0 / output.length()));
    ui->RFreq->setText(QString::number(output.count('R') * 100.0 / output.length()));
    ui->SFreq->setText(QString::number(output.count('S') * 100.0 / output.length()));
    ui->TFreq->setText(QString::number(output.count('T') * 100.0 / output.length()));
    ui->UFreq->setText(QString::number(output.count('U') * 100.0 / output.length()));
    ui->VFreq->setText(QString::number(output.count('V') * 100.0 / output.length()));
    ui->WFreq->setText(QString::number(output.count('W') * 100.0 / output.length()));
    ui->XFreq->setText(QString::number(output.count('X') * 100.0 / output.length()));
    ui->YFreq->setText(QString::number(output.count('Y') * 100.0 / output.length()));
    ui->ZFreq->setText(QString::number(output.count('Z') * 100.0 / output.length()));
}

void DecryptionWindow::on_aEdit_editingFinished()
{
    output.replace('A', ui->aEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_bEdit_editingFinished()
{
    output.replace('B', ui->bEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_cEdit_editingFinished()
{
    output.replace('C', ui->cEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_dEdit_editingFinished()
{
    output.replace('D', ui->dEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_eEdit_editingFinished()
{
    output.replace('E', ui->eEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_fEdit_editingFinished()
{
    output.replace('F', ui->fEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_gEdit_editingFinished()
{
    output.replace('G', ui->gEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_hEdit_editingFinished()
{
    output.replace('H', ui->hEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_iEdit_editingFinished()
{
    output.replace('I', ui->iEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_jEdit_editingFinished()
{
    output.replace('J', ui->jEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_kEdit_editingFinished()
{
    output.replace('K', ui->kEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_lEdit_editingFinished()
{
    output.replace('L', ui->lEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_mEdit_editingFinished()
{
    output.replace('M', ui->mEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_nEdit_editingFinished()
{
    output.replace('N', ui->nEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_oEdit_editingFinished()
{
    output.replace('O', ui->oEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_pEdit_editingFinished()
{
    output.replace('P', ui->pEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_qEdit_editingFinished()
{
    output.replace('Q', ui->qEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_rEdit_editingFinished()
{
    output.replace('R', ui->rEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_sEdit_editingFinished()
{
    output.replace('S', ui->sEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_tEdit_editingFinished()
{
    output.replace('T', ui->tEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_uEdit_editingFinished()
{
    output.replace('U', ui->uEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_vEdit_editingFinished()
{
    output.replace('V', ui->vEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_wEdit_editingFinished()
{
    output.replace('W', ui->wEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_xEdit_editingFinished()
{
    output.replace('X', ui->xEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_yEdit_editingFinished()
{
    output.replace('Y', ui->yEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

void DecryptionWindow::on_zEdit_editingFinished()
{
    output.replace('Z', ui->zEdit->text().toUpper());
    ui->textBrowser->setText(output);
}

