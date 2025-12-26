#include <iostream>
using namespace std;

int N;
int board[20][20];

void printSolution()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (board[i][j] == 1)
        cout << "Q ";
      else
        cout << ". ";
    }
    cout << endl;
  }
  cout << endl;
}

bool isSafe(int row, int col)
{
  int i, j;

  // 1. Check this column (upwards)
  for (i = 0; i < row; i++)
    if (board[i][col] == 1)
      return false;

  // 2. Check upper-left diagonal
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j] == 1)
      return false;

  // 3. Check upper-right diagonal
  for (i = row, j = col; i >= 0 && j < N; i--, j++)
    if (board[i][j] == 1)
      return false;

  return true;
}

// Recursive function to solve N Queens
bool solveNQueens(int row)
{
  // Base case: If all queens are placed, print the board
  if (row == N)
  {
    printSolution();
    return true;
  }

  bool res = false;
  for (int col = 0; col < N; col++)
  {
    // Check if placing queen here is safe
    if (isSafe(row, col))
    {
      board[row][col] = 1; // Place queen

      // Recur to place the rest
      res = solveNQueens(row + 1) || res;

      board[row][col] = 0; // BACKTRACK (remove queen)
    }
  }
  return res;
}

int main()
{
  cout << "Enter number of queens (N): ";
  cin >> N;

  // Initialize board with 0
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      board[i][j] = 0;

  solveNQueens(0);

  return 0;
}
