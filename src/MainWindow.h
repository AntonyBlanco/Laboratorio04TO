#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "SignoZodiacal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSelectZodiac(QListWidgetItem* item);

private:
    Ui::MainWindow *ui;
    QList<SignoZodiacal> signozodiacal;
};
#endif // MAINWINDOW_H
