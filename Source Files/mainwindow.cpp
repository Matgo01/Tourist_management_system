#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create instances of the other windows
    ptrAddPackage = new AddPackage();
    ptrRegisterTourist = new RegisterTourist();
    ptrFindPackage = new FindPackage();
    ptrFindTourist = new FindTourist();

    // Create buttons
    QPushButton *btnAddPackage = new QPushButton("Add Package", this);
    QPushButton *btnRegisterTourist = new QPushButton("Register Tourist", this);
    QPushButton *btnFindPackage = new QPushButton("Find Package", this);
    QPushButton *btnFindTourist = new QPushButton("Find Tourist", this);

    // Set geometry for buttons (x, y, width, height)
    btnAddPackage->setGeometry(QRect(QPoint(50, 50), QSize(200, 50)));
    btnRegisterTourist->setGeometry(QRect(QPoint(50, 120), QSize(200, 50)));
    btnFindPackage->setGeometry(QRect(QPoint(50, 190), QSize(200, 50)));
    btnFindTourist->setGeometry(QRect(QPoint(50, 260), QSize(200, 50)));

    // Connect buttons to corresponding slots
    connect(btnAddPackage, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(btnRegisterTourist, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);
    connect(btnFindPackage, &QPushButton::clicked, this, &MainWindow::on_pushButton_3_clicked);
    connect(btnFindTourist, &QPushButton::clicked, this, &MainWindow::on_pushButton_4_clicked);
}

MainWindow::~MainWindow()
{
    delete ptrAddPackage;
    delete ptrRegisterTourist;
    delete ptrFindPackage;
    delete ptrFindTourist;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ptrAddPackage->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    ptrRegisterTourist->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    ptrFindPackage->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    ptrFindTourist->show();
}
