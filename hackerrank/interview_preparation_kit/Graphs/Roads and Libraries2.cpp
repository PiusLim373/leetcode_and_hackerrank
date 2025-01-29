#include <bits/stdc++.h>

using namespace std;

class graph
{
public:
    long node = 0;
    map<long, list<long>> edges;
    graph(int n) { node = (long)n; }
    void add_edge(int u, int v)
    {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<long> count_component_and_nodes()
    {
        vector<long> return_val;
        map<long, bool> visited;

        for (long i = 1; i < node + 1; i++)
        {
            if (visited[i])
                continue;
            else
            {
                if (edges[i].size() == 1)
                    return_val.push_back(1);
                else
                {
                    long node_counter = 0;
                    queue<long> visit_queue;
                    visit_queue.push(i);
                    visited[i] = true;
                    node_counter++;
                    while (!visit_queue.empty())
                    {
                        long curr = visit_queue.front();
                        visit_queue.pop();
                        for (auto x : edges[curr])
                        {
                            if (!visited[x])
                            {
                                visited[x] = true;
                                node_counter++;
                                visit_queue.push(x);
                            }
                        }
                    }
                    return_val.push_back(node_counter);
                }
            }
        }
        return return_val;
    }
};

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{

    graph g(n);
    for (auto x : cities)
        g.add_edge(x[0], x[1]);
    vector<long> node_counter = g.count_component_and_nodes();
    long long int cost = 0;
    for (auto x : node_counter)
        cost += min(((x - 1) * c_road + c_lib), x * c_lib);
    return cost;
}

int main()
{
    int n = 5;
    int m = 3;
    int c_lib = 3;
    int c_road = 2;
    // vector<vector<int>> cities = {{0, 1}, {2, 3}, {3, 4}};
    vector<vector<int>> cities = {{1, 4}, {1, 3}, {1, 2}, {2, 3}};
    // vector<vector<int>> cities = {{0, 6}, {0, 2}, {0, 1}, {1, 2}, {4, 5}, {5, 7}};
    cout << roadsAndLibraries(n, c_lib, c_road, cities) << endl;
    // long result = roadsAndLibraries(n, c_lib, c_road, cities);
    return 0;
}