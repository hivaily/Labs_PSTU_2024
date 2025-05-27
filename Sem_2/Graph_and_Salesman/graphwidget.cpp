#include "graphwidget.h"


GraphWidget::GraphWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
}

GraphWidget::~GraphWidget()
{
    clearT();
}

void GraphWidget::addGraph(int x, int y, int number) {
    if (number < 0) {
        QMessageBox::warning(nullptr, "Ошибка", "Номер вершины не может быть отрицательным");
        return;
    }

    if (number < vertices.size() && vertices[number].ellipse != nullptr) {
        QMessageBox::warning(nullptr, "Ошибка", "Вершина с таким номером уже существует");
        return;
    }

    if (number >= vertices.size()) {
        vertices.resize(number + 1);

        int oldSize = adjacencyMatrix.size();

        adjacencyMatrix.resize(number + 1);
        edgeWeights.resize(number + 1);

        for (int i = 0; i <= number; ++i) {
            if (i >= oldSize) {
                adjacencyMatrix[i] = QVector<int>(number + 1, 0);
                edgeWeights[i] = QVector<int>(number + 1, 0);
            }
            else {
                adjacencyMatrix[i].resize(number + 1);
                edgeWeights[i].resize(number + 1);
                for (int j = oldSize; j <= number; ++j) {
                    adjacencyMatrix[i][j] = 0;
                    edgeWeights[i][j] = 0;
                }
            }
        }
    }

    Graph &v = vertices[number];
    v.x = x;
    v.y = y;

    v.ellipse = scene()->addEllipse(v.x - 15, v.y - 15, 30, 30,
                                    QPen(Qt::black), QBrush(Qt::white));
    v.label = scene()->addText(QString::number(number));
    QFont font = v.label->font();
    font.setPointSize(12);
    v.label->setFont(font);
    v.label->setDefaultTextColor(Qt::black);
    QRectF textRect = v.label->boundingRect();
    v.label->setPos(v.x - textRect.width() / 2, v.y - textRect.height() / 2);

}

void GraphWidget::removeGraph(int index)
{
    if (index < 0 || index >= vertices.size() || vertices[index].ellipse == nullptr) {
        QMessageBox::warning(nullptr, "Ошибка", "Неверный индекс вершины");
        return;
    }

    scene()->removeItem(vertices[index].ellipse);
    scene()->removeItem(vertices[index].label);
    delete vertices[index].ellipse;
    delete vertices[index].label;

    for (int i = 0; i < vertices.size(); ++i) {
        if (adjacencyMatrix[index][i] != 0) {
            adjacencyMatrix[index][i] = 0;
            adjacencyMatrix[i][index] = 0;
            edgeWeights[index][i] = 0;
            edgeWeights[i][index] = 0;
        }
    }

    vertices.remove(index);

    adjacencyMatrix.remove(index);
    edgeWeights.remove(index);
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        adjacencyMatrix[i].remove(index);
        edgeWeights[i].remove(index);
    }

    for (int i = index; i < vertices.size(); ++i) {
        vertices[i].label->setPlainText(QString::number(i));
    }

    redraw();


}

void GraphWidget::addEdge(int from, int to)
{
    if (from < 0 || to < 0 || from >= vertices.size() || to >= vertices.size() ||
        vertices[from].ellipse == nullptr || vertices[to].ellipse == nullptr) {
        QMessageBox::warning(nullptr, "Ошибка", "Неверные индексы вершин");
        return;
    }

    if (from == to) {
        QMessageBox::warning(nullptr, "Ошибка", "Нельзя создать петлю");
        return;
    }

    adjacencyMatrix[from][to] = 1;
    adjacencyMatrix[to][from] = 1;

    edgeWeights[from][to] = 1;
    edgeWeights[to][from] = 1;

    redraw();

}

void GraphWidget::removeEdge(int from, int to)
{
    if (from < 0 || to < 0 || from >= vertices.size() || to >= vertices.size()) {
        QMessageBox::warning(nullptr, "Ошибка", "Неверные индексы вершин");
        return;
    }

    if (adjacencyMatrix[from][to] == 0) {
        QMessageBox::warning(nullptr, "Ошибка", "Ребро не существует");
        return;
    }

    adjacencyMatrix[from][to] = 0;
    adjacencyMatrix[to][from] = 0;
    edgeWeights[from][to] = 0;
    edgeWeights[to][from] = 0;

    redraw();


}

void GraphWidget::setEdge(int from, int to, int weight)
{
    if (from < 0 || to < 0 || from >= vertices.size() || to >= vertices.size()) {
        QMessageBox::warning(nullptr, "Ошибка", "Неверные индексы вершин");
        return;
    }

    if (adjacencyMatrix[from][to] == 0) {
        QMessageBox::warning(nullptr, "Ошибка", "Ребро не существует");
        return;
    }

    if (weight <= 0) {
        QMessageBox::warning(nullptr, "Ошибка", "Вес должен быть положительным");
        return;
    }

    edgeWeights[from][to] = weight;
    edgeWeights[to][from] = weight;

    redraw();


}

void GraphWidget::setMatrix(const QVector<QVector<int>> &matrix)
{
    if (matrix.size() != vertices.size()) {
        QMessageBox::warning(nullptr, "Ошибка", "Размер матрицы не соответствует количеству вершин");
        return;
    }

    adjacencyMatrix = matrix;
    edgeWeights.resize(vertices.size());

    for (int i = 0; i < vertices.size(); ++i) {
        edgeWeights[i].resize(vertices.size());
        for (int j = 0; j < vertices.size(); ++j) {
            edgeWeights[i][j] = (adjacencyMatrix[i][j] != 0) ? 1 : 0;
        }
    }

    redraw();


}

QVector<QVector<int>> GraphWidget::getAdjacencyMatrix() const
{
    return adjacencyMatrix;
}

void GraphWidget::redraw() {
    for (auto line : edgeLines) {
        scene()->removeItem(line);
        delete line;
    }
    edgeLines.clear();

    for (auto label : edgeLabels) {
        scene()->removeItem(label);
        delete label;
    }
    edgeLabels.clear();

    const qreal GraphRadius = 15.0;

    for (int i = 0; i < vertices.size(); ++i) {
        if (vertices[i].ellipse == nullptr) continue;

        for (int j = i + 1; j < vertices.size(); ++j) {
            if (vertices[j].ellipse == nullptr) continue;

            if (adjacencyMatrix[i][j] != 0) {
                QPen pen(Qt::black);
                if (edgeWeights[i][j] > 1) {
                    pen.setWidth(2);
                }

                QPointF center1(vertices[i].x, vertices[i].y);
                QPointF center2(vertices[j].x, vertices[j].y);

                QPointF direction = center2 - center1;
                qreal length = sqrt(direction.x() * direction.x() + direction.y() * direction.y());

                if (length > 0) {
                    direction /= length;
                }

                QPointF startPoint = center1 + direction * GraphRadius;
                QPointF endPoint = center2 - direction * GraphRadius;

                QGraphicsLineItem* edgeLine = scene()->addLine(
                    QLineF(startPoint, endPoint), pen);
                edgeLines.append(edgeLine);

                if (edgeWeights[i][j] > 0) {
                    QGraphicsTextItem* weightText = scene()->addText(QString::number(edgeWeights[i][j]));
                    weightText->setDefaultTextColor(Qt::black);
                    QPointF midPoint = (startPoint + endPoint) / 2;
                    weightText->setPos(midPoint);
                    edgeLabels.append(weightText);
                }
            }
        }
    }
}

void GraphWidget::bSearch(int startGraph)
{
    if (startGraph < 0 || startGraph >= vertices.size() || vertices[startGraph].ellipse == nullptr) {
        QMessageBox::warning(nullptr, "Ошибка", "Неверная начальная вершина");
        return;
    }

    clear();
    clearT();

    QQueue<int> queue;
    queue.enqueue(startGraph);
    visited[startGraph] = true;

    QString order = "BFS: ";

    while (!queue.isEmpty()) {
        int v = queue.dequeue();
        bfsTraversal.append(v);
        order += QString::number(v) + " ";

        for (int i = 0; i < vertices.size(); ++i) {
            if (adjacencyMatrix[v][i] != 0 && !visited[i]) {
                visited[i] = true;
                queue.enqueue(i);
            }
        }
    }

    QMessageBox::information(nullptr, "Обход в ширину", order);
}

void GraphWidget::dSearch(int startGraph)
{
    if (startGraph < 0 || startGraph >= vertices.size() || vertices[startGraph].ellipse == nullptr) {
        QMessageBox::warning(nullptr, "Ошибка", "Неверная начальная вершина");
        return;
    }

    clear();
    clearT();

    Recursive(startGraph);

    QString order = "DFS: ";
    for (int v : dfsTraversal) {
        order += QString::number(v) + " ";
    }

    QMessageBox::information(nullptr, "Обход в глубину", order);
}

void GraphWidget::Recursive(int Graph)
{
    visited[Graph] = true;
    dfsTraversal.append(Graph);

    for (int i = 0; i < vertices.size(); ++i) {
        if (adjacencyMatrix[Graph][i] != 0 && !visited[i]) {
            Recursive(i);
        }
    }
}

void GraphWidget::dextersomeothing(int startGraph, int endGraph)
{
    if (startGraph < 0 || startGraph >= vertices.size() || vertices[startGraph].ellipse == nullptr ||
        endGraph < 0 || endGraph >= vertices.size() || vertices[endGraph].ellipse == nullptr) {
        QMessageBox::warning(nullptr, "Ошибка", "Неверные вершины");
        return;
    }

    int n = vertices.size();
    QVector<int> dist(n, INT_MAX);
    QVector<int> prev(n, -1);
    QVector<bool> visited(n, false);

    dist[startGraph] = 0;

    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }

        if (v == -1 || dist[v] == INT_MAX) {
            break;
        }

        visited[v] = true;

        for (int to = 0; to < n; ++to) {
            if (adjacencyMatrix[v][to] != 0) {
                int alt = dist[v] + edgeWeights[v][to];
                if (alt < dist[to]) {
                    dist[to] = alt;
                    prev[to] = v;
                }
            }
        }
    }

    if (dist[endGraph] == INT_MAX) {
        QMessageBox::information(nullptr, "Алгоритм Дейкстры", "Путь не существует");
        return;
    }

    QVector<int> path;
    for (int v = endGraph; v != -1; v = prev[v]) {
        path.prepend(v);
    }

    QString pathStr;
    for (int v : path) {
        pathStr += QString::number(v) + " ";
    }

    QMessageBox::information(nullptr, "Алгоритм Дейкстры",
                             QString("Кратчайшее расстояние: %1\nПуть: %2").arg(dist[endGraph]).arg(pathStr));

    highlightPath(path, Qt::red);
}

void GraphWidget::floyd()
{
    int n = vertices.size();
    if (n == 0) return;

    QVector<QVector<int>> dist(n, QVector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (adjacencyMatrix[i][j] != 0) {
                dist[i][j] = edgeWeights[i][j];
            } else {
                dist[i][j] = INT_MAX / 2;
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    QString result = "Матрица кратчайших расстояний:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INT_MAX / 2) {
                result += "∞ ";
            } else {
                result += QString::number(dist[i][j]) + " ";
            }
        }
        result += "\n";
    }

    QMessageBox::information(nullptr, "Алгоритм Флойда-Уоршелла", result);
}

void GraphWidget::solvecomi()
{
    int n = vertices.size();
    if (n < 2) {
        QMessageBox::warning(nullptr, "Ошибка", "Недостаточно вершин для задачи коммивояжера");
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && adjacencyMatrix[i][j] == 0) {
                QMessageBox::warning(nullptr, "Ошибка", "Граф должен быть полным для задачи коммивояжера");
                return;
            }
        }
    }

    QVector<int> GraphIndices;
    for (int i = 0; i < n; ++i) {
        GraphIndices.append(i);
    }

    QVector<int> bestPath;
    int minCost = INT_MAX;

    do {
        int currentCost = 0;
        bool valid = true;

        for (int i = 0; i < n - 1; ++i) {
            int from = GraphIndices[i];
            int to = GraphIndices[i + 1];
            currentCost += edgeWeights[from][to];
        }

        currentCost += edgeWeights[GraphIndices[n - 1]][GraphIndices[0]];

        if (currentCost < minCost) {
            minCost = currentCost;
            bestPath = GraphIndices;
        }

    } while (std::next_permutation(GraphIndices.begin() + 1, GraphIndices.end()));

    QString result = "Оптимальный маршрут: ";
    for (int v : bestPath) {
        result += QString::number(v) + " -> ";
    }
    result += QString::number(bestPath[0]);
    result += QString("\nОбщая стоимость: %1").arg(minCost);

    QMessageBox::information(nullptr, "Задача коммивояжера", result);

    bestPath.append(bestPath[0]);
    highlightPath(bestPath, Qt::blue);
}

void GraphWidget::highlightPath(const QVector<int>& path, const QColor& color) {
    if (path.size() < 2) return;

    const qreal GraphRadius = 15.0;

    for (int i = 0; i < path.size() - 1; ++i) {
        int from = path[i];
        int to = path[i + 1];

        if (from < 0 || to < 0 || from >= vertices.size() || to >= vertices.size() ||
            vertices[from].ellipse == nullptr || vertices[to].ellipse == nullptr) {
            continue;
        }

        QPointF center1(vertices[from].x, vertices[from].y);
        QPointF center2(vertices[to].x, vertices[to].y);

        QPointF direction = center2 - center1;
        qreal length = sqrt(direction.x() * direction.x() + direction.y() * direction.y());

        if (length > 0) {
            direction /= length;
        }

        QPointF startPoint = center1 + direction * GraphRadius;
        QPointF endPoint = center2 - direction * GraphRadius;

        QPen pen(color);
        pen.setWidth(3);
        scene()->addLine(QLineF(startPoint, endPoint), pen);

        vertices[from].ellipse->setBrush(QBrush(color.lighter(150)));
        vertices[to].ellipse->setBrush(QBrush(color.lighter(150)));
    }
}

void GraphWidget::setWaitingForClick(bool waiting, int GraphNumber)
{
    m_waitingForClick = waiting;
    m_nextGraphNumber = GraphNumber;
}

void GraphWidget::mousePressEvent(QMouseEvent *event)
{
    if (m_waitingForClick) {
        QPointF pt = mapToScene(event->pos());
        addGraph(pt.x(), pt.y(), m_nextGraphNumber);
        m_waitingForClick = false;
        m_nextGraphNumber = -1;
        return;
    }
    QGraphicsView::mousePressEvent(event);
}



void GraphWidget::scale(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100) return;
    scale(scaleFactor);
}

void GraphWidget::clear()
{
    visited.clear();
    visited.resize(vertices.size());
    for (int i = 0; i < visited.size(); ++i) {
        visited[i] = false;
    }
}

void GraphWidget::clearT()
{
    bfsTraversal.clear();
    dfsTraversal.clear();
}

void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);
    painter->fillRect(sceneRect(), Qt::white);
}
