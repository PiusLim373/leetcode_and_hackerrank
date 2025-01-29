#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>
int shortestPathBinaryMatrix(std::vector<std::vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    if (grid[0][0] || grid[m - 1][n - 1])
        return -1;
    if (m == 1 && n == 1)
        return 1;
    std::vector<int> dir_x = {0, 1, 1, 1, 0, -1, -1, -1};
    std::vector<int> dir_y = {-1, -1, 0, 1, 1, 1, 0, -1};

    std::queue<std::pair<int, int>> q;
    std::map<std::pair<int, int>, int> distance;

    q.push({0, 0});
    distance[{0, 0}] = 1;
    grid[0][0] = 1;

    while (!q.empty())
    {
        std::pair<int, int> curr = q.front();
        q.pop();
        for (int i = 0; i < dir_x.size(); i++)
        {
            if (curr.first + dir_x[i] >= 0 &&
                curr.second + dir_y[i] >= 0 &&
                curr.first + dir_x[i] <= m - 1 &&
                curr.second + dir_y[i] <= n - 1 &&
                grid[curr.first + dir_x[i]][curr.second + dir_y[i]] == 0)
            {
                if (curr.first + dir_x[i] == m - 1 && curr.second + dir_y[i] == n - 1)
                    return distance[{curr.first, curr.second}] + 1;
                q.push({curr.first + dir_x[i], curr.second + dir_y[i]});
                grid[curr.first + dir_x[i]][curr.second + dir_y[i]] = 1;
                distance[{curr.first + dir_x[i], curr.second + dir_y[i]}] = distance[{curr.first, curr.second}] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    // std::vector<std::vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    std::vector<std::vector<int>> grid = {{0, 1}, {1, 0}};
    std::cout << shortestPathBinaryMatrix(grid);
}