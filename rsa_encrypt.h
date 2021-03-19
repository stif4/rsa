#ifndef RSA_ENCRYPT_H
#define RSA_ENCRYPT_H

#include <QString>
#include <QVector>
#include <QList>

class rsa_encrypt
{
public:
    rsa_encrypt();
    QList<QString>* rsaEncrept(QString alphabet, QString dataString);
    long calculate_d(long m, long e);
    long calculate_e(long m);
    QList<QString>* rsa_endoce(QString alphabet, QString s, long e, long n);
    long int greatestCommonDivisor( long int e, long int t );
    int getD();
    int getN();
private:
    QVector<int> tableSimpleNumber;
    long p;
    long q;
    long n;
    long m;
    long d;
    long e;
};

#endif // RSA_ENCRYPT_H
