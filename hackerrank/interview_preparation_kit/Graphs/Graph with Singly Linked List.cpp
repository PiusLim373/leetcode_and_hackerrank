#include <bits/stdc++.h>
using namespace std;

// class Edges
// {
// public:
//     int connecting_nodes;
//     int weight;
//     Edges *next;
//     Edges(int node, int input_weight)
//     {
//         connecting_nodes = node;
//         weight = input_weight;
//         next = NULL;
//     }
//     Edges *insert(Edges *head, int node, int input_weight)
//     {
//         if (head == NULL)
//             return new Edges(node, input_weight);
//         else
//         {
//             Edges *temp = insert(head->next, node, input_weight);
//             head->next = temp;
//         }
//     }
// };

class Graph
{
public:
    map<int, list<pair<int, int>>> edges;
    void add_edge(int u, int v, int weight)
    {
        edges[u].push_back(make_pair(v, weight));
        edges[v].push_back(make_pair(u, weight));
    }
    vector<int> bfs(int start)
    {
        vector<int> visit_vec;
        map<int, bool> has_visited;
        queue<int> visit_queue;
        visit_vec.push_back(start);
        has_visited[start] = true;
        for (auto x : edges[start])
        {
            visit_queue.push(x.first);
            has_visited[x.first] = true;
        }
        while (!visit_queue.empty())
        {
            int curr = visit_queue.front();
            visit_queue.pop();
            visit_vec.push_back(curr);
            for (auto x : edges[curr])
                if (!has_visited[x.first])
                {
                    visit_queue.push(x.first);
                    has_visited[x.first] = true;
                }
        }
        return visit_vec;
    }
    // vector<int> dfs(int start)
    // {
    //     vector<int> visit_vec;
    //     map<int, bool> has_visited;
    //     stack<int> visit_stack;
    //     visit_vec.push_back(start);
    //     has_visited[start] = true;
    //     for (auto x : edges[start])
    //     {
    //         visit_stack.push(x);
    //         has_visited[x] = true;
    //     }
    //     while (!visit_stack.empty())
    //     {
    //         int curr = visit_stack.top();
    //         visit_stack.pop();
    //         visit_vec.push_back(curr);
    //         for (auto x : edges[curr])
    //             if (!has_visited[x])
    //             {
    //                 visit_stack.push(x);
    //                 has_visited[x] = true;
    //             }
    //     }
    //     return visit_vec;
    // }
    void print_adj_list()
    {
        for (auto x : edges)
        {
            cout << "vertex: " << x.first << ", connecting edges: ";
            for (auto y : x.second)
                cout << y.first << "-> ";
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.add_edge(0, 1, 6);
    g.add_edge(0, 4, 6);
    g.add_edge(1, 2, 6);
    g.add_edge(1, 3, 6);
    g.add_edge(1, 4, 6);
    g.add_edge(3, 4, 6);
    g.add_edge(4, 3, 6);
    // g.print_adj_list();
    vector<int> bfs_sol = g.bfs(0);
    for (auto x : bfs_sol)
        cout << x << " ";
    cout << endl;
    // vector<int> dfs_sol = g.dfs(0);
    // for (auto x : dfs_sol)
    //     cout << x << " ";
    // cout << endl;
}