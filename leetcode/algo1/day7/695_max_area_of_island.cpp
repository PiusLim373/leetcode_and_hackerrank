#include <bits/stdc++.h>
using namespace std;
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int max_area = 0;

    int image_size_x = grid[0].size();
    int image_size_y = grid.size();

    vector<int> dir_x{0, 1, 0, -1};
    vector<int> dir_y{-1, 0, 1, 0};
    queue<pair<int, int>> visit_queue;
    map<pair<int, int>, bool> visited;

    for (int x = 0; x < image_size_y; x++)
    {
        for (int y = 0; y < image_size_x; y++)
        {
            if (grid[x][y] && !visited[{x, y}])
            {
                visited[{x, y}] = true;
                visit_queue.push(make_pair(x, y));

                int area = 0;

                while (!visit_queue.empty())
                {
                    pair<int, int> curr = visit_queue.front();
                    visit_queue.pop();
                    area++;
                    for (int i = 0; i < dir_x.size(); i++)
                    {
                        pair<int, int> child_coor = {curr.first + dir_x[i], curr.second + dir_y[i]};
                        if (child_coor.first >= 0 && child_coor.second >= 0 && child_coor.first < image_size_y && child_coor.second < image_size_x)
                        {
                            if (!visited[child_coor] && grid[child_coor.first][child_coor.second])
                            {
                                visit_queue.push(child_coor);
                                visited[child_coor] = true;
                            }
                        }
                    }
                }
                if (area > max_area)
                    max_area = area;
            }
        }
    }

    return max_area;

    // better solution will be change the visited node to 0 then can save sometime during checking
}
int main()
{

    // vector<vector<int>> image = {{0, 0, 0}, {0, 0, 0}};
    // int sr = 0, sc = 0, newColor = 2;

    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    int area = maxAreaOfIsland(grid);
    cout << area << endl;
}