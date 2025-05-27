#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPushButton>
#include <QInputDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class GraphWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addG_Clicked();
    void on_removeG_Clicked();
    void on_addE_Clicked();
    void on_removeE_Clicked();
    void on_editW_Clicked();
    void on_editM_Clicked();
    void on_bfs_Clicked();
    void on_dfs_Clicked();
    void on_dextersomeothing_Clicked();
    void on_floyd_Clicked();
    void on_comi_Clicked();

private:
    Ui::MainWindow *ui;
    GraphWidget *graphWidget;
    void setupUI();
};

#endif // MAINWINDOW_H
