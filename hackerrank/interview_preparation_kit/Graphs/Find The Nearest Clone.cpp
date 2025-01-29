#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int number_of_nodes = 0;
    map<int, list<int>> edges;
    Graph(int n)
    {
        number_of_nodes = n;
    }
    void add_edge(int u, int v)
    {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int bfs_find_node_length(vector<int> interested)
    {

        map<int, int> distance_map;
        queue<int> visit_queue;
        for (auto x : interested)
        {
            visit_queue.push(x);
            distance_map[x] = 0;
        }

        map<int, bool> visited;
        while (!visit_queue.empty())
        {
            int curr = visit_queue.front();
            visit_queue.pop();
            visited[curr] = true;

            for (auto x : edges[curr])
            {
                if (visited[x])
                {

                    if (find(interested.begin(), interested.end(), x) == interested.end())
                        return (distance_map[x] + distance_map[curr] + 1);
                }
                else
                {
                    if (find(interested.begin(), interested.end(), x) != interested.end())
                        return distance_map[curr] + 1;
                    else
                    {
                        distance_map[x] = distance_map[curr] + 1;
                        visit_queue.push(x);
                        visited[x] = true;
                    }
                }
            }
        }
    }
};

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val)
{
    vector<int> interested;
    for (int i = 0; i < ids.size(); i++)
        if (ids[i] == val)
            interested.push_back(i + 1);
    if (interested.size() <= 1)
        return -1;
    Graph g(graph_nodes);
    for (int i = 0; i < graph_from.size(); i++)
        g.add_edge(graph_from[i], graph_to[i]);

    return g.bfs_find_node_length(interested);
}
int main()
{
    // int graph_nodes = 4;
    // vector<int> graph_from = {1, 1, 4};
    // vector<int> graph_to = {2, 3, 2};
    // vector<long> ids = {1, 2, 1, 1};
    // int val = 1;

    // int graph_nodes = 4;
    // vector<int> graph_from = {1, 1, 2, 3};
    // vector<int> graph_to = {2, 3, 4, 5};
    // vector<long> ids = {1, 2, 3, 3, 2};
    // int val = 2;

    int graph_nodes = 4;
    vector<int> graph_from = {1, 1, 4};
    vector<int> graph_to = {2, 3, 2};
    vector<long> ids = {1, 2, 3, 4};
    int val = 2;

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);
    cout << ans << endl;
}