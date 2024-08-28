#ifndef REGISTERTOURIST_H
#define REGISTERTOURTIST_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class RegisterTourist : public QDialog{
    Q_OBJECT

public:
      explicit RegisterTourist(QWidget *parent = nullptr)
      ~RegisterTourist();

private slots:
    void on_btnSave_clicked();

private:
   QLineEdit *txtName;
   QLineEdit *txtSurname;
   QLineEdit *textEmail;
   QPushButton *btnSave;
   QSqlDatabase database;
}

#endif // REGISTERTOURIST_H