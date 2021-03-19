#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setTextEditString();

public slots:
    void click_encrypt();
    void click_decrypt();

private:
    Ui::MainWindow *ui;
    QString alphabet = " abcdefghijklmnopqrstuvwxyz.!,";
    QList<QString> *result;
    QString *decodString;
    int d;
    int n;
};
#endif // MAINWINDOW_H
