#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>

bool existHelper(std::vector<std::vector<char>>& board, std::string word, int index, int row, int col)
{
  if (index == word.size())
    return true;

  if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index])
    return false;

  char temp = board[row][col];
  board[row][col] = '#';
  std::vector<std::pair<int, int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
  for (auto dir : dirs)
  {
    int check_row = row + dir.first;
    int check_col = col + dir.second;
    if (existHelper(board, word, index + 1, check_row, check_col))
      return true;
  }
  board[row][col] = temp;
  return false;
}

bool exist(std::vector<std::vector<char>>& board, std::string word)
{
  int max_row = board.size();
  int max_col = board[0].size();
  bool success = false;
  for (int row = 0; row < max_row; row++)
  {
    for (int col = 0; col < max_col; col++)
    {
      if (board[row][col] == word[0])
      {
        success = existHelper(board, word, 0, row, col);
        if (success)
          return true;
      }
    }
  }
  return false;
}
bool exist_BFS_INCORRECT(std::vector<std::vector<char>>& board, std::string word)
{
  int max_row = board.size();
  int max_col = board[0].size();
  std::vector<std::pair<int, int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

  for (int row = 0; row < max_row; row++)
  {
    for (int col = 0; col < max_col; col++)
    {
      if (board[row][col] == word[0])
      {
        int index = 0;
        std::vector<std::vector<bool>> visited(max_row, std::vector<bool>(max_col, false));
        std::queue<std::pair<int, int>> queue;
        queue.push({ row, col });
        visited[row][col] = true;

        while (!queue.empty())
        {
          auto [curr_row, curr_col] = queue.front();
          queue.pop();
          index++;

          for (auto dir : dirs)
          {
            int check_row = curr_row + dir.first;
            int check_col = curr_col + dir.second;
            if (check_row >= 0 && check_row < max_row && check_col >= 0 && check_col < max_col &&
                !visited[check_row][check_col] && board[check_row][check_col] == word[index])
            {
              std::cout << "added" << word[index] << std::endl;
              if (index + 1 == word.size())
                return true;
              visited[check_row][check_col] = true;
              queue.push({ check_row, check_col });
            }
          }
        }
      }
    }
  }
  return false;
}
int main()
{
  //   std::vector<std::vector<char>> board = { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' }
  //   }; std::string word = "ABCCE";

  std::vector<std::vector<char>> board = { { 'Z', 'B', 'C', 'E' }, { 'S', 'A', 'B', 'S' }, { 'A', 'D', 'E', 'E' } };
  std::string word = "ABCBZ";
  bool ans = exist(board, word);
  return 0;
}