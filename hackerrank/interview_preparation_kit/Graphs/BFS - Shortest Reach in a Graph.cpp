#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, list<int>> edges;
    int number_of_nodes = 0;
    Graph(int n)
    {
        number_of_nodes = n;
    }
    void add_edge(int u, int v)
    {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<int> shortest_reach(int start)
    {
        vector<int> distance(number_of_nodes, -1);
        map<int, bool> visited;
        distance[start - 1] = 0;
        queue<int> visit_queue;
        visited[start] = true;
        visit_queue.push(start);

        while (!visit_queue.empty())
        {
            int curr = visit_queue.front();
            visit_queue.pop();

            for (auto x : edges[curr])
            {
                if (!visited[x])
                {
                    visit_queue.push(x);
                    distance[x - 1] = distance[curr - 1] + 6;
                    visited[x] = true;
                }
            }
        }
        vector<int> processed_distance;
        for (auto x : distance)
            if (x)
                processed_distance.push_back(x);
        return processed_distance;
        // return distance;
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

int main()
{
    Graph g(4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    // g.add_edge(3, 4);
    // g.add_edge(1, 5);
    g.print_adj_list();
    vector<int> distance = g.shortest_reach(1);
    for (auto x : distance)
        cout << x << " ";
    cout << endl;
}