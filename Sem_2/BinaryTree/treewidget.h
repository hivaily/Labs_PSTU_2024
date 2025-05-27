    #ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <QPainter>
#include "treeclass.h"

class TreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = nullptr);
    void setTree(Tree* tree);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Tree* ttree;
    void drawNode(QPainter& painter, Tree::Node* node);
    void drawConnection(QPainter& painter, Tree::Node* parent, Tree::Node* child);
    void drawConnections(QPainter& painter, Tree::Node* node);
    void drawNodes(QPainter& painter, Tree::Node* node);
};

#endif // TREEWIDGET_H
