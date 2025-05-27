#include "mainwindow.h"
#include "ui_mainwindow.h"
QString infos = "";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Деревья");
    treeWidget = new TreeWidget(this);
    ui->verticalLayout->insertWidget(0, treeWidget);
    treeWidget->update();
    treeWidget->setTree(&tree);
    connect(ui->insertButton, &QPushButton::clicked, this, &MainWindow::on_Insert_Clicked);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::on_Remove_Clicked);
    connect(ui->balanceButton, &QPushButton::clicked, this, &MainWindow::on_Balance_Clicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::on_Clear_Clicked);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_preOButton_clicked()
{
    infos = "";
    tree.preOrder(tree.getRoot());
    QMessageBox::information(nullptr, "Прямой обход", infos);
}


void MainWindow::on_inOButton_clicked()
{
    infos = "";
    tree.inOrder(tree.getRoot());
    QMessageBox::information(nullptr, "Симметричный обход", infos);
}

void MainWindow::on_postOButton_clicked()
{
    infos = "";
    tree.postOrder(tree.getRoot());
    QMessageBox::information(nullptr, "Обратный обход", infos);
}



void MainWindow::on_Insert_Clicked()
{
    int value = ui->valueSpinBox->value();
    tree.insert(value);
    treeWidget->update();
    treeWidget->setTree(&tree);
}

void MainWindow::on_Remove_Clicked()
{
    int value = ui->valueSpinBox->value();

    if (!tree.search(value))
    {
        QMessageBox::warning(this, "Ошибка", "Узел с таким значением не найден!");
        return;
    }

    tree.remove(value);
    treeWidget->setTree(&tree);
}

void MainWindow::on_Balance_Clicked()
{
    tree.balance();
    treeWidget->setTree(&tree);
}

void MainWindow::on_Clear_Clicked()
{
    tree.clear();
    treeWidget->setTree(&tree);
}



