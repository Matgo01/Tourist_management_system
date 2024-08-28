#ifndef FINDPACKAGE_H
#define FINDPACKAGE_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QVBoxLayout>



class FindPackage : public QDialog
{
    Q_OBJECT

public:
    explicit FindPackage(QWidget *parent = nullptr);
    ~FindPackage();

private slots:
    void on_btnSave_clicked();

private:
    QLineEdit *txtPackageName;
    QPushButton *findButton;
    QTableView *tableView;
    QSqlQueryModel *model; // Added model to manage the SQL query results
};

#endif // FINDPACKAGE_H
