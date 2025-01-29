#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    map<int, list<int>> edges;
    int number_of_nodes = 0;
    Graph(int i)
    {
        number_of_nodes = i;
    }
    void add_edge(int u, int v)
    {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int count_connected(int start)
    {
        int connected = 1;

        map<int, bool> visited;
        stack<int> visit_stack;

        visited[start] = true;
        visit_stack.push(start);

        while (!visit_stack.empty())
        {
            int curr = visit_stack.top();
            visit_stack.pop();
            for (auto x : edges[curr])
            {
                if (!visited[x])
                {
                    visit_stack.push(x);
                    visited[x] = true;
                    connected++;
                }
            }
        }
        return connected;
    }
    void print_adj_list()
    {
        for (auto x : edges)
        {
            cout << "vertex: " << x.first << ", connecting edges: ";
            for (auto y : x.second)
                cout << y << "-> ";
            cout << endl;
        }
    }
};

int maxRegion(vector<vector<int>> grid)
{
    vector<pair<int, int>> region;
    vector<int> area_list;
    int cols = grid[0].size();
    int rows = grid.size();
    vector<pair<int, int>> ones;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            if (grid[i][j])
                ones.push_back(make_pair(i, j));
    }

    for (auto x : ones)
        cout << x.first << ", " << x.second << endl;

    if (ones.size())
    {
        region.push_back(make_pair(ones[0].first, ones[0].second));
        area_list.push_back(1);
    }

    Graph g(ones.size());

    //something logic is wrong here
    for (int i = 1; i < ones.size(); i++)
    {
        if ((abs(ones[i].first - ones[i - 1].first) + abs(ones[i].second - ones[i - 1].second)) <= 2)
        {
            g.add_edge(ones[i - 1].second + ones[i - 1].first * cols, ones[i].second + ones[i].first * cols);
        }
        else
        {
            region.push_back(make_pair(ones[i].first, ones[i].second));
        }
    }
    //something logic is wrong here ends

    g.print_adj_list();
    for (auto x : region)
        area_list.push_back(g.count_connected(x.second + x.first * cols));

    if (!area_list.size())
        return 0;
    else
        return *max_element(area_list.begin(), area_list.end());
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
                                {0, 0, 0, 0, 1},
                                {1, 1, 1, 0, 0}};
    int max_region = maxRegion(grid);
    cout << max_region << endl;
}