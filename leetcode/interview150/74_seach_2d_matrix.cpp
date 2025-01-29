#include <iostream>
#include <vector>

int getMatrix(std::vector<std::vector<int>>& matrix, int index)
{
  int row = matrix.size();
  int col = matrix[0].size();
  int target_row = index / col;
  int target_col = index % col;
  return matrix[target_row][target_col];
}

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
{
  int row = matrix.size();
  int col = matrix[0].size();
  int low = 0;
  int high = row * col - 1;

  while (high >= low)
  {
    int mid = low + (high - low) / 2;
    if (getMatrix(matrix, mid) == target)
      return true;
    else if (target > getMatrix(matrix, mid))
      low = mid + 1;
    else
      high = mid - 1;
  }
  return false;
}

int main()
{
//   std::vector<std::vector<int>> matrix = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
  std::vector<std::vector<int>> matrix = { { 1, 1 } };
  int target = 2;
  std::cout << searchMatrix(matrix, target);
  return 0;
}