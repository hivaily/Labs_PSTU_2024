#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include "treewidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Insert_Clicked();
    void on_Remove_Clicked();
    void on_Balance_Clicked();
    void on_Clear_Clicked();
    void on_preOButton_clicked();
    void on_inOButton_clicked();
    void on_postOButton_clicked();

private:
    Ui::MainWindow *ui;
    Tree tree;
    TreeWidget* treeWidget;
};

#endif // MAINWINDOW_H
