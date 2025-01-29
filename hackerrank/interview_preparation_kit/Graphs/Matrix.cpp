#include <bits/stdc++.h>
using namespace std;
class graph
{
    map<int, vector<pair<int, int>>> edges;

public:
    void add_edges(int u, int v, int w)
    {
        edges[u].push_back(make_pair(v, w));
        edges[v].push_back(make_pair(u, w));
    }
    int dfs_break_road(vector<int> machines)
    {
        int cost = 0;
        stack<int> visit_stack;
        map<int, bool> visited;

        visit_stack.push(0);
        visited[0] = true;

        while (!visit_stack.empty())
        {
            int curr = visit_stack.top();
            cout << curr << endl;
            visit_stack.pop();
            for (auto x : edges[curr])
            {
                if (!visited[x.first])
                {
                    visited[x.first] = true;
                    visit_stack.push(x.first);
                }
            }
            if (find(machines.begin(), machines.end(), curr) != machines.end())
            {
            }
        }
        return 999;
    }
};
bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[2] > b[2];
}
int minTime(vector<vector<int>> roads, vector<int> machines)
{
    // graph g;
    // for (auto x : roads)
    //     g.add_edges(x[0], x[1], x[2]);
    // return g.dfs_break_road(machines);
    int cost = 0;

    map<int, bool> has_machine;
    for (auto x : machines)
        has_machine[x] = true;

    sort(roads.begin(), roads.end(), cmp);

    // bool component_has_machine = false;
    // for (auto x : roads)
    // {
    //     int machine_count = 0;
    //     if (has_machine[x[0]])
    //         machine_count++;
    //     if (has_machine[x[1]])
    //         machine_count++;
    //     if (machine_count == 2)
    //         cost += x[2];
    //     else if (machine_count == 1)
    //     {
    //         if (component_has_machine)
    //             cost += x[2];
    //         else
    //             component_has_machine = true;
    //     }
    // }

    for (auto x : roads)
    {
        int b1 = x[0];
        int b2 = x[1];

        if (has_machine[b1] && has_machine[b2])
            cost += x[2];
        else
        {
            has_machine[b1] = b1 || b2;
            has_machine[b2] = b1 || b2;
        }
    }
    return cost;
}

int main()
{
    // vector<vector<int>> roads = {{2, 1, 8}, {1, 0, 5}, {2, 4, 5}, {1, 3, 4}};
    // vector<int> machines = {2, 4, 0};

    // vector<vector<int>> roads = {{0, 1, 4}, {2, 0, 8}, {1, 3, 7}, {1, 4, 2}};
    // vector<int> machines = {2, 4, 3};

    vector<vector<int>> roads = {{0, 3, 3}, {1, 4, 4}, {1, 3, 4}, {0, 2, 5}};
    vector<int> machines = {1, 4, 3};
    int ans = minTime(roads, machines);
    cout << ans << endl;
}