#include "registertourist.h"

RegisterTourist::RegisterTourist(QWidget *parent){
    QDialog(parent){
        QLabel *lblName = new QLabel("Name",this);
        txtName = new QLineEdit(this);

        QLabel *lblSurname = new QLabel("Surname",this);
        txtSurname = new QLineEdit(this);

        QLabel *lblEmail = new QLabel("Email",this);
        txtEmail = new QLineEdit(this);

        btnSave = new QPushButton("save tourist",this);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(lblName);
        layout->addWidget(txtName);
        layout->addWidget(lblSurname);
        layout->addWidget(txtSurname);
        layout->addWidget(lblEmail);
        layout->addWidget(textEmail);
        layout->addWidget(btnSave);

        setLayout(layout);

        connect(btnSave, &QPushButton::clicked, this, &RegisterTourist::on_btnSave_clicked);
    }

    RegisterTourist::~RegisterTourist() {
    // Destructor
}

void RegisterTourist::on_btnSave_clicked() {
    QString Name = txtName->text();
    QString Surname = txtSurname->text();
    QString Email = txtEmail->text();

    qDebug()<<"Name:"<<Name<<"Surname"<<Surname<<"Email"<<Email;

    database = QSqlDatabase::addDatabase("QSQLITE");
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
    query.prepare("INSERT INTO Tourist (Name, Surname, Email) VALUES (:Name, :Surname, :Email)");
    query.bindValue(":Name", Name);
    query.bindValue(":Surname", Surname);
    query.bindValue(":Email", Email);

    if (!query.exec()) {
        qDebug() << "Error inserting data: " << query.lastError().text();
    } else {
        qDebug() << "Data inserted successfully";
    }

    database.close();
}
}