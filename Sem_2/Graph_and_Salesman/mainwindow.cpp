#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI()
{
        graphWidget = new GraphWidget(this);

        QPushButton *addG = new QPushButton("Добавить вершину", this);
        QPushButton *removeG = new QPushButton("Удалить вершину", this);
        QPushButton *addE = new QPushButton("Добавить ребро", this);
        QPushButton *removeE = new QPushButton("Удалить ребро", this);
        QPushButton *editW = new QPushButton("Изменить вес ребра", this);
        QPushButton *editM = new QPushButton("Редактировать матрицу смежности", this);
        QPushButton *bfs = new QPushButton("Обход в ширину", this);
        QPushButton *dfs = new QPushButton("Обход в глубину", this);
        QPushButton *dextersomeone = new QPushButton("Алгоритм Дейкстры", this);
        QPushButton *floyd = new QPushButton("Алгоритм Флойда", this);
        QPushButton *comi = new QPushButton("Коммивояжер", this);
        connect(addG, &QPushButton::clicked, this, &MainWindow::on_addG_Clicked);
        connect(removeG, &QPushButton::clicked, this, &MainWindow::on_removeG_Clicked);
        connect(addE, &QPushButton::clicked, this, &MainWindow::on_addE_Clicked);
        connect(removeE, &QPushButton::clicked, this, &MainWindow::on_removeE_Clicked);
        connect(editW, &QPushButton::clicked, this, &MainWindow::on_editW_Clicked);
        connect(editM, &QPushButton::clicked, this, &MainWindow::on_editM_Clicked);
        connect(bfs, &QPushButton::clicked, this, &MainWindow::on_bfs_Clicked);
        connect(dfs, &QPushButton::clicked, this, &MainWindow::on_dfs_Clicked);
        connect(dextersomeone, &QPushButton::clicked, this, &MainWindow::on_dextersomeothing_Clicked);
        connect(floyd, &QPushButton::clicked, this, &MainWindow::on_floyd_Clicked);
        connect(comi, &QPushButton::clicked, this, &MainWindow::on_comi_Clicked);


        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout->addWidget(addG);
        buttonLayout->addWidget(removeG);
        buttonLayout->addWidget(addE);
        buttonLayout->addWidget(removeE);
        buttonLayout->addWidget(editW);
        buttonLayout->addWidget(editM);
        buttonLayout->addWidget(bfs);
        buttonLayout->addWidget(dfs);
        buttonLayout->addWidget(dextersomeone);
        buttonLayout->addWidget(floyd);
        buttonLayout->addWidget(comi);

        QVBoxLayout *mainLayout = new QVBoxLayout();
        mainLayout->addLayout(buttonLayout);
        mainLayout->addWidget(graphWidget);

        QWidget *centralWidget = new QWidget(this);
        centralWidget->setLayout(mainLayout);
        setCentralWidget(centralWidget);

        setWindowTitle("Графы и коммивояжер");
        resize(1000, 800);
}

void MainWindow::on_addG_Clicked()
{
    bool ok;
    int GraphNumber = QInputDialog::getInt(this, "Добавить вершину",
                                            "Введите номер вершины:",
                                            graphWidget->GraphCount(), 0, 1000, 1, &ok);
    if (ok) {

        graphWidget->setWaitingForClick(true, GraphNumber);
    }
}

void MainWindow::on_removeG_Clicked()
{
    bool ok;
    int GraphNumber = QInputDialog::getInt(this, "Удалить вершину",
                                            "Введите номер вершины для удаления:",
                                            0, 0, graphWidget->GraphCount() - 1, 1, &ok);
    if (ok) {
        graphWidget->removeGraph(GraphNumber);
    }
}

void MainWindow::on_addE_Clicked()
{
    bool ok1, ok2;
    int from = QInputDialog::getInt(this, "Добавить ребро", "Первая вершина:",
                                    0, 0, graphWidget->GraphCount() - 1, 1, &ok1);
    int to = QInputDialog::getInt(this, "Добавить ребро", "Вторая вершина:",
                                  0, 0, graphWidget->GraphCount() - 1, 1, &ok2);
    if (ok1 && ok2) {
        graphWidget->addEdge(from, to);
    }
}

void MainWindow::on_removeE_Clicked()
{
    bool ok1, ok2;
    int from = QInputDialog::getInt(this, "Удалить ребро", "Первая вершина:",
                                    0, 0, graphWidget->GraphCount() - 1, 1, &ok1);
    int to = QInputDialog::getInt(this, "Удалить ребро", "Вторая вершина:",
                                  0, 0, graphWidget->GraphCount() - 1, 1, &ok2);
    if (ok1 && ok2) {
        graphWidget->removeEdge(from, to);
    }
}

void MainWindow::on_editW_Clicked()
{
    bool ok1, ok2, ok3;
    int from = QInputDialog::getInt(this, "Изменить вес ребра", "Первая вершина:",
                                    0, 0, graphWidget->GraphCount() - 1, 1, &ok1);
    int to = QInputDialog::getInt(this, "Изменить вес ребра", "Вторая вершина:",
                                  0, 0, graphWidget->GraphCount() - 1, 1, &ok2);
    int weight = QInputDialog::getInt(this, "Изменить вес ребра", "Новый вес:",
                                      1, 1, 10000, 1, &ok3);
    if (ok1 && ok2 && ok3) {
        graphWidget->setEdge(from, to, weight);
    }
}

void MainWindow::on_editM_Clicked()
{
    int n = graphWidget->GraphCount();
    if (n == 0) {
        QMessageBox::warning(this, "Ошибка", "Нет вершин для редактирования матрицы");
        return;
    }

    QVector<QVector<int>> matrix = graphWidget->getAdjacencyMatrix();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool ok;
            int val = QInputDialog::getInt(this, "Редактирование матрицы",
                                           QString("Матрица[%1][%2]:").arg(i).arg(j),
                                           matrix[i][j], 0, 1, 1, &ok);
            if (!ok) return;
            matrix[i][j] = val;
        }
    }

    graphWidget->setMatrix(matrix);
}

void MainWindow::on_bfs_Clicked()
{
    bool ok;
    int start = QInputDialog::getInt(this, "BFS", "Начальная вершина:",
                                     0, 0, graphWidget->GraphCount() - 1, 1, &ok);
    if (ok) {
        graphWidget->bSearch(start);
    }
}

void MainWindow::on_dfs_Clicked()
{
    bool ok;
    int start = QInputDialog::getInt(this, "DFS", "Начальная вершина:",
                                     0, 0, graphWidget->GraphCount() - 1, 1, &ok);
    if (ok) {
        graphWidget->dSearch(start);
    }
}

void MainWindow::on_dextersomeothing_Clicked()
{
    bool ok1, ok2;
    int from = QInputDialog::getInt(this, "Дейкстра", "Откуда:",
                                    0, 0, graphWidget->GraphCount() - 1, 1, &ok1);
    int to = QInputDialog::getInt(this, "Дейкстра", "Куда:",
                                  0, 0, graphWidget->GraphCount() - 1, 1, &ok2);
    if (ok1 && ok2) {
        graphWidget->dextersomeothing(from, to);
    }
}

void MainWindow::on_floyd_Clicked()
{
    graphWidget->floyd();
}

void MainWindow::on_comi_Clicked()
{
    graphWidget->solvecomi();
}
