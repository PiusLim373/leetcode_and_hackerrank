#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <algorithm>

std::vector<std::vector<int>> res;
std::vector<int> temp;
int target;

void dfs_helper(std::vector<std::vector<int>> &graph, int curr)
{
    temp.push_back(curr);
    if (curr == target)
        res.push_back(temp);
    for (auto x : graph[curr])
        dfs_helper(graph, x);
    temp.pop_back();
}

std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>> &graph)
{
    target = graph.size() - 1;
    dfs_helper(graph, 0);
    return res;
}
std::vector<std::vector<int>> allPathsSourceTargetBugged(std::vector<std::vector<int>> &graph)
{
    int target = graph.size() - 1;
    std::vector<std::vector<int>> res;
    std::map<int, std::list<int>> connected;
    std::map<int, int> origin;
    std::map<int, bool> visited;
    for (int i = 0; i < graph.size(); i++)
    {
        for (auto x : graph[i])
        {
            connected[i].push_back(x);
        }
    }
    std::stack<int> s;
    s.push(0);
    origin[0] = -1;
    visited[0] = true;
    while (!s.empty())
    {
        int curr = s.top();
        s.pop();
        for (auto x : connected[curr])
        {
            if (x == target)
            {
                std::vector<int> route = {target};
                int last_node = curr;
                while (last_node != -1)
                {
                    route.push_back(last_node);
                    last_node = origin[last_node];
                }
                std::reverse(route.begin(), route.end());
                res.push_back(route);
            }
            else if (!visited[x])
            {
                s.push(x);
                origin[x] = curr; // some logic is wrong here as next node form the same origin will overwrite this
                visited[x] = true;
            }
        }
    }
    return res;
}
int main()
{
    // std::vector<std::vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    std::vector<std::vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    for (auto x : allPathsSourceTarget(graph))
    {
        for (auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
    }
}