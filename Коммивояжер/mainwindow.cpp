#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <cmath>
#include <limits>
#include <iostream>
#include <QHeaderView>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    solveButton = new QPushButton("Решить", this);
    output = new QTextEdit(this);
    output->setReadOnly(true);
    matrixTable = new QTableWidget(this);
    matrixTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    pathTable = new QTableWidget(this);
    pathTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    layout->addWidget(new QLabel("Маршрут:"));
    layout->addWidget(pathTable);

    layout->addWidget(new QLabel("Матрица расстояний:"));
    layout->addWidget(matrixTable);
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    view->setScene(scene);

    layout->addWidget(view);
    layout->addWidget(solveButton);
    layout->addWidget(new QLabel("Результат:"));
    layout->addWidget(output);

    setCentralWidget(central);
    setWindowTitle("Коммивояжер — ветви и границы");
    resize(700, 800);

    matrix = {
        {0, 8, 0, 0, 0, 11},
        {8, 0, 12, 0, 10, 0},
        {0, 12, 0, 16, 0, 0},
        {0, 0, 16, 0, 5, 9},
        {0, 10, 0, 5, 0, 6},
        {11, 0, 0, 9, 6, 0}
    };

    connect(solveButton, &QPushButton::clicked, this, &MainWindow::solveTSP);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::solveTSP() {
    vector<int> path;
    int cost = tspBranchBound(matrix, path);

    output->clear();
    output->append("Минимальная стоимость: " + QString::number(cost));
    output->append("Маршрут:");
    for (int node : path)
        output->append("Вершина " + QString::number(node + 1));

    int n = matrix.size();
    matrixTable->setRowCount(n);
    matrixTable->setColumnCount(n);
    matrixTable->setHorizontalHeaderLabels(QStringList());
    matrixTable->setVerticalHeaderLabels(QStringList());

    matrixTable->horizontalHeader()->setStretchLastSection(true);
    matrixTable->verticalHeader()->setStretchLastSection(true);
    matrixTable->resizeColumnsToContents();
    matrixTable->resizeRowsToContents();

    // Таблица маршрута
    pathTable->clear();
    pathTable->setRowCount(path.size() - 1);
    pathTable->setColumnCount(3);
    pathTable->setHorizontalHeaderLabels(QStringList() << "От" << "До" << "Расстояние");

    int total = 0;
    for (int i = 0; i < path.size() - 1; ++i) {
        int from = path[i];
        int to = path[i + 1];
        int dist = matrix[from][to];

        pathTable->setItem(i, 0, new QTableWidgetItem(QString::number(from + 1)));
        pathTable->setItem(i, 1, new QTableWidgetItem(QString::number(to + 1)));
        pathTable->setItem(i, 2, new QTableWidgetItem(QString::number(dist)));

        total += dist;
    }

    pathTable->resizeColumnsToContents();
    pathTable->resizeRowsToContents();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            QString value = (matrix[i][j] > 0 || i == j)
            ? QString::number(matrix[i][j])
            : "∞";
            matrixTable->setItem(i, j, new QTableWidgetItem(value));
        }
    }


    drawGraph(path);
}

int MainWindow::tspBranchBound(const vector<vector<int>>& graph, vector<int>& bestPath) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> path = {5};
    visited[5] = true;

    int bestCost = numeric_limits<int>::max();
    branch(1, 0, path, visited, bestCost, bestPath);
    return bestCost;
}

void MainWindow::branch(int level, int currentCost, vector<int>& path, vector<bool>& visited,
                        int& bestCost, vector<int>& bestPath) {
    int n = matrix.size();

    if (level == n) {
        int totalCost = currentCost + matrix[path.back()][path[0]];
        if (totalCost < bestCost) {
            bestCost = totalCost;
            bestPath = path;
            bestPath.push_back(0);
        }
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && matrix[path.back()][i] > 0) {
            int nextCost = currentCost + matrix[path.back()][i];
            if (nextCost < bestCost) {
                visited[i] = true;
                path.push_back(i);
                branch(level + 1, nextCost, path, visited, bestCost, bestPath);
                visited[i] = false;
                path.pop_back();
            }
        }
    }
}

void MainWindow::drawGraph(const vector<int>& path) {
    scene->clear();

    int n = matrix.size();
    const int radius = 20;
    const int centerX = 300, centerY = 300, graphRadius = 200;

    QVector<QPointF> positions;

    for (int i = 0; i < n; ++i) {
        double angle = 2 * M_PI * i / n;
        double x = centerX + graphRadius * cos(angle);
        double y = centerY + graphRadius * sin(angle);
        positions.append(QPointF(x, y));

        scene->addEllipse(x - radius/2, y - radius/2, radius, radius,
                          QPen(Qt::black), QBrush(Qt::yellow));
        QGraphicsTextItem *text = scene->addText(QString::number(i + 1));
        text->setPos(x + 10, y + 10);
    }

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (matrix[i][j] > 0)
                scene->addLine(positions[i].x(), positions[i].y(),
                               positions[j].x(), positions[j].y(),
                               QPen(Qt::gray));

    for (size_t i = 1; i < path.size(); ++i) {
        int from = path[i - 1];
        int to = path[i];
        scene->addLine(QLineF(positions[from], positions[to]), QPen(Qt::red, 3));
    }

}
