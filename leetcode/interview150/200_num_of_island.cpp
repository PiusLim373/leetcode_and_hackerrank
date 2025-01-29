#include <vector>
#include <iostream>
#include <queue>
#include <map>

int numIslands(std::vector<std::vector<char>>& grid)
{
  std::queue<std::pair<int, int>> q;
  std::map<std::pair<int, int>, bool> has_visited;
  std::vector<std::pair<int, int>> direction = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
  int row = grid.size();
  int col = grid[0].size();
  int island_count = 0;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (grid[i][j] == '1' && !has_visited[{ i, j }])
      {
        island_count++;
        q.push({ i, j });
      }
      while (!q.empty())
      {
        std::pair<int, int> current = q.front();
        q.pop();
        has_visited[current] = true;
        for (auto x : direction)
        {
          int check_x = current.first + x.first;
          int check_y = current.second + x.second;
          //   std::cout << has_visited[{check_x, check_y}] << std::endl;
          if (check_x >= 0 && check_y >= 0 && check_x < row and check_y < col && grid[check_x][check_y] == '1' &&
              !has_visited[{ check_x, check_y }])
          {
            q.push({ check_x, check_y });
            has_visited[{ check_x, check_y }] = true;
          }
        }
      }
    }
  }
  return island_count;
}
int main()
{
//   std::vector<std::vector<char>> grid = {
//     { '1', '1', '1', '1', '0' }, { '1', '1', '0', '1', '0' }, { '1', '1', '0', '0', '0' }, { '0', '0', '0', '0', '0' }
//   };
    std::vector<std::vector<char>> grid = {
      { '1', '1', '0', '0', '0' }, { '1', '1', '0', '0', '0' }, { '0', '0', '1', '0', '0' }, { '0', '0', '0', '1',
      '1' }
    };
  std::cout << numIslands(grid);
}