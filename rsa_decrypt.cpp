#include "rsa_decrypt.h"
#include <QDebug>
rsa_decrypt::rsa_decrypt()
{

}

QString *rsa_decrypt::rsaDecrept(QList<QString> *cipher, QString alphabet,int d,int n)
{
    QString *result_string = new QString();

    unsigned long long current, result;

    for(int i = 0; i < cipher->length();i++)
    {
        current = cipher->value(i).toLong();

        result = 1;

        for ( long int j = 0; j < d; j++ )
        {
            result = result * current;
            result = result % n;
        }
        *result_string = result_string + alphabet[(int)result];
    }

    qDebug()<<*result_string;

    return result_string;
}
