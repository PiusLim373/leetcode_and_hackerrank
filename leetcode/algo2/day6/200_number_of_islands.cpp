#include <vector>
#include <iostream>
#include <queue>
#include <utility>
int numIslands(std::vector<std::vector<char>> &grid)
{
    int m = grid.size();    // vertical;
    int n = grid[0].size(); // horizontal;
    int island_count = 0;

    std::vector<int> dir_x = {0, 1, 0, -1};
    std::vector<int> dir_y = {-1, 0, 1, 0};

    std::queue<std::pair<int, int>> visit_queue;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                visit_queue.push(std::make_pair(i, j));
                grid[i][j] = '0';
                while (!visit_queue.empty())
                {
                    std::pair curr = visit_queue.front();
                    visit_queue.pop();
                    for (int k = 0; k < dir_x.size(); k++)
                    {
                        if (curr.first + dir_x[k] >= 0 && curr.second + dir_y[k] >= 0 && curr.first + dir_x[k] < m && curr.second + dir_y[k] < n && grid[curr.first + dir_x[k]][curr.second + dir_y[k]] != '0')
                        {
                            visit_queue.push(std::make_pair(curr.first + dir_x[k], curr.second + dir_y[k]));
                            grid[curr.first + dir_x[k]][curr.second + dir_y[k]] = '0';
                        }
                    }
                }
                island_count++;
            }
        }
    }
    return island_count;
}
int main()
{
    // std::vector<std::vector<char>> grid = {
    //     {'1', '1', '0', '0', '0'},
    //     {'1', '1', '0', '0', '0'},
    //     {'0', '0', '1', '0', '0'},
    //     {'0', '0', '0', '1', '1'}};
    std::vector<std::vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    std::cout << numIslands(grid) << std::endl;
}