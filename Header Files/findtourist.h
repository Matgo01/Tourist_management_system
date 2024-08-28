#ifndef FINDTOURIST_H
#define FINDTOURIST_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QVBoxLayout>

class FindTourist : public QDialog
{
    Q_OBJECT

public:
    explicit FindTourist(QWidget *parent = nullptr);
    ~FindTourist();

private slots:
    void on_findButton_clicked();

private:
    QLineEdit *txtTouristName;
    QPushButton *findButton;
    QTableView *tableView;
    QSqlQueryModel *model;
};

#endif // FINDTOURIST_H

