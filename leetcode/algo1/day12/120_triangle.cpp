#include <iostream>
#include <vector>
#include <algorithm>

// dynamic prog method
int minimumTotal(std::vector<std::vector<int>> &triangle)
{
    std::vector<std::vector<int>> memo(triangle.size());
    int row_pointer = triangle.size() - 1;
    while (row_pointer >= 0)
    {
        if (row_pointer == triangle.size() - 1)
            for (auto x : triangle[row_pointer])
                memo[row_pointer].push_back(x);
        else
        {
            memo[row_pointer].resize(triangle[row_pointer].size());
            for (int i = 0; i < triangle[row_pointer].size(); i++)
            {
                memo[row_pointer][i] = std::min(triangle[row_pointer][i] + memo[row_pointer + 1][i], triangle[row_pointer][i] + memo[row_pointer + 1][i + 1]);
            }
        }
        row_pointer--;
    }
    return memo[0][0];
}

int main()
{
    std::vector<std::vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    // std::vector<std::vector<int>> triangle = {{-10}};
    std::cout << minimumTotal(triangle) << std::endl;
}