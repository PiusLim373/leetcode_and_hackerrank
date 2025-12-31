#include <vector>
bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
{
    int start_row = 0;
    int start_col = matrix[0].size() - 1;

    while (start_col >= 0 && start_row < matrix.size())
    {
        int check = matrix[start_row][start_col];
        if (target == check)
            return true;
        else if (check > target)
            start_col--;
        else
            start_row++;
    }
    return false;
}

int main()
{
    // std::vector<std::vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    std::vector<std::vector<int>> matrix = {{1}};
    int target = 1;

    auto ans = searchMatrix(matrix, target);
    return 0;
}