#include <bits/stdc++.h>

using namespace std;

int dfs_region(vector<vector<int>> &grid, int i, int j, int rows, int cols)
{
    int max_region = 1;
    grid[i][j] = 0;

    stack<pair<int, int>> visit_stack;
    visit_stack.push(make_pair(i, j));

    while (!visit_stack.empty())
    {

        pair<int, int> curr = visit_stack.top();
        // cout << "checking: " << curr.first << ", " << curr.second << endl;
        visit_stack.pop();
        for (int ii = curr.first - 1; ii <= curr.first + 1; ii++)
        {
            for (int jj = curr.second - 1; jj <= curr.second + 1; jj++)
            {
                if (jj < 0 || ii < 0 || jj > cols - 1 || ii > rows - 1)
                    ;
                else if (grid[ii][jj])
                {
                    // cout << "ii: " << ii << "jj: " << jj << endl;
                    max_region++;
                    grid[ii][jj] = 0;
                    visit_stack.push(make_pair(ii, jj));
                }
            }
        }
        // cout << "out, max_region:  " << max_region << endl;
    }
    cout << "===" << endl;
    return max_region;
}

int maxRegion(vector<vector<int>> grid)
{
    int max_region = 0;
    int cols = grid[0].size();
    int rows = grid.size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j])
            {
                int temp_max_region = dfs_region(grid, i, j, rows, cols);
                if (temp_max_region > max_region)
                    max_region = temp_max_region;
            }
        }
    }
    return max_region;
}

int maxRegion2(vector<vector<int>> grid)
{
    int max_region = 0;
    int cols = grid[0].size();
    int rows = grid.size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j])
            {
                int local_region = 1;
                grid[i][j] = 0;
                for (int ii = i - 1; ii <= i + 1; ii++)
                {
                    for (int jj = j - 1; jj <= j + 1; jj++)
                    {
                        if (jj < 0 || ii < 0 || jj > cols - 1 || ii > rows - 1)
                            ;
                        else if (ii == i && jj == j)
                            ;
                        else
                        {
                            if (grid[ii][jj])
                            {
                                local_region++;
                                grid[ii][jj] = 0;
                            }
                        }
                    }
                }
                if (local_region > max_region)
                    max_region = local_region;
            }
        }
    }
    return max_region;
}
int main()
{
    // vector<vector<int>> grid = {{0, 0, 1, 1, 0, 0},
    //                             {0, 0, 0, 1, 1, 0},
    //                             {0, 0, 0, 1, 0, 0},
    //                             {1, 1, 0, 0, 0, 1}};
    vector<vector<int>> grid = {{1, 0, 1, 1, 0},
                                {1, 1, 0, 0, 1},
                                {0, 1, 1, 1, 0},
                                {0, 0, 0, 0, 0},
                                {1, 1, 1, 0, 1}};
    int max_region = maxRegion(grid);
    cout << max_region << endl;
}