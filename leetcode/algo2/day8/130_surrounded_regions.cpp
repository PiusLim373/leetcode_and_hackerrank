#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <map>

void fill_x(std::vector<std::vector<char>> &board, std::vector<std::pair<int, int>> &fill)
{
    for (auto x : fill)
    {
        board[x.first][x.second] = 'X';
    }
}

void solve(std::vector<std::vector<char>> &board)
{
    int m = board.size();
    int n = board[0].size();
    if (m <= 2 || n <= 2)
    {
        return;
    }

    std::vector<int> dir_x = {0, 1, 0, -1};
    std::vector<int> dir_y = {-1, 0, 1, 0};

    std::queue<std::pair<int, int>> q;
    std::map<std::pair<int, int>, bool> visited;

    int debug_component = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'O' && !visited[{i, j}])
            {
                visited[{i, j}] = true;
                q.push({i, j});
                bool is_surrounded = true;
                std::vector<std::pair<int, int>> coor = {{i, j}};
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
                    is_surrounded = false;
                while (!q.empty())
                {
                    std::pair<int, int> curr = q.front();
                    q.pop();
                    for (int k = 0; k < dir_x.size(); k++)
                    {

                        int visit_x = curr.first + dir_x[k];
                        int visit_y = curr.second + dir_y[k];
                        if (visit_x >= 0 && visit_y >= 0 && visit_x <= m - 1 && visit_y <= n - 1 && !visited[{visit_x, visit_y}] && board[visit_x][visit_y] == 'O')
                        {
                            std::cout << visit_x << " " << visit_y << std::endl;
                            if (visit_x == 0 || visit_y == 0 || visit_x == m - 1 || visit_y == n - 1)
                            {
                                std::cout << debug_component << " " << visit_x << " " << visit_y << std::endl;
                                is_surrounded = false;
                            }
                            q.push({visit_x, visit_y});
                            visited[{visit_x, visit_y}] = true;
                            coor.push_back({visit_x, visit_y});
                        }
                    }
                }
                if (is_surrounded)
                    fill_x(board, coor);
                debug_component++;
            }
        }
    }
    std::cout << debug_component << std::endl;
}

/*Better solution

1. look for boundary 'O' and dfs to its component
2. fill these component with '#'
3. Loop through the board again, convert these # to X

Link: https://leetcode.com/problems/surrounded-regions/discuss/691675/C%2B%2B-Beginner-Friendly-or-Boundary-DFS-or-inPlace
*/
int main()
{
    std::vector<std::vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    solve(board);
    for (auto x : board)
    {
        for (auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
    }
}