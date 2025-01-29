#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{

    int m = mat[0].size();
    int n = mat.size();
    vector<vector<int>> sol(n, vector<int>(m, -1));
    vector<int> dir_x = {0, 1, 0, -1};
    vector<int> dir_y = {-1, 0, 1, 0};

    queue<pair<int, int>> visit_queue;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!mat[i][j])
            {
                visit_queue.push({i, j});
                sol[i][j] = 0;
            }
        }
    }

    while (!visit_queue.empty())
    {
        pair<int, int> curr = visit_queue.front();
        visit_queue.pop();
        for (int k = 0; k < dir_x.size(); k++)
        {
            pair<int, int> temp = {curr.first + dir_y[k], curr.second + dir_x[k]};
            if (temp.first >= 0 && temp.second >= 0 && temp.first < n && temp.second < m && sol[temp.first][temp.second] == -1)
            {
                visit_queue.push(temp);
                sol[temp.first][temp.second] = sol[curr.first][curr.second] + 1;
            }
        }
    }

    return sol;
}

vector<vector<int>> updateMatrixBugged(vector<vector<int>> &mat)
{

    int m = mat[0].size();
    int n = mat.size();
    vector<vector<int>> sol(n, vector<int>(m, 0));
    vector<int> dir_x = {0, 1, 0, -1};
    vector<int> dir_y = {-1, 0, 1, 0};

    map<pair<int, int>, bool> calculated;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!mat[i][j])
            {
                sol[i][j] = 0;
                calculated[{i, j}] = true;
            }
            else
            {
                queue<pair<int, int>> visit_queue;
                map<pair<int, int>, bool> visited;
                map<pair<int, int>, int> distance;
                visit_queue.push({i, j});
                visited[{i, j}] = true;
                distance[{i, j}] = 0;
                bool distance_found = false;
                while (!visit_queue.empty() && !distance_found)
                {
                    pair<int, int> curr = visit_queue.front();
                    visit_queue.pop();
                    for (int k = 0; k < dir_x.size(); k++)
                    {
                        pair<int, int> temp = {curr.first + dir_y[k], curr.second + dir_x[k]};
                        if (temp.first >= 0 && temp.second >= 0 && temp.first < n && temp.second < m)
                        {
                            if (!visited[temp])
                            {
                                if (calculated[temp])
                                {
                                    sol[i][j] = sol[temp.first][temp.second] + 1;
                                    calculated[curr] = true;
                                    distance_found = true;
                                    break;
                                }
                                distance[temp] = distance[curr] + 1;
                                if (!mat[temp.first][temp.second])
                                {

                                    sol[i][j] = distance[temp];
                                    calculated[curr] = true;
                                    distance_found = true;
                                    break;
                                }
                                visited[temp] = true;
                                visit_queue.push(temp);
                            }
                        }
                    }
                }
            }
        }
    }
    return sol;
}

vector<vector<int>> updateMatrixTimeExceeded(vector<vector<int>> &mat)
{

    int m = mat[0].size();
    int n = mat.size();
    vector<vector<int>> sol(n, vector<int>(m, 0));
    vector<int> dir_x = {0, 1, 0, -1};
    vector<int> dir_y = {-1, 0, 1, 0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!mat[i][j])
                sol[i][j] = 0;
            else
            {
                queue<pair<int, int>> visit_queue;
                map<pair<int, int>, bool> visited;
                map<pair<int, int>, int> distance;

                visit_queue.push({i, j});
                visited[{i, j}] = true;
                distance[{i, j}] = 0;
                bool distance_found = false;
                while (!visit_queue.empty() && !distance_found)
                {
                    pair<int, int> curr = visit_queue.front();
                    visit_queue.pop();
                    for (int k = 0; k < dir_x.size(); k++)
                    {
                        pair<int, int> temp = {curr.first + dir_x[k], curr.second + dir_y[k]};
                        if (temp.first >= 0 && temp.second >= 0 && temp.first < n && temp.second < m)
                        {
                            if (!visited[temp])
                            {
                                distance[temp] = distance[curr] + 1;
                                if (!mat[temp.first][temp.second])
                                {

                                    sol[i][j] = distance[temp];
                                    distance_found = true;
                                    break;
                                }
                                visited[temp] = true;
                                visit_queue.push(temp);
                            }
                        }
                    }
                }
            }
        }
    }
    return sol;
}
int main()
{
    // vector<vector<int>> mat = {{0, 0, 0},
    //                            {0, 1, 0},
    //                            {1, 1, 1},
    //                            {1, 1, 1}};
    vector<vector<int>> mat = {{0, 1, 0},
                               {0, 1, 0},
                               {0, 1, 0},
                               {0, 1, 0}};

    vector<vector<int>> sol = updateMatrix(mat);
    for (auto x : sol)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}