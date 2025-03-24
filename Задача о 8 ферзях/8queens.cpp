#include <iostream>
#include <cmath>

using namespace std;

int n = 8;
int solutions, maxSolutions;
int* board;

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

void printBoard()
{
    cout << "Solution " << solutions << ":" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << (board[i] == j ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int row)
{
    if (row == n)
    {
        solutions++;
        printBoard();
        if (solutions >= maxSolutions) exit(0);
        return;
    }
    for (int col = 0; col < n; ++col)
    {
        if (isSafe(row, col))
        {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите максимальное количество решений для отображения: ";
    cin >> maxSolutions;
    
    board = new int[n];
    solutions = 0;
    solve(0);
    delete[] board;
    return 0;
}
