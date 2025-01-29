#include <bits/stdc++.h>
using namespace std;

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY)
{
    int size = grid.size();
    queue<pair<int, int>> visit_queue;
    map<pair<int, int>, int> distance;

    visit_queue.push({startX, startY});
    grid[startX][startY] = 'C';
    int temp_distance = 0;
    distance[{startX, startY}] = temp_distance;

    while (!visit_queue.empty())
    {
        pair<int, int> curr = visit_queue.front();
        visit_queue.pop();
        temp_distance++;

        vector<int> dr = {0, 0, -1, 1};
        vector<int> dc = {-1, 1, 0, 0};

        for (int i = 0; i < dr.size(); i++)
        {
            int row = curr.first;
            int col = curr.second;
            while (1)
            {
                row += dr[i];
                col += dc[i];

                if (col < 0 || row < 0 || col > size - 1 || row > size - 1 || grid[row][col] == 'X')
                    break;

                else if (row == goalX && col == goalY)
                {
                    return distance[curr] + 1;
                }
                else if (grid[row][col] == '.')
                {
                    visit_queue.push({row, col});
                    grid[row][col] = 'C';
                    distance[{row, col}] = distance[curr] + 1;
                }
            }
        }
    }
    return -1;

    //     vector<int> dr = {0, 0, -1, 1};
    //     vector<int> dc = {-1, 1, 0, 0};

    //     for (int i = 0; i < dr.size(); i++)
    //     {
    //         int row = curr.first + dc[i];
    //         int col = curr.second + dr[i];

    //         if (col < 0 || row < 0 || col > 2 || row > 2)
    //             ;
    //         else if (row == goalX && col == goalY)
    //         {
    //             return distance[curr] + 1;
    //         }
    //         else if (grid[row][col] == '.')
    //         {
    //             visit_queue.push({row, col});
    //             grid[row][col] = 'X';
    //             distance[{row, col}] = distance[curr] + 1;
    //         }
    //     }
    // }
    // return -1;
}

int main()
{
    // vector<string> grid = {".X.", ".X.", "..."};
    // int startX = 0;
    // int startY = 0;
    // int goalX = 0;
    // int goalY = 2;

    // vector<string> grid = {"...", ".X.", ".X."};
    // int startX = 2;
    // int startY = 0;
    // int goalX = 2;
    // int goalY = 2;

    vector<string> grid = {".X..XX...X",
                           "X.........",
                           ".X.......X",
                           "..........",
                           "........X.",
                           ".X...XXX..",
                           ".....X..XX",
                           ".....X.X..",
                           "..........",
                           ".....X..XX"};
    int startX = 9;
    int startY = 1;
    int goalX = 9;
    int goalY = 6;
    int step = minimumMoves(grid, startX, startY, goalX, goalY);
    cout << step << endl;
}