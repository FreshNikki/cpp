#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTextEdit>
#include <QPushButton>
#include <vector>
#include <iostream>
#include <QTableWidget>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void solveTSP();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTextEdit *output;
    QPushButton *solveButton;
    QTableWidget *matrixTable;
    QTableWidget *pathTable;

    vector<vector<int>> matrix;
    void drawGraph(const vector<int>& path);
    int tspBranchBound(const vector<vector<int>>& graph, vector<int>& bestPath);
    void branch(int level, int currentCost, vector<int>& path, vector<bool>& visited,
                int& bestCost, vector<int>& bestPath);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
