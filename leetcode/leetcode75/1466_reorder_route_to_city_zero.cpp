#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>

int minReorder(int n, std::vector<std::vector<int>> &connections)
{
    std::map<int, std::vector<std::pair<int, bool>>> graph;
    for (auto x : connections)
    {
        graph[x[0]].push_back({x[1], true});
        graph[x[1]].push_back({x[0], false});
    }
    int changes = 0;
    std::stack<int> s;
    std::map<int, bool> visited;
    s.push(0);
    visited[0] = true;

    while (!s.empty())
    {
        auto curr = s.top();
        s.pop();
        for (auto x : graph[curr])
        {
            if (!visited[x.first])
            {
                if (x.second)
                    changes++;
                s.push(x.first);
                visited[x.first] = true;
            }
        }
    }
    return changes;
}

int BuggedminReorder(int n, std::vector<std::vector<int>> &connections)
{
    std::set<int> viable;
    std::vector<int> unknown;
    int reorder = 0;
    for (int i = 0; i < connections.size(); i++)
    {
        if (connections[i][0] == 0)
        {
            reorder++;
            viable.insert(connections[i][1]);
        }
        else if (connections[i][1] == 0)
        {
            viable.insert(connections[i][0]);
        }
        else
        {
            if (viable.find(connections[i][1]) != viable.end())
            {
                viable.insert(connections[i][0]);
            }
            else if (viable.find(connections[i][0]) != viable.end())
            {
                reorder++;
                viable.insert(connections[i][1]);
            }
            else
            {
                unknown.push_back(i);
            }
        }
    }
    for (auto x : unknown)
    {
        if (viable.find(connections[x][1]) != viable.end())
        {
            viable.insert(connections[x][0]);
        }
        else if (viable.find(connections[x][0]) != viable.end())
        {
            reorder++;
            viable.insert(connections[x][1]);
        }
    }
    return reorder;
}
int main()
{
    // std::vector<std::vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    // std::vector<std::vector<int>> connections = {{4, 5}, {0, 1}, {1, 3}, {2, 3}, {4, 0}};
    std::vector<std::vector<int>> connections = {{4, 3}, {2, 3}, {1, 2}, {1, 0}};
    int n = 6;
    auto res = minReorder(n, connections);
    return 0;
}