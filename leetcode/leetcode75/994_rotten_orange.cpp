#include <iostream>
#include <vector>
#include <queue>
#include <map>
std::vector<std::pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int orangesRotting(std::vector<std::vector<int>> &grid)
{
    int rotten = 0;
    int good = 0;
    int row = grid.size();
    int col = grid[0].size();
    std::queue<std::pair<int, int>> q;
    std::map<std::pair<int, int>, bool> visited;
    std::map<std::pair<int, int>, int> time;
    int max_time = 0;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (grid[i][j] == 2)
            {
                rotten++;
                q.push({i, j});
                visited[{i, j}] = true;
                time[{i, j}] = 0;
            }
            else if (grid[i][j] == 1)
                good++;
        }
    }
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        for (auto step : dir)
        {
            int check_i = curr.first + step.first;
            int check_j = curr.second + step.second;
            if (check_i >= 0 && check_i < row && check_j >= 0 && check_j < col && !visited[{check_i, check_j}] && grid[check_i][check_j] == 1)
            {
                good--;
                time[{check_i, check_j}] = time[curr] + 1;
                q.push({check_i, check_j});
                visited[{check_i, check_j}] = true;
                if (time[{check_i, check_j}] > max_time)
                    max_time = time[{check_i, check_j}];
            }
        }
    }
    if (good)
        return -1;
    return max_time;
}
int main()
{
    // std::vector<std::vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    std::vector<std::vector<int>> grid = {{0, 2}};
    auto res = orangesRotting(grid);
    return 0;
}