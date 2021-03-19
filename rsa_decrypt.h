#ifndef RSA_DECRYPT_H
#define RSA_DECRYPT_H
#include <QList>


class rsa_decrypt
{
public:
    rsa_decrypt();
    QString* rsaDecrept(QList<QString> *cipher, QString alphabet, int d, int n);
};

#endif // RSA_DECRYPT_H
