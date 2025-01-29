#include <vector>
#include <iostream>
bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
{
    int n = matrix.size();    // 3
    int m = matrix[0].size(); // 4

    int left = 0;
    int right = m * n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int row = mid / m;
        int col = mid - row * m;
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int main()
{
    // std::vector<std::vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    std::vector<std::vector<int>> matrix = {{1}};
    int target = 1;
    std::cout << searchMatrix(matrix, target) << std::endl;
}