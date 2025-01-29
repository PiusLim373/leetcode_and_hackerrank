#include <vector>
#include <iostream>
#include <string>

std::string convert(std::string s, int numRows)
{
  if (numRows == 1)
    return s;

  std::string ans;
  for (int row = 0; row < numRows; row++)
  {
    int increment = 2 * (numRows - 1);
    for (int index = row; index < s.size(); index += increment)  // row 1 starts at index1, row2 starts at index 2 ...
    {
      ans += s[index];  // for all row
      if (row > 0 && row < numRows - 1 && (index + increment - (2 * row)) < s.size())   // do this for non first and last row, want to add in the second char of the zigzag, it is like a 'V' char, where separation at higher is big and lower is small
      {
        ans += s[index + increment - 2 * row];              
      }
    }
  }
  return ans;
}
std::string convertNotWorking(std::string s, int numRows)
{
  if (numRows == 1)
    return s;
  int char_per_group = 2 * numRows - 2;
  int col_per_group = numRows - 1;
  int numCols = s.size() / char_per_group * col_per_group + s.size() % char_per_group;
  //   int numCols = s.size() / numRows + s.size() % numRows;

  std::vector<std::vector<char>> board(numRows, std::vector<char>(numCols, '*'));
  int index = 0;
  int mode = 0;

  int col = 0;
  int row = 0;
  while (index < s.size())
  {
    // fill in row top to bot
    if (mode == 0)
    {
      while (row < numRows && index < s.size())
      {
        board[row][col] = s[index];
        index++;
        row++;
      }
      mode = 1;
      row -= 2;
      col++;
    }
    else if (mode == 1)
    {
      // fill diagonal upwards
      while (row > 0 && index < s.size())
      {
        board[row][col] = s[index];
        row--;
        col++;
        index++;
      }
      mode = 0;
    }
  }

  std::string ans;
  for (auto x : board)
  {
    for (auto y : x)
    {
      std::cout << y << " ";
      if (y != '*')
        ans += y;
    }
    std::cout << std::endl;
  }

  return ans;
}

int main()
{
    std::string s = "PAYPALISHIRING";
    int numRows = 4;

//   std::string s =
//       "ucqxswyqdntdmfrtzlqsekejhzksklfepxchvczysvdgcxbbiswmeaylzifktmoikssfxtgpojxqiysrsqfwqdjqnqcgdqrnlluieazvmwnuufnn"
//       "xvloyvgmliuqandlyavfauaosnlnvacsvpiumoiawcqxswkqwgxyazntnaikameybnuqbcqaggxachrynqxqqmlfotpqhvokiiammqmvxjvbsoai"
//       "fzyxnjcberrnmixxsyjhovengbpyqrixqgwdrygxrxkfhicainhwilkqmbpeszdigznzxtzqsjwatycbmjawwmninepfduplucltxmkpvgrrgtus"
//       "eurageltkcapwpbqromqawixezqkvlfbhwcocpjmrmbpbegvsuluqtuuvkesvjtdhvtjmexfqbvufdpaxcwnwqjtbplyzedicwsodpwtqrpyuear"
//       "hwgfnpaqelofrsotqiktxipqzeqvlqmuoubbjbrpmixfclbstnosvdkujcpwsdqhxrkiueziowoqjpiecwxxbjtnmkjgncpmvauqgtausokbfugj"
//       "tfiu";
//   int numRows = 199;
  auto ans = convert(s, numRows);
  return 0;
}