#include <iostream>
#include <vector>
#include <queue>
#include <map>
std::vector<std::pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int nearestExit(std::vector<std::vector<char>> &maze, std::vector<int> &entrance)
{
    int row = maze.size();
    int col = maze[0].size();
    std::queue<std::pair<int, int>> q;
    std::map<std::pair<int, int>, bool> visited;
    std::map<std::pair<int, int>, int> dist;
    q.push({entrance[0], entrance[1]});
    dist[{entrance[0], entrance[1]}] = 0;
    visited[{entrance[0], entrance[1]}] = true;

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        for (auto step : dir)
        {
            int check_i = curr.first + step.first;
            int check_j = curr.second + step.second;
            if (check_i < 0 || check_i >= row || check_j < 0 || check_j >= col)
            {
                if (curr.first != entrance[0] || curr.second != entrance[1])
                {
                    // exit found
                    return dist[curr];
                }
            }
            else if (check_i >= 0 && check_i < row && check_j >= 0 && check_j < col && !visited[{check_i, check_j}] && maze[check_i][check_j] != '+')
            {
                visited[{check_i, check_j}] = true;
                dist[{check_i, check_j}] = dist[curr] + 1;
                q.push({check_i, check_j});
            }
        }
    }
    return -1;
}

int main()
{
    // std::vector<std::vector<char>> maze = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    // std::vector<int> entrance = {1, 2};
    // std::vector<std::vector<char>> maze ={{'+','+','+'},{'.','.','.'},{'+','+','+'}};
    // std::vector<int> entrance = {1, 0};
    std::vector<std::vector<char>> maze ={{'.', '+'}};
    std::vector<int> entrance = {0, 0};
    std::cout << nearestExit(maze, entrance);
    return 0;
}
