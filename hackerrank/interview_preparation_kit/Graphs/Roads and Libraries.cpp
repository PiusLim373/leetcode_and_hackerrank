#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>> &v, int src, vector<bool> &visited)
{
    visited[src] = true;
    int ans = 1;
    for (int i = 0; i < v[src].size(); i++)
    {
        if (!visited[v[src][i]])
            ans += dfs(v, v[src][i], visited);
    }
    return ans;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{

    vector<vector<int>> v(n + 1);
    for (auto x : cities)
    {
        v[x[0]].push_back(x[1]);
        v[x[1]].push_back(x[0]);
    }
    vector<int> components;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i < n + 1; i++)
    {
        if (v[i].size() > 0 && !visited[i])
            components.push_back(dfs(v, i, visited));
        else if (v[i].size() == 0)
            components.push_back(1);
    }
    long long int cost = 0;
    for (auto x : components)
    {
        cost += min(((x - 1) * c_road + c_lib), x * c_lib);
    }
    return cost;
}

int main()
{
    int n = 5;
    int m = 3;
    int c_lib = 6;
    int c_road = 1;
    vector<vector<int>> cities = {{1, 2}, {1, 3}, {1, 4}};
    // vector<vector<int>> cities = {{1, 7}, {1, 3}, {1, 2}, {2, 3}, {5, 6}, {6, 8}};
    // vector<vector<int>> cities = {{0, 6}, {0, 2}, {0, 1}, {1, 2}, {4, 5}, {5, 7}};
    cout << roadsAndLibraries(n, c_lib, c_road, cities) << endl;
    // long result = roadsAndLibraries(n, c_lib, c_road, cities);
    return 0;
}