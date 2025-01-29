#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <list>
int findCircleNum(std::vector<std::vector<int>> &isConnected)
{
    std::map<int, std::list<int>> connected;
    for (int i = 0; i < isConnected.size(); i++)
    {
        for (int j = 0; j < isConnected[i].size(); j++)
        {
            if (isConnected[i][j])
            {
                connected[i].push_back(j);
            }
        }
    }

    std::queue<int> visit_queue;
    int province_count = 0;

    for (auto x : connected)
    {
        if (!x.second.empty())
        {
            visit_queue.push(x.second.front());
            x.second.pop_front();
            while (!visit_queue.empty())
            {
                int curr = visit_queue.front();
                visit_queue.pop();
                while (!connected[curr].empty())
                {
                    visit_queue.push(connected[curr].front());
                    connected[curr].pop_front();
                }
            }
            province_count++;
        }
    }
    return province_count;
}
int main()
{
    std::vector<std::vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};

    // std::vector<std::vector<int>> isConnected = {
    //     {1, 0, 0},
    //     {0, 1, 0},
    //     {0, 0, 1}};
    std::cout << findCircleNum(isConnected) << std::endl;
}