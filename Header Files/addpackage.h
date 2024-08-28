#ifndef ADDPACKAGE_H
#define ADDPACKAGE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <SQlError>
#include <QFile>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class AddPackage : public QDialog
{
    Q_OBJECT

    public:
      explicit AddPackage(QWidget *parent = nullptr)
      ~AddPackage();

private slots:
    void on_btnSave_clicked();

private:
   QLineEdit *txtName;
   QLineEdit *txtPackageDescription;
   QLineEdit *textAmount;
   QPushButton *btnSave;
   QSqlDatabase database;
};

#endif