#include "rsa_encrypt.h"
#include "generatorsimplenumber.h"
#include <cmath>
#include <QMessageBox>
#include <QDebug>

rsa_encrypt::rsa_encrypt()
{
    generatorSimpleNumber number;
    this->q = number.generateNumber();
    this->p = number.generateNumber();
    n = p * q;
    m = (p - 1) * (q - 1);
}

QList<QString> *rsa_encrypt::rsaEncrept(QString alphabet, QString dataString)
{
    e = calculate_e(m);
    d = calculate_d(m,e);

    return rsa_endoce(alphabet,dataString,e,n);
}

long rsa_encrypt::calculate_d(long t, long e)
{
    /*
    long d = m - 1;
       for (long i = 2; i <= m; i++)
           if ((m % i == 0) && (d % i == 0)) //если имеют общие делители
           {
               d--;
               i = 1;
           }
       return d;
       */
       long int d;
       long int k = 1;

       while ( 1 )
       {
           k = k + t;

           if ( k % e == 0)
           {
               d = (k / e);
               return d;
           }
       }
}

long rsa_encrypt::calculate_e(long m)
{
        long int e;

        for ( e = 2; e < m; e++ )
        {
            if (greatestCommonDivisor( e, m ) == 1 )
            {
                return e;
            }
        }
        return -1;
}

long rsa_encrypt::greatestCommonDivisor(long e, long t)
{
    while ( e > 0 )
       {
           long int myTemp;

           myTemp = e;
           e = t % e;
           t = myTemp;
       }

    return t;
}

int rsa_encrypt::getD()
{
    return d;
}

int rsa_encrypt::getN()
{
    return n;
}

QList<QString> *rsa_encrypt::rsa_endoce(QString alphabet, QString s, long e, long n)
{
    QList<QString> *result = new QList<QString>;

    unsigned long long *big;

        for (int i = 0; i < s.length(); i++)
        {
            int index=-1;

            for (int j = 0; j < alphabet.length(); j++)
            {
                if (s[i].toLower() == alphabet[j])
                {
                    index = j;
                    break;
                }
            }

            if(index == -1)
            {
                QMessageBox msgBox;
                msgBox.setText("В алфавите не найдено заданых символов");
                msgBox.exec();

                result->clear();
                result->push_back("-1");
                break;
            }

            int h = 0;
            long  c = 1;
            while(h<e)
            {
               c = c*index;
               c = c%n;
               h++;
            }
            big = new unsigned long long();

            *big = c;
            result->push_back(QString::number(*big));
        }
        qDebug()<<*result;

        return result;
}

