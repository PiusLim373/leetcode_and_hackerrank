#include <vector>
#include <set>

// void totalNQueensHelper(std::set<int>& col, std::set<int>& pos_diag, std::set<int>& neg_diag,
//                         std::vector<std::vector<int>>& board, int& ans, int r)
void totalNQueensHelper(std::set<int>& col, std::set<int>& pos_diag, std::set<int>& neg_diag, int board_size, int& ans,
                        int r)
{
  if (r == board_size)
  {
    ans++;
    return;
  }
  for (int c = 0; c < board_size; c++)
  {
    auto col_it = col.find(c);
    auto pos_diag_it = pos_diag.find(r + c);
    auto neg_diag_it = neg_diag.find(r - c);
    if (col_it != col.end() || pos_diag_it != pos_diag.end() || neg_diag_it != neg_diag.end())
      continue;

    col.insert(c);
    pos_diag.insert(r + c);
    neg_diag.insert(r - c);
    totalNQueensHelper(col, pos_diag, neg_diag, board_size, ans, r + 1);
    col.erase(c);
    pos_diag.erase(r + c);
    neg_diag.erase(r - c);
  }
}

int totalNQueens(int n)
{
  std::set<int> col;
  std::set<int> pos_diag;  // r+c
  std::set<int> neg_diag;  // r-c
  int ans = 0;

  totalNQueensHelper(col, pos_diag, neg_diag, n, ans, 0);
  return ans;
}

int main()
{
  int n = 4;
  int ans = totalNQueens(n);
  return 0;
}