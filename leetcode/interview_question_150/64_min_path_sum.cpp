#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

// solution using dp
int minPathSum(std::vector<std::vector<int>>& grid)
{
  int max_row = grid.size();
  int max_col = grid[0].size();

  std::vector<std::vector<int>> dp(max_row, std::vector<int>(max_col, 0));
  dp[0][0] = grid[0][0];

  for (int col = 1; col < max_col; col++)
  {
    dp[0][col] = grid[0][col] + dp[0][col - 1];
  }

  for (int row = 1; row < max_row; row++)
  {
    dp[row][0] = grid[row][0] + dp[row - 1][0];
  }

  for (int i = 1; i < max_row; i++)
  {
    for (int j = 1; j < max_col; j++)
    {
      dp[i][j] = grid[i][j] + std::min(dp[i][j - 1], dp[i - 1][j]);
    }
  }
  return dp[max_row - 1][max_col - 1];
}
int minPathSum_bfs(std::vector<std::vector<int>>& grid)
{
  int max_row = grid.size();
  int max_col = grid[0].size();

  if (max_row == 1 && max_col == 1)
    return grid[0][0];
  std::vector<std::pair<int, int>> directions = { { 1, 0 }, { 0, 1 } };
  std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>,
                      std::greater<>>
      pq;
  pq.push({ grid[0][0], { 0, 0 } });
  std::map<std::pair<int, int>, bool> visited;

  while (!pq.empty())
  {
    auto [cost, curr] = pq.top();
    pq.pop();
    visited[curr] = true;
    for (auto dir : directions)
    {
      int new_row = curr.first + dir.first;
      int new_col = curr.second + dir.second;

      if (new_row >= 0 && new_row < max_row && new_col >= 0 && new_col < max_col && !visited[{ new_row, new_col }])
      {
        int new_cost = grid[new_row][new_col] + cost;
        if (new_row == max_row - 1 && new_col == max_col - 1)
          return new_cost;
        pq.push({ new_cost, { new_row, new_col } });
        visited[{ new_row, new_col }] = true;
      }
    }
  }

  return -1;
}
int main()
{
  std::vector<std::vector<int>> grid = { { 1, 30, 1 }, { 1, 5, 10 }, { 40, 2, 1 } };

//   std::vector<std::vector<int>> grid = {
//     { 7, 1, 3, 5, 8, 9, 9, 2, 1, 9, 0, 8, 3, 1, 6, 6, 9, 5 }, { 9, 5, 9, 4, 0, 4, 8, 8, 9, 5, 7, 3, 6, 6, 6, 9, 1, 6 },
//     { 8, 2, 9, 1, 3, 1, 9, 7, 2, 5, 3, 1, 2, 4, 8, 2, 8, 8 }, { 6, 7, 9, 8, 4, 8, 3, 0, 4, 0, 9, 6, 6, 0, 0, 5, 1, 4 },
//     { 7, 1, 3, 1, 8, 8, 3, 1, 2, 1, 5, 0, 2, 1, 9, 1, 1, 4 }, { 9, 5, 4, 3, 5, 6, 1, 3, 6, 4, 9, 7, 0, 8, 0, 3, 9, 9 },
//     { 1, 4, 2, 5, 8, 7, 7, 0, 0, 7, 1, 2, 1, 2, 7, 7, 7, 4 }, { 3, 9, 7, 9, 5, 8, 9, 5, 6, 9, 8, 8, 0, 1, 4, 2, 8, 2 },
//     { 1, 5, 2, 2, 2, 5, 6, 3, 9, 3, 1, 7, 9, 6, 8, 6, 8, 3 }, { 5, 7, 8, 3, 8, 8, 3, 9, 9, 8, 1, 9, 2, 5, 4, 7, 7, 7 },
//     { 2, 3, 2, 4, 8, 5, 1, 7, 2, 9, 5, 2, 4, 2, 9, 2, 8, 7 }, { 0, 1, 6, 1, 1, 0, 0, 6, 5, 4, 3, 4, 3, 7, 9, 6, 1, 9 }
//   };
  std::cout << minPathSum(grid);
  return 0;
}