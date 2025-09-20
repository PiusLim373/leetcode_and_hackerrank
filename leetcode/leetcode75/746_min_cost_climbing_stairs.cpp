#include <vector>
#include <unordered_map>
#include <queue>
struct Compare
{
    bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

int minCostClimbingStairs(std::vector<int> &cost)
{
    int target_index = cost.size();
    std::vector<int> cost_vector(target_index + 1, INT32_MAX);

    cost_vector[0] = 0;
    cost_vector[1] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> q;

    q.push({0, 0});
    q.push({1, 0});

    while (!q.empty())
    {
        auto [curr_index, curr_cost] = q.top();
        q.pop();
        for (int i = 1; i <= 2; i++)
        {
            int new_index = curr_index + i;
            if(new_index > target_index)
                continue;
            int new_cost = curr_cost + cost[curr_index];
            if (new_index <= target_index && new_cost < cost_vector[new_index])
            {
                cost_vector[new_index] = new_cost;
                q.push({new_index, new_cost});
            }
        }
    }
    return cost_vector[target_index];
}
int main()
{
    std::vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    // std::vector<int> cost = {10,15,20};
    // std::vector<int> cost = {0, 0, 0, 0};
    auto res = minCostClimbingStairs(cost);
    return 0;
}