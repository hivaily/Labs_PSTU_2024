#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include <QVector>
#include <QMouseEvent>
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QQueue>
#include <QStack>
#include <QGraphicsScene>
#include <QPainter>
#include <QWheelEvent>
#include <QMessageBox>
#include <QInputDialog>
#include <QColorDialog>
#include <climits>
#include <algorithm>
#include <QDebug>
#include <cmath>

struct Graph {
    int x, y;
    QGraphicsEllipseItem* ellipse = nullptr;
    QGraphicsTextItem* label = nullptr;
};

class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GraphWidget(QWidget *parent = nullptr);
    ~GraphWidget();
    void bSearch(int startGraph);
    void dSearch(int startGraph);
    void dextersomeothing(int startGraph, int endGraph);
    void floyd();
    void solvecomi();
    void addGraph(int x, int y, int number);
    void removeGraph(int index);
    void addEdge(int from, int to);
    void removeEdge(int from, int to);
    void setEdge(int from, int to, int weight);
    void setMatrix(const QVector<QVector<int>> &matrix);
    void setWaitingForClick(bool waiting, int GraphNumber);
    int GraphCount() const { return vertices.size(); }
    QVector<QVector<int>> getAdjacencyMatrix() const;


protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    void scale(qreal scaleFactor);
    void clear();
    void clearT();
    void Recursive(int Graph);
    void redraw();
    void highlightPath(const QVector<int>& path, const QColor& color);
    bool m_waitingForClick = false;
    int m_nextGraphNumber = -1;
    QVector<Graph> vertices;
    QVector<QVector<int>> adjacencyMatrix;
    QVector<QVector<int>> edgeWeights;
    QVector<bool> visited;
    QVector<int> bfsTraversal;
    QVector<int> dfsTraversal;
    QVector<QGraphicsLineItem*> edgeLines;
    QVector<QGraphicsTextItem*> edgeLabels;

};

#endif // GRAPHWIDGET_H
