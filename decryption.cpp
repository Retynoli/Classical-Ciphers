#include "decryption.h"

Decryption::Decryption()
{ }

bool isMutuallyPrimeNumbers(int a, int b)		//проверка на взаимно простые числа
{
    for (int i = 2; i < b; i++)
        if (a % i == 0 && b % i == 0)
            return false;

    return true;
}

double frequency(char c)
{
    switch (c)
    {
    case 'A':	return 8.55;
    case 'B':	return 1.60;
    case 'C':	return 3.16;
    case 'D':	return 3.87;
    case 'E':	return 12.10;
    case 'F':	return 2.18;
    case 'G':	return 2.09;
    case 'H':	return 4.96;
    case 'I':	return 7.33;
    case 'J':	return 0.22;
    case 'K':	return 0.81;
    case 'L':	return 4.21;
    case 'M':	return 2.53;
    case 'N':	return 7.17;
    case 'O':	return 7.47;
    case 'P':	return 2.07;
    case 'Q':	return 0.17;
    case 'R':	return 6.33;
    case 'S':	return 6.73;
    case 'T':	return 8.94;
    case 'U':	return 2.68;
    case 'V':	return 1.06;
    case 'W':	return 1.83;
    case 'X':	return 0.17;
    case 'Y':	return 1.72;
    case 'Z': 	return 0.11;
    default: return 0;
    }
}

QString Decryption::AtbashCipher(QString cipherText) //Ready
{
    cipherText = cipherText.toUpper();

    QString output = nullptr;

    foreach (auto currentChar, cipherText)
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

QString Decryption::ROT13(QString cipherText) //Ready
{
    cipherText = cipherText.toUpper();

    QString output = nullptr;

    foreach (auto currentChar, cipherText)
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

QString Decryption::CaesarCipher(QString input) //Ready
{
    QString output = nullptr;
    input = input.toUpper();

    double currentFrequency = 0, rememberedFrequency = 0;
    for (int i = 0; i < alphabet.length(); i++)
    {
        QString tempDecode;
        QString alphabetOfUsedLetters;

        foreach (auto currentChar, input)
        {
            if (!currentChar.isLetter())
            {
                tempDecode += currentChar;
                continue;
            }

            int index = alphabet.indexOf(currentChar) - i;

            if (index < 0)
                index = alphabet.length() - abs(alphabet.indexOf(currentChar) - i);

            tempDecode += alphabet[index];
        }

        foreach (auto currentChar, tempDecode)      // using frequency analysis
        {
            if (!currentChar.isLetter())
                continue;

            if (alphabetOfUsedLetters.indexOf(currentChar) == -1)
            {
                currentFrequency += (frequency(currentChar.toLatin1()) * (tempDecode.count(currentChar) * 1.0 / tempDecode.length()));
                alphabetOfUsedLetters += currentChar;
            }
        }

        if (currentFrequency > rememberedFrequency)
        {
            output = tempDecode;
            rememberedFrequency = currentFrequency;
        }

        currentFrequency = 0;
    }

    return output;
}

QString Decryption::AffiliateCipher(QString input)
{
    QString output = nullptr;

//    foreach (auto currentChar, input)
//        if (!currentChar.isLetter())
//            input.remove(currentChar);

    input = input.toUpper();

    double currentFrequency = 0, rememberedFrequency = 0;
    for (int i = 0; i < alphabet.length(); i++)
    {
        if (!isMutuallyPrimeNumbers(i, alphabet.length()))
            continue;

        for (int j = 0; j < alphabet.length(); j++)
        {
            QString tempDecode;
            QString alphabetOfUsedLetters;

            foreach (auto currentChar, input)           // input decryption
            {
                if (!currentChar.isLetter())
                {
                    tempDecode += currentChar;
                    continue;
                }

                tempDecode += alphabet[i * (alphabet.indexOf(currentChar) + j) % alphabet.length()];
            }

            foreach (auto currentChar, tempDecode)      // using frequency analysis
            {
                if (!currentChar.isLetter())
                    continue;

                if (alphabetOfUsedLetters.indexOf(currentChar) == -1)
                {
                    currentFrequency += (frequency(currentChar.toLatin1()) * (tempDecode.count(currentChar) * 1.0 / tempDecode.length()));
                    alphabetOfUsedLetters += currentChar;
                }
            }

            if (currentFrequency > rememberedFrequency)
            {
                output = tempDecode;
                rememberedFrequency = currentFrequency;
            }

            currentFrequency = 0;
        }
    }

    return output;
}

QString Decryption::SimpleReplacementCipher(QString input)
{
    QString primeAlphabet;
    QVector <double> primeKey(0);

    input = input.toUpper();

    foreach (auto currentChar, input)      // using frequency analysis
    {
        if (!currentChar.isLetter())
            continue;

        if (primeAlphabet.indexOf(currentChar) == -1)
        {
            primeKey.push_back(input.count(currentChar) * 1.0 / input.length());
            primeAlphabet += currentChar;
        }
    }

    for (int i = 0, swap_cnt = 0; i < primeKey.size();)     //sorting
    {
        if (i + 1 != primeKey.size() && primeKey[i] < primeKey[i + 1])
        {
            QChar temp = primeAlphabet[i];
            primeAlphabet[i] = primeAlphabet[i + 1];
            primeAlphabet[i + 1] = temp;
            double tempD = primeKey[i];
            primeKey[i] = primeKey[i + 1];
            primeKey[i + 1] = tempD;
            swap_cnt = 1;
        }
        i++;
        if (i == primeKey.size() && swap_cnt == 1)
        {
            swap_cnt = 0;
            i = 0;
        }
    }

    for (int i = 0; primeAlphabet.length() != alphabet.length(); i++)
        if (primeAlphabet.indexOf(alphabet[i]) == -1)
        {
            primeAlphabet += alphabet[i];
            primeKey.push_back(0.0);
        }

    QString sortedAlphabet = "ETAOINSHRDLCUMWFGYPBVKXJQZ";
    QString primeCiphertext;

    foreach (auto currentChar, input)      // getting the primary ciphertext
    {
        if (!currentChar.isLetter())
        {
            primeCiphertext += currentChar;
            continue;
        }

        primeCiphertext += sortedAlphabet[primeAlphabet.indexOf(currentChar) % sortedAlphabet.length()];
    }

    QString bigrams;
    QString trigrams;
    double prevBigramsRating = 0;
    double prevTrigramsRating = 0;
    foreach(auto currentChar, primeCiphertext)
    {
        if (!currentChar.isLetter())
            continue;

        if (bigrams.length() == 2)
        {
            prevBigramsRating += bigramsFreqsStandart.value(bigrams);
            bigrams.clear();
        }

        if (trigrams.length() == 3)
        {
            prevTrigramsRating += trigramsFreqsStandart.value(trigrams);
            trigrams.clear();
        }
        bigrams += currentChar;
        trigrams += currentChar;
    }
    if (bigrams.length() == 2)
        prevBigramsRating += bigramsFreqsStandart.value(bigrams);

    if (trigrams.length() == 3)
        prevTrigramsRating += trigramsFreqsStandart.value(trigrams);

    bigrams.clear();
    trigrams.clear();

    QString tempString;
    int step = 1;
    while (true)
    {
        bool findGoodBigrammFlag = false;

        for (int i = 0; i + step < primeAlphabet.length(); i++)
        {
            QChar temp = primeAlphabet[i];
            primeAlphabet[i] = primeAlphabet[i + step];
            primeAlphabet[i + step] = temp;

            foreach (auto currentChar, primeCiphertext)           // decryption
            {
                if (!currentChar.isLetter())
                {
                    tempString += currentChar;
                    continue;
                }

                tempString += sortedAlphabet[primeAlphabet.indexOf(currentChar) % sortedAlphabet.length()];
            }

            double currentBigramsRating = 0;
            double currentTrigramsRating = 0;
            foreach (auto currentChar, tempString)   //count current bigram and trigram rating
            {
                if (!currentChar.isLetter())
                    continue;

                if (bigrams.length() == 2)
                {
                    currentBigramsRating += bigramsFreqsStandart.value(bigrams);
                    bigrams.clear();
                }
                if (trigrams.length() == 3)
                {
                    currentTrigramsRating += trigramsFreqsStandart.value(trigrams);
                    trigrams.clear();
                }

                bigrams += currentChar;
                trigrams += currentChar;
            }
            if (bigrams.length() == 2)
                currentBigramsRating += bigramsFreqsStandart.value(bigrams);
            if (trigrams.length() == 3)
                currentTrigramsRating += trigramsFreqsStandart.value(trigrams);

            bigrams.clear();
            trigrams.clear();

            if (currentBigramsRating > prevBigramsRating && currentTrigramsRating > prevTrigramsRating)
            {
                findGoodBigrammFlag = true;
                prevBigramsRating = currentBigramsRating;
                prevTrigramsRating = currentTrigramsRating;
                primeCiphertext = tempString;
                tempString.clear();
                step = 1;
                break;
            }
            else
            {
                tempString.clear();
                QChar temp = primeAlphabet[i + step];
                primeAlphabet[i + step] = primeAlphabet[i ];
                primeAlphabet[i] = temp;
            }
        }

        if (!findGoodBigrammFlag)
        {
            step++;
            if (step > primeAlphabet.length())
                break;
        }
    }

    return primeCiphertext;
}

QString Decryption::PolibiyaCipher(QString input)
{
    QString output = nullptr;
    return output;
}

QString Decryption::SwapCipher(QString input)
{
    QString output = nullptr;
    return output;
}

QString Decryption::VigeneraCipher(QString input)
{
    QString output = nullptr;
    return output;
}
