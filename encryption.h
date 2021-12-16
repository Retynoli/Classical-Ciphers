#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <QMessageBox>
#include <QVector>
#include <QString>
#include <QMap>

class Encryption
{
private:
    QString alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

public:
    Encryption();

    QString AtbashCipher(QString plainText);
    QString ROT13 (QString plainText);
    QString CaesarCipher(QString strkey, QString plainText);
    QString AffiliateCipher(QString key, QString plainText);
    QString BaconianCipher(QString plainText);
    QString SimpleReplacementCipher(QString keyAlphabet, QString plainText);
    QString PolibiyaCipher(QString key, QString plainText);
    QString SwapCipher(QString key, QString plainText);
    QString VigeneraCipher(QString key, QString plainText);
};

#endif // ENCRYPTION_H
