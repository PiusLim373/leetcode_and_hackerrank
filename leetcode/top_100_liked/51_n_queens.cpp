#include <vector>
#include <string>
#include <unordered_set>

void recv(int row,
          int &n,
          std::unordered_set<int> &blocked_col,
          std::unordered_set<int> &blocked_p_diag, // row+col
          std::unordered_set<int> &blocked_n_diag, // row-col
          std::vector<std::string> curr,
          std::vector<std::vector<std::string>> &ans)
{
    if (row >= n)
    {
        ans.push_back(curr);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (!blocked_col.contains(col) && !blocked_p_diag.contains(row + col) && !blocked_n_diag.contains(row - col))
        {
            curr[row][col] = 'Q';
            blocked_col.insert(col);
            blocked_p_diag.insert(row + col);
            blocked_n_diag.insert(row - col);
            recv(row + 1, n, blocked_col, blocked_p_diag, blocked_n_diag, curr, ans);

            curr[row][col] = '.';
            blocked_col.erase(col);
            blocked_p_diag.erase(row + col);
            blocked_n_diag.erase(row - col);
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n)
{
    int max_row = n;
    int max_col = n;
    std::unordered_set<int> blocked_col, blocked_p_diag, blocked_n_diag;
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> curr(n, std::string(n, '.'));

    recv(0, n, blocked_col, blocked_p_diag, blocked_n_diag, curr, ans);
    return ans;
}
int main()
{
    int n = 9;
    auto ans = solveNQueens(n);
    return 0;
}