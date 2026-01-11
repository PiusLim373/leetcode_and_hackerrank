#include <vector>

int minFallingPathSum(std::vector<std::vector<int>> &matrix)
{
    std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix[0].size(); i++)
    {
        dp[0][i] = matrix[0][i];
    }

    for (int row = 1; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[0].size(); col++)
        {
            std::vector<int> check = {dp[row - 1][col]};
            if (col - 1 >= 0)
                check.push_back(dp[row - 1][col - 1]);
            if (col + 1 < matrix[0].size())
                check.push_back(dp[row - 1][col + 1]);

            dp[row][col] = *std::min_element(check.begin(), check.end()) + matrix[row][col];
        }
    }
    return *std::min_element(dp[dp.size() - 1].begin(), dp[dp.size() - 1].end());
}
int main()
{
    // std::vector<std::vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    std::vector<std::vector<int>> matrix = {{-19, 57}, {-40, -5}};
    auto ans = minFallingPathSum(matrix);
    return 0;
}