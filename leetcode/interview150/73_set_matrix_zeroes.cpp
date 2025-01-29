#include <vector>
#include <set>
#include <iostream>
void setZeroes(std::vector<std::vector<int>> &matrix)
{
    std::set<int> row_to_zero;
    std::set<int> col_to_zero;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                row_to_zero.insert(i);
                col_to_zero.insert(j);
            }
        }
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        bool zero_row = false;
        auto it = row_to_zero.find(i);
        if (it != row_to_zero.end())
            zero_row = true;
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (zero_row)
            {
                matrix[i][j] = 0;
                continue;
            }
            auto it2 = col_to_zero.find(j);
            if (it2 != col_to_zero.end())
            {
                matrix[i][j] = 0;
            }
        }
    }
}
int main()
{
    // std::vector<std::vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    std::vector<std::vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes(matrix);

    for (auto x : matrix)
    {
        for (auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
    }
}