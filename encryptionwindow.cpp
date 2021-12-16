#include "encryptionwindow.h"
#include "ui_encryptionwindow.h"

EncryptionWindow::EncryptionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EncryptionWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Encryption");
}

EncryptionWindow::~EncryptionWindow()
{
    delete ui;
}

void EncryptionWindow::on_toEncrypt_clicked()
{
    if (ui->key->text().isEmpty())
    {
        QMessageBox::warning(this, "Wrong key input", "Please, enter the key");
        return;
    }
    if (ui->textToEncrypt->toPlainText().isEmpty())
    {
        QMessageBox::warning(this, "Wrong input", "Please, enter the text");
        return;
    }

    Encryption cipher;
    QString key = ui->key->text();
    QString input = ui->textToEncrypt->toPlainText();
    QString output = nullptr;

    ui->label->setText(QString::number(input.length()));

    switch (ui->listOfCiphers->currentIndex())
    {
    case 0: output = cipher.AtbashCipher(input); break;
    case 1: output = cipher.ROT13(input); break;
    case 2: output = cipher.CaesarCipher(key, input); break;
    case 3: output = cipher.AffiliateCipher(key, input); break;
    case 4: output = cipher.BaconianCipher(input); break;
    case 5: output = cipher.SimpleReplacementCipher(key, input); break;
    case 6: output = cipher.PolibiyaCipher(key, input); break;
    case 7: output = cipher.SwapCipher(key, input); break;
    case 8: output = cipher.VigeneraCipher(key, input); break;
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
