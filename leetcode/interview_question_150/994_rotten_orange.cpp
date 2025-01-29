#include <iostream>
#include <vector>
#include <queue>
#include <map>
// #include <pair>
int orangesRotting(std::vector<std::vector<int>>& grid)
{
  int cycle = 0;
  std::queue<std::pair<int, int>> q;
  std::vector<std::vector<int>> dir = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };

  std::pair<int, int> curr;
  int x_size = grid[0].size();
  int y_size = grid.size();

  int fresh_oren = 0;
  int rot_oren = 0;

  // find rotten oranges
  for (int i = 0; i < grid.size(); i++)
  {
    for (int j = 0; j < grid[i].size(); j++)
    {
      if (grid[i][j] == 2)
      {
        q.push(std::make_pair(i, j));
        rot_oren++;
      }
      else if (grid[i][j] == 1)
        fresh_oren++;
    }
  }
  if (rot_oren == 0 && fresh_oren == 0)
    return 0;
  if (rot_oren == 0)
    return -1;
  if (!fresh_oren)
    return 0;

  while (!q.empty())
  {
    int size = q.size();
    bool rotted = false;

    for (int i = 0; i < size; i++)
    {
      curr = q.front();
      q.pop();

      for (auto move : dir)
      {
        int y = curr.first + move[1];
        int x = curr.second + move[0];
        if (x >= 0 && x < x_size && y >= 0 && y < y_size && grid[y][x] == 1)
        {
          grid[y][x] = 2;
          q.push({ y, x });
          rotted = true;
          fresh_oren--;
        }
      }
    }
    if (rotted)
      cycle++;
  }
  if (fresh_oren)
    return -1;
  return cycle;
}

int main()
{
  std::vector<std::vector<int>> grid = { { 2, 1, 1 }, { 0, 1, 1 }, { 1, 0, 1 } };
  std::vector<std::vector<int>> grid = { { 0, 2 } };
  orangesRotting(grid);
  return 0;
}