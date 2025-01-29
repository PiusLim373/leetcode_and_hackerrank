#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid[0].size();
    int n = grid.size();

    vector<int> dir_x = {0, 1, 0, -1};
    vector<int> dir_y = {-1, 0, 1, 0};

    map<pair<int, int>, int> time;
    int max_time = 0;
    map<pair<int, int>, bool> visited;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)

            if (grid[i][j] == 2)
            {
                visited[{i, j}] = true;
                q.push({i, j});
                time[{i, j}] = 0;
            }

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        for (int k = 0; k < dir_x.size(); k++)
        {
            pair<int, int> temp = {curr.first + dir_y[k], curr.second + dir_x[k]};
            if (temp.first >= 0 && temp.second >= 0 && temp.first < n && temp.second < m && !visited[temp])
            {
                if (grid[temp.first][temp.second] != 0)
                {
                    visited[temp] = true;
                    grid[temp.first][temp.second] = 2;
                    time[temp] = time[curr] + 1;
                    if (time[temp] > max_time)
                        max_time = time[temp];
                    q.push(temp);
                }
            }
        }
    }
    for (auto x : grid)
        for (auto y : x)
            if (y == 1)
                return -1;

    return max_time;
}
int main()
{
    // vector<vector<int>> grid = {{2, 1, 1},
    //                             {1, 1, 0},
    //                             {0, 1, 1}};
    // vector<vector<int>> grid = {{2, 1, 1},
    //                             {0, 1, 1},
    //                             {1, 0, 1}};
    vector<vector<int>> grid = {{0, 2}};

    cout << orangesRotting(grid) << endl;
}