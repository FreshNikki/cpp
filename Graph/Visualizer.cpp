#include "visualizer.h"
#include <GLUT/glut.h>
#include <cmath>
#include <string>

// Координаты вершин
float positions[6][2] = {
    {100, 500}, {150, 350}, {50, 200},
    {300, 100}, {250, 300}, {300, 500}
};
float radius = 20.0f;
Graph* graphPtr = nullptr;

// Функция отрисовки круга (заливка)
void drawCircle(float cx, float cy, float r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; ++i) {
        float angle = 2.0f * 3.1415926f * i / 100;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

// Отрисовка текста по центру
void drawText(float x, float y, const std::string& text) {
    float totalWidth = 0;
    for (char c : text)
        totalWidth += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, c);

    float startX = x - totalWidth / 2.0f;
    float startY = y - 4.0f;

    glRasterPos2f(startX, startY);
    for (char c : text)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

// Основная функция отрисовки графа
void drawGraph(const Graph& g) {
    const auto& matrix = g.getMatrix();

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // === 1. Рисуем рёбра и веса ===
    glColor3f(0.0f, 0.0f, 0.0f); // чёрный цвет
    glLineWidth(1.5f);
    for (int i = 0; i < 6; ++i) {
        for (int j = i + 1; j < 6; ++j) {
            if (matrix[i][j]) {
                // Рисуем ребро
                glBegin(GL_LINES);
                glVertex2f(positions[i][0], positions[i][1]);
                glVertex2f(positions[j][0], positions[j][1]);
                glEnd();

                // Подпись веса
                float midX = (positions[i][0] + positions[j][0]) / 2.0f;
                float midY = (positions[i][1] + positions[j][1]) / 2.0f;
                drawText(midX, midY, std::to_string(matrix[i][j]));
            }
        }
    }

    // === 2. Рисуем вершины (круги) ===
    for (int i = 0; i < 6; ++i) {
        // Белая заливка круга
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(positions[i][0], positions[i][1], radius);

        // Чёрный контур круга
        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);
        for (int j = 0; j <= 100; ++j) {
            float angle = 2.0f * 3.1415926f * j / 100;
            float x = radius * cos(angle);
            float y = radius * sin(angle);
            glVertex2f(positions[i][0] + x, positions[i][1] + y);
        }
        glEnd();

        // Номер вершины
        drawText(positions[i][0], positions[i][1], std::to_string(i + 1));
    }
}

// Обновление окна
void display() {
    drawGraph(*graphPtr);
    glutSwapBuffers();
}

// Адаптация окна при изменении размеров
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Инициализация OpenGL
void initOpenGL() {
    int argc = 1;
    char* argv[1] = { (char*)"OpenGL" };
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Graph Visualization");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // белый фон
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
}
