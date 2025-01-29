#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
int maximalSquare(std::vector<std::vector<char>>& matrix)
{
  if (!matrix.size())
    return 0;
  int max_row = matrix.size();
  int max_col = matrix[0].size();

  int longest_edge = 0;
  std::vector<std::vector<int>> square_length(max_row, std::vector<int>(max_col, 0));

  //  the last row
  for (int col = 0; col < max_col; col++)
  {
    if (matrix[max_row - 1][col] == '0')
      square_length[max_row - 1][col] = 0;
    else
    {
      square_length[max_row - 1][col] = 1;
      longest_edge = 1;
    }
  }

  // the last col
  for (int row = 0; row < max_row; row++)
  {
    if (matrix[row][max_col - 1] == '0')
      square_length[row][max_col - 1] = 0;
    else
    {
      square_length[row][max_col - 1] = 1;
      longest_edge = 1;
    }
  }

  // loop for last to first;
  for (int row = max_row - 2; row >= 0; row--)
  {
    for (int col = max_col - 2; col >= 0; col--)
    {
      if (matrix[row][col] == '0')
        square_length[row][col] = 0;

      else
      {
        int right_neigh = square_length[row][col + 1];
        int bot_neigh = square_length[row + 1][col];
        int diag_neigh = square_length[row + 1][col + 1];

        if (right_neigh == 0 || bot_neigh == 0 || diag_neigh == 0)
          square_length[row][col] = 1;
        else if (right_neigh == bot_neigh && bot_neigh == diag_neigh && diag_neigh == right_neigh)
          square_length[row][col] = right_neigh + 1;
        else
          square_length[row][col] = std::min({ right_neigh, bot_neigh, diag_neigh }) + 1;

        if (square_length[row][col] > longest_edge)
          longest_edge = square_length[row][col];
      }
    }
  }

  for (const auto& row : square_length)
  {
    for (const auto& val : row)
    {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  return pow(longest_edge, 2);
}
int main()
{
  //   std::vector<std::vector<char>> matrix = {
  //     { '1', '0', '1', '0', '0' }, { '1', '0', '1', '1', '1' }, { '1', '1', '1', '1', '1' }, { '1', '0', '0', '1',
  //     '0' }
  //   };
  std::vector<std::vector<char>> matrix = { { '1', '1', '1', '1', '0' },
                                            { '1', '1', '1', '1', '0' },
                                            { '1', '1', '1', '1', '1' },
                                            { '1', '1', '1', '1', '1' },
                                            { '0', '0', '1', '1', '1' } };

  //   std::vector<std::vector<char>> matrix = { { '1' }, { '1' } };

  int ans = maximalSquare(matrix);
  return 0;
}