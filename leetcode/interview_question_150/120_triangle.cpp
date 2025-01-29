#include <vector>
int minimumTotal(std::vector<std::vector<int>>& triangle)
{
  if (!triangle.size())
    return 0;
  for (int i = triangle.size() - 2; i >= 0; i--)
  {
    for (int j = 0; j < triangle[i].size(); j++)
    {
      int curr = triangle[i][j];
      triangle[i][j] = std::min(curr + triangle[i + 1][j], curr + triangle[i + 1][j + 1]);
    }
  }
  return triangle[0][0];
}

int main()
{
  std::vector<std::vector<int>> triangle = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
  std::vector<std::vector<int>> triangle = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
  int ans = minimumTotal(triangle);
  return 0;
}