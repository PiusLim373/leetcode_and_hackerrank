#include <vector>
#include <iostream>

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
{
  int max_row = obstacleGrid.size();
  int max_col = obstacleGrid[0].size();
  if (obstacleGrid[max_row - 1][max_col - 1] || obstacleGrid[0][0])
    return 0;

  std::vector<std::vector<long long>> solutions(max_row, std::vector<long long>(max_col, 0));
  solutions[max_row - 1][max_col - 1] = 1;

  // fill the last row
  for (int i = max_col - 2; i >= 0; i--)
  {
    if (solutions[max_row - 1][i + 1] == 1 && !obstacleGrid[max_row - 1][i])
      solutions[max_row - 1][i] = 1;
    else
      solutions[max_row - 1][i] = 0;
  }

  // fill in the last col
  for (int i = max_row - 2; i >= 0; i--)
  {
    if (solutions[i + 1][max_col - 1] == 1 && !obstacleGrid[i][max_col - 1])
      solutions[i][max_col - 1] = 1;
    else
      solutions[i][max_col - 1] = 0;
  }

  // fill in the rest
  for (int i = max_row - 2; i >= 0; i--)
  {
    for (int j = max_col - 2; j >= 0; j--)
    {
      if (obstacleGrid[i][j] == 1)
        solutions[i][j] = 0;
      else
      {
        solutions[i][j] = solutions[i + 1][j] + solutions[i][j + 1];
      }
    }
  }
  return solutions[0][0];
}

int main()
{
  //   std::vector<std::vector<int>> obstacleGrid = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
  //   std::vector<std::vector<int>> obstacleGrid = { { 0, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 0, 0 }, { 0, 1, 0, 0 } };
  std::vector<std::vector<int>> obstacleGrid = { { 1 } };
  std::cout << uniquePathsWithObstacles(obstacleGrid);
  return 0;
}