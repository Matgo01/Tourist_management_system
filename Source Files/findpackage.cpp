#include "findpackage.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>
#include <QVBoxLayout>


FindPackage::FindPackage(QWidget *parent) :
    QDialog(parent),
    model(nullptr) // Initialize the model to nullptr
{
    txtPackageName = QLineEdit(this);
    txtPakcage->setPlaceHolderText("enter package name");

    findButton = new QPushButton("Find package", this);

    tableView = new QTableView(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(txtPackageName);
    layout->addWidget(findButton);
    layout->addWidget(tableView);
    
    setLayout(layout);
    
    // Connect button signal to the slot
    connect(findButton, &QPushButton::clicked, this, &FindPackage::on_findButton_clicked);}

FindPackage::~FindPackage() {
    delete ui;
    if (model) {
        delete model; // Clean up the model if it was created
    }
}

void FindPackage::on_btnSave_clicked() {
    QString packageName = ui->txtPackageName->text();

    qDebug() << "Package Name:" << packageName; 

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/document/Matteo Gorla/database/myDb.db");

    if (QFile::exists("C:/Users/document/Matteo Gorla/database/myDb.db")) {
        qDebug() << "Database file exists";
    } else {
        qDebug() << "Database file doesn't exist";
        return;
    }

    if (!database.open()) {
        qDebug() << "Error opening database: " << database.lastError().text();
        return;
    } else {
        qDebug() << "Database opened";
    }

    QSqlQuery query(database);
    query.prepare("SELECT * FROM Package WHERE PackageName = :packageName");
    query.bindValue(":packageName", packageName);

    if (!query.exec()) {
        qDebug() << "Query execution error: " << query.lastError().text();
        return;
    }

    if (!model) {
        model = new QSqlQueryModel();
    }
    model->setQuery(query);
    model->setModel(model);
    model->setColumnWidth(0, 200);
    model->setColumnWidth(1, 200);
    model->setColumnWidth(2, 200);

    database.close();
}
