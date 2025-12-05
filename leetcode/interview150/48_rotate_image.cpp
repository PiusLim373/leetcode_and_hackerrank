#include <vector>
#include <algorithm>
#include <iostream>

void rotate(std::vector<std::vector<int>> &matrix)
{
    // rotate 90deg  = transpose then swap column
    // transpose
    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = row + 1; col < matrix.size(); col++)
            std::swap(matrix[row][col], matrix[col][row]);
    }

    // mirror
    int left = 0;
    int right = matrix.size() - 1;
    while (left < right)
    {
        for (int row = 0; row < matrix.size(); row++)
            std::swap(matrix[row][left], matrix[row][right]);
        left++;
        right--;
    }
}

int main()
{
    std::vector<std::vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotate(matrix);
    return 0;
}