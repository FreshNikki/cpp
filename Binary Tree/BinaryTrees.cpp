#include <GLUT/glut.h>
#include "BinaryTrees.h"
#include <cmath>

using namespace std;

BinaryTree tree;

int windowWidth = 800;
int windowHeight = 600;
float nodeRadius = 20.0f;

void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; ++i)
    {
        float angle = 2 * M_PI * i / 100;
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();
}

void drawText(float x, float y, const char* text)
{
    int textWidth = 0;
    for (const char* c = text; *c; ++c)
    {
        textWidth += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, *c);
    }

    glRasterPos2f(x - textWidth / 2.0f, y - 5);
    for (const char* c = text; *c; ++c)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void drawArrow(float x1, float y1, float x2, float y2, float radius);

void drawTree(Node* node, float x, float y, float offsetX, float offsetY)
{
    if (!node) return;

    if (node->left)
    {
        drawArrow(x, y, x - offsetX, y - offsetY, nodeRadius);
        drawTree(node->left, x - offsetX, y - offsetY, offsetX / 1.8f, offsetY);
    }
    if (node->right)
    {
        drawArrow(x, y, x + offsetX, y - offsetY, nodeRadius);
        drawTree(node->right, x + offsetX, y - offsetY, offsetX / 1.8f, offsetY);
    }

    glColor3f(1, 1, 1); // белая заливка
    drawCircle(x, y, nodeRadius);

    glColor3f(0, 0, 0); // черная обводка
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 100; ++i)
    {
        float angle = 2 * M_PI * i / 100;
        glVertex2f(x + cos(angle) * nodeRadius, y + sin(angle) * nodeRadius);
    }
    glEnd();

    string text = to_string(node->key);
    glColor3f(0, 0, 0);
    drawText(x, y, text.c_str());
}

void drawArrow(float x1, float y1, float x2, float y2, float radius)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float len = sqrt(dx * dx + dy * dy);
    dx /= len;
    dy /= len;

    float startX = x1 + dx * radius;
    float startY = y1 + dy * radius;
    float endX = x2 - dx * radius;
    float endY = y2 - dy * radius;

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(startX, startY);
    glVertex2f(endX, endY);
    glEnd();

    float arrowLength = 10.0f;
    float arrowAngle = M_PI / 6;
    float angle = atan2(dy, dx);

    float x3 = endX - arrowLength * cos(angle - arrowAngle);
    float y3 = endY - arrowLength * sin(angle - arrowAngle);
    float x4 = endX - arrowLength * cos(angle + arrowAngle);
    float y4 = endY - arrowLength * sin(angle + arrowAngle);

    glBegin(GL_TRIANGLES);
    glVertex2f(endX, endY);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawTree(tree.root, windowWidth / 2, windowHeight - 50, 150.0f, 70.0f);
    glColor3f(0, 0, 0);
    glutSwapBuffers();
    glLoadIdentity();
    drawTree(tree.root, windowWidth / 2, windowHeight - 50, 150.0f, 70.0f);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, w, 0, h);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
}

int main(int argc, char** argv)
{
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.balance();

    cout << "Max value in tree: " << tree.findMax() << "\n";
    cout << "Inorder: "; tree.inorder();
    
    cout << "Горизонтальная печать дерева:\n";
    tree.printHorizontal();

    cout << "\nВертикальная печать дерева:\n";
    tree.printVertical();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Binary Tree Visualization");

    glClearColor(1, 1, 1, 1); // белый фон

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(glutPostRedisplay);

    glutMainLoop();

    return 0;
}
