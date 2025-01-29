#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
void solve(std::vector<std::vector<char>>& board)
{
  int max_row = board.size();
  int max_col = board[0].size();
  std::queue<std::pair<int, int>> queue;
  std::vector<std::pair<int, int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
  for (int row = 0; row < max_row; row++)
  {
    for (int col = 0; col < max_col; col++)
    {
      if (row == 0 || col == 0 || row == max_row - 1 || col == max_col - 1)
      {
        if (board[row][col] == 'O')
        {
          std::cout << "Found O at" << row << ", " << col << std::endl;
          queue.push({ row, col });
          while (!queue.empty())
          {
            auto curr = queue.front();
            queue.pop();
            board[curr.first][curr.second] = 'T';

            for (auto dir : dirs)
            {
              int check_row = curr.first + dir.first;
              int check_col = curr.second + dir.second;
              if (check_row >= 0 && check_row < max_row && check_col >= 0 && check_col < max_col &&
                  board[check_row][check_col] == 'O')
              {
                queue.push({ check_row, check_col });
                board[check_row][check_col] = 'T';
              }
            }
          }
        }
      }
    }
  }

  for (int row = 0; row < max_row; row++)
  {
    for (int col = 0; col < max_col; col++)
    {
      if (board[row][col] == 'O')
        board[row][col] = 'X';
      else if (board[row][col] == 'T')
        board[row][col] = 'O';
    }
  }
}
int main()
{
  std::vector<std::vector<char>> board = {
    { 'X', 'X', 'X', 'X' }, { 'X', 'O', 'O', 'X' }, { 'X', 'O', 'X', 'X' }, { 'X', 'O', 'X', 'X' }
  };
  solve(board);
  return 0;
}