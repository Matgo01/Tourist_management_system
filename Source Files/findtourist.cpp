#include "findtourist.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>
#include <QVBoxLayout>

FindTourist::FindTourist(QWidget *parent) :
    QDialog(parent),
    model(nullptr)
{
    // Create UI elements
    txtTouristName = new QLineEdit(this);
    txtTouristName->setPlaceholderText("Enter Tourist Name");

    findButton = new QPushButton("Find Tourist", this);

    tableView = new QTableView(this);

    // Set up layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(txtTouristName);
    layout->addWidget(findButton);
    layout->addWidget(tableView);

    setLayout(layout);

    // Connect button signal to the slot
    connect(findButton, &QPushButton::clicked, this, &FindTourist::on_findButton_clicked);
}

FindTourist::~FindTourist() {
    if (model) {
        delete model;
    }
}

void FindTourist::on_findButton_clicked() {
    QString touristName = txtTouristName->text();
    qDebug() << "Tourist Name:" << touristName;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/document/Matteo Gorla/database/myDb.db");

    if (!QFile::exists("C:/Users/document/Matteo Gorla/database/myDb.db")) {
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
    query.prepare("SELECT id, TouristName, Surname, Email FROM Tourist WHERE TouristName = :touristName");
    query.bindValue(":touristName", touristName);

    if (!query.exec()) {
        qDebug() << "Query execution error: " << query.lastError().text();
        return;
    }

    if (!model) {
        model = new QSqlQueryModel(this);  // Parent is set to manage memory automatically
    }
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Name");
    model->setHeaderData(2, Qt::Horizontal, "Surname");
    model->setHeaderData(3, Qt::Horizontal, "Email");

    tableView->setModel(model);
    tableView->resizeColumnsToContents();
    database.close();
}
