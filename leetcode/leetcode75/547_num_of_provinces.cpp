#include <iostream>
#include <vector>
#include <stack>
#include <map>

int findCircleNum(std::vector<std::vector<int>> &isConnected)
{
    std::stack<int> s;
    std::map<int, bool> visited;
    int num_province = 0;
    // int isolated = isConnected.size();
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (!visited[i])
        {
            s.push(i);
            num_province++;
        }
        while (!s.empty())
        {
            auto curr = s.top();
            s.pop();
            for (int i = 0; i < isConnected[curr].size(); i++)
            {
                if (isConnected[curr][i] != 0 && !visited[i])
                {
                    s.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    return num_province;
}
int main()
{
    std::vector<std::vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    // std::vector<std::vector<int>> isConnected = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 1, 1, 0}, {0, 0, 1, 1, 0},{0, 0, 0, 0, 1}};
    // std::vector<std::vector<int>> isConnected = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};

    auto res = findCircleNum(isConnected);
    return 0;
}