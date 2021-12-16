#include "encryption.h"

Encryption::Encryption()
{ }

QString Encryption::AtbashCipher(QString plainText) //Ready
{
    plainText = plainText.toUpper();

    QString output = nullptr;

    foreach (auto currentChar, plainText)
    {
        if (!currentChar.isLetter())
        {
            output += currentChar;
            continue;
        }

        int index = alphabet.indexOf(currentChar);
        if (index == -1)
        {
            QString description = "Invalid character in the text: ";
            QMessageBox::critical(nullptr, "Input error", description + currentChar);
            return nullptr;
        }

        output += alphabet[alphabet.length() - alphabet.indexOf(currentChar) - 1];
    }

    return output;
}

QString Encryption::ROT13(QString plainText) //Ready
{
    plainText = plainText.toUpper();

    QString output = nullptr;

    foreach (auto currentChar, plainText)
    {
        if (!currentChar.isLetter())
        {
            output += currentChar;
            continue;
        }

        int index = alphabet.indexOf(currentChar);
        if (index == -1)
        {
            QString description = "Invalid character in the text: ";
            QMessageBox::critical(nullptr, "Input error", description + currentChar);
            return nullptr;
        }

        output += alphabet[(index + 13) % alphabet.length()];
    }

    return output;
}

QString Encryption::CaesarCipher(QString strkey, QString plainText) //Ready
{
    foreach (auto currentChar, strkey)
        if (!currentChar.isDigit())
        {
            QString description = "Invalid character in the key: ";
            QMessageBox::critical(nullptr, "Input error", description + currentChar);
            return nullptr;
        }

    QString output = nullptr;

    int key = strkey.toInt();
    if (key == 0)
    {
        QMessageBox::critical(nullptr, "Key input error", "Please, enter the correct key");
        return nullptr;
    }

    foreach (auto currentChar, plainText)
    {
        if (!currentChar.isLetter())
        {
            output += currentChar;
            continue;
        }

        if (currentChar.isLower())
            currentChar = currentChar.toUpper();

        int index = alphabet.indexOf(currentChar);
        if (index == -1)
        {
            QString description = "Invalid character in the text: ";
            QMessageBox::critical(nullptr, "Input error", description + currentChar);
            return nullptr;
        }

        output += alphabet[(index + key) % alphabet.length()];
    }

    return output;
}

QString Encryption::AffiliateCipher(QString key, QString plainText) //Ready
{
    QString output = nullptr;
    int keyA = 0;
    int keyB = 0;
    int keyAmount = 0;

    for (int i = 0; i < key.length(); i++)
    {
        QString temp;
        while (!key[i].isSpace() && i < key.length())
        {
            if (!key[i].isDigit())
            {
                QMessageBox::critical(nullptr, "Key input error", "Invalid character in the key: " + key[i]);
                return nullptr;
            }
            temp += key[i++];
        }

        keyAmount++;

        if (keyAmount == 1)
        {
            keyA = temp.toInt();
            if (keyA == 0)
            {
                QMessageBox::critical(nullptr, "Key input error", "Invalid key input");
                return nullptr;
            }
        }
        else if (keyAmount == 2)
        {
            keyB = temp.toInt();
            if (keyB == 0)
            {
                QMessageBox::critical(nullptr, "Key input error", "Invalid key input");
                return nullptr;
            }
        }
        else if (keyAmount > 2)
        {
            QMessageBox::critical(nullptr, "Key input error", "Please, enter the correct key");
            return nullptr;
        }

        temp.clear();
    }

    if (keyAmount < 2)
    {
        QMessageBox::critical(nullptr, "Key input error", "Please, enter the correct key");
        return nullptr;
    }

    plainText = plainText.toUpper();

    foreach (auto currentChar, plainText)
    {
        if (!currentChar.isLetter())
        {
            output += currentChar;
            continue;
        }

        int index = alphabet.indexOf(currentChar);
        if (index == -1)
        {
            QString description = "Invalid character in the text: ";
            QMessageBox::critical(nullptr, "Input error", description + currentChar);
            return nullptr;
        }

        output += alphabet[(keyA * index + keyB) % alphabet.length()];
    }

    return output;
}

QString Encryption::BaconianCipher(QString plainText) //Ready
{
    plainText = plainText.toUpper();
    QString output = nullptr;
    QMap <QChar, QString> binAlphabet = {{'A', "00000"}, {'B', "00001"}, {'C', "00010"}, {'D', "00011"}, {'E', "00100"}, {'F', "00101"},
                                         {'G', "00110"}, {'H', "00111"}, {'I', "01000"}, {'J', "01001"}, {'K', "01010"}, {'L', "01011"},
                                         {'M', "01100"}, {'N', "01101"}, {'O', "01110"}, {'P', "01111"}, {'Q', "10000"}, {'R', "10001"},
                                         {'S', "10010"}, {'T', "10011"}, {'U', "10100"}, {'V', "10101"}, {'W', "10110"}, {'X', "10111"},
                                         {'Y', "11000"}, {'Z', "11001"}};

    foreach (auto currentChar, plainText)
    {
        if (!currentChar.isLetter())
            continue;

        QString value = binAlphabet.value(currentChar);

        if (value == nullptr)
        {
            QString description = "Invalid character in the text: ";
            QMessageBox::critical(nullptr, "Key input error", description + currentChar);
            return nullptr;
        }

        output += value;
    }

    return output;
}

QString Encryption::SimpleReplacementCipher(QString keyAlphabet, QString plainText) //Ready
{
    QString output = nullptr;

    foreach (auto currentChar, keyAlphabet)
    {
        if (!currentChar.isLetter())
        {
            QString description = "Invalid character in the key: ";
            QMessageBox::critical(nullptr, "Key input error", description + currentChar);
            return nullptr;
        }

        if (currentChar.isLower())
            currentChar = currentChar.toUpper();
    }

    foreach (auto currentChar, plainText)
    {
        if (!currentChar.isLetter())
        {
            output += currentChar;
            continue;
        }

        if (currentChar.isLower())
            currentChar = currentChar.toUpper();

        int index = alphabet.indexOf(currentChar);
        if (index == -1)
        {
            QString description = "Invalid character in the text: ";
            QMessageBox::critical(nullptr, "Input error", description + currentChar);
            return nullptr;
        }

        output += keyAlphabet[index % keyAlphabet.length()];
    }

    return output;
}

QString Encryption::PolibiyaCipher(QString key, QString plainText) //Ready
{    
    foreach (auto currentChar, key)
    {
        if (!currentChar.isLetter())
        {
            QString description = "Invalid character in the key: ";
            QMessageBox::critical(nullptr, "Key input error", description + currentChar);
            return nullptr;
        }
        else if (key.count(currentChar) > 1)
        {
            QString description = "Repeated character in the key: ";
            QMessageBox::critical(nullptr, "Key input error", description + currentChar);
            return nullptr;
        }
    }
    if (key.length() > 26)
    {
        QMessageBox::critical(nullptr, "Key input error", "Key is too long");
        return nullptr;
    }

    foreach (auto currentChar, plainText)
        if (!currentChar.isLetter())
            plainText.remove(currentChar);

    plainText = plainText.toUpper();
    plainText.replace('J', 'I');
    key = key.toUpper();
    key.remove('J');        //to form a 5x5 matrix

    QString output = nullptr;
    int row = 5, col = 5;

    QVector <QVector <QChar>> keyAlphabet;

    for (int i = 0, s = 0; i < row; i++)
    {
        QVector <QChar> temp;

        for (int j = 0; j < col; j++)
            temp.push_back(key[s++]);

        keyAlphabet.push_back(temp);
    }

    foreach (auto currentChar, plainText)
    {
        int tempRow = -1, tempCol = -1;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (keyAlphabet[i][j] == currentChar)
                {
                    tempRow = i;
                    tempCol = j;
                    break;
                }

        if (tempRow == -1 || tempCol == -1)
        {
            QString description = "Can not find this character in the key: ";
            QMessageBox::critical(nullptr, "Run time error", description + currentChar);
            return nullptr;
        }

        output += alphabet[tempRow];
        output += alphabet[tempCol];
        output += " ";
    }

    return output;
}

QString Encryption::SwapCipher(QString key, QString plainText) //Дописать на человеческом языке
{
    foreach (auto currentChar, key)
    {
        if (!currentChar.isNumber() && currentChar != ' ')
        {
            QString description = "Invalid character in the key: ";
            QMessageBox::critical(nullptr, "Input error", description + currentChar);
            return nullptr;
        }
        if (currentChar.isSpace())
            key.remove(currentChar);

        if (currentChar.isPunct())
            key.remove(currentChar);
    }
    foreach (auto currentChar, plainText)
    {
        if (!currentChar.isLetter())
        {
            QString description = "Invalid character in the text: ";
            QMessageBox::critical(nullptr, "Input error", description + currentChar);
            return nullptr;
        }
        if (currentChar.isSpace())
            plainText.remove(currentChar);

        if (currentChar.isPunct())
            plainText.remove(currentChar);
    }
    plainText = plainText.toUpper();
    key = key.toUpper();

    QString output = nullptr;

    QVector <QString> cipherMatrix(0);
    cipherMatrix.push_back(key);


    for (int i = 0, j = 0; i < plainText.size(); j = 0)
    {
        QString tempString;
        while (j++ != key.size() && i < plainText.size())
            tempString += plainText[i++];

        if (tempString.size() < key.size())
            while (tempString.size() != key.size())
                tempString += alphabet[qrand() % alphabet.length()];

        cipherMatrix.push_back(tempString);
        tempString.clear();
    }

    int keySize = key.size();

    for (int i = 0; i < keySize; i++)
    {
        int index = 0;
        QChar tempChar = key[0];
        for (int j = 0; j < key.size(); j++)
        {
            if (tempChar > key[j])
            {
                tempChar = key[j];
                index = j;
            }
        }

        key.remove(index, 1);

        for (int j = 1; j < cipherMatrix.size(); j++)
        {
            QString tempStr = cipherMatrix[j];
            output += tempStr[index];
            cipherMatrix[j].remove(index, 1);
        }

        output += " ";
    }

    return output;
}

QString Encryption::VigeneraCipher(QString key, QString plainText) //Ready
{
    QString output = nullptr;

    foreach (auto currentChar, key)
        if (!currentChar.isLetter())
        {
            QString description = "Invalid character in the key: ";
            QMessageBox::critical(nullptr, "Key input error", description + currentChar);
            return nullptr;
        }

    for (int i = 0; key.length() < plainText.length(); i++)
    {
        if (i == key.length())
            i = 0;

        key += key[i];
    }

    for (int i = 0; i < plainText.length(); i++)
    {
        if (!plainText[i].isLetter())
        {
            output += plainText[i];
            continue;
        }

        if (plainText[i].isLower())
            plainText[i] = plainText[i].toUpper();

        if (key[i].isLower())
            key[i] = key[i].toUpper();

        int inputIndex = alphabet.indexOf(plainText[i]);
        int keyIndex = alphabet.indexOf(key[i]);
        if (inputIndex == -1)
        {
            QMessageBox::critical(nullptr, "Input error", "Invalid character in the text: " + plainText[i]);
            return nullptr;
        }
        if (keyIndex == -1)
        {
            QMessageBox::critical(nullptr, "Key input error", "Invalid character in the key: " + key[i]);
            return nullptr;
        }

        output += alphabet[(inputIndex + keyIndex) % alphabet.length()];
    }

    return output;
}
