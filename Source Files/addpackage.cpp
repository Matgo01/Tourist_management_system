#include "addpackage.h"


AddPackage::AddPackage(QWidget *parent){
    QDialog(parent),{
        QLabel PlblPackageName = new QLabel("Package Name:",this);
        txtPackageName = new QLineEdit(this);

        QLabel *lblPackageDscription = new QLabel("Package Description:", this);
        txtPackageDescription = new QTextEdit(this);

        QLabel *lblAmount = new QLabel("Amount:",this);
        textAmount = new QLineEdit(this);

        btnSave = new QPushButton("Save package",this);

        QVBoxLayout *layout = new VBoxLayout(this);
        layout->addWidget(lblPackageName);
        layout->addWidget(txtPackageName);
        layout->addWidget(lblPackageDescription);
        layout->addWidget(txtPackageDescription);
        layout->addWidget(lblAmount);
        layout->addWidget(textAmount);
        layout->addWidget(btnSave);

        setLayout(layout);

        connect(btnSave, &QPushButton::clicked, this, &AddPackage::on_btnSave_clicked);
    }

    AddPackage::~AddPackage(){
        
    }

    void AddPackage::on_btnSave_clicked(){
        QString packageName = ui->txtPackageName->text();
        QString packageDescription = ui->txtPackageDescription->text();
        QString amount = ui->textAmount->text();

        qDebug()<<"Package Name:"<<packageName<<"description package"<<packageDesription<<"amount"<<amount;

        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("C:/User/document/Matteo Gorla/database/myDb.db");

        if(QFile::exists("C:/Users/document/Matteo Gorla/myDb.db")){
            qDebug()<<"Database file exists";
        }else{
            qDebug()<<"Database file dosen't exist",
            return;
        }

        if(!database.open()){
            qDebug()<<"Error opening database";
            return;
        }
        else{
            qDebug()<<"Database opened";
        }
        
        query = QSqlquery(database);
        query.prepare("insert into Package (PakcageName, PackageDscription, Amount) values ('"+pakcageName+"','"+packageDescription+"','"+amount+"'");
        query.exec();
        qDebug()<<"last error:"<<query.lastError().text();
        database.close();
    }
}