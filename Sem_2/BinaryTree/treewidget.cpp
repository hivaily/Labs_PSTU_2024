#include "treewidget.h"


TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent), ttree(nullptr)
{
    setMinimumSize(600, 600);
}


void TreeWidget::setTree(Tree *tree)
{
    ttree = tree;
    if (ttree)
    {
        ttree->calculate(width());
    }
    update();
}

void TreeWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    drawConnections(painter, ttree->getRoot());
    drawNodes(painter, ttree->getRoot());
}

void TreeWidget::drawConnections(QPainter& painter, Tree::Node* node)
{
    if (!node) return;

    if (node->left)
    {
        drawConnection(painter, node, node->left);
        drawConnections(painter, node->left);
    }

    if (node->right)
    {
        drawConnection(painter, node, node->right);
        drawConnections(painter, node->right);
    }
}

void TreeWidget::drawConnection(QPainter& painter, Tree::Node* parent, Tree::Node* child)
{
    painter.setPen(QPen(Qt::black, 1));
    painter.drawLine(parent->x + 10, parent->y + 10, child->x + 10, child->y + 10);
}

void TreeWidget::drawNodes(QPainter& painter, Tree::Node* node)
{
    if (!node) return;

    painter.setPen(QPen(Qt::black, 1));
    painter.setBrush(QBrush(Qt::white));
    painter.drawEllipse(node->x, node->y, 20, 20);

    painter.setPen(Qt::black);
    QFont font = painter.font();
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(QRect(node->x, node->y, 20, 20), Qt::AlignCenter, QString::number(node->key));

    drawNodes(painter, node->left);
    drawNodes(painter, node->right);
}
