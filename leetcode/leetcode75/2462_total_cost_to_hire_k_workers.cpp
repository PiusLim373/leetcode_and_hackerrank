#include <queue>
#include <iostream>
#include <vector>

struct firstLowerTop
{
    bool operator()(std::pair<int, int> lhs, std::pair<int, int> rhs)
    {
        return lhs.first > rhs.first;
    }
};
std::vector<std::pair<int, int>> formPairVector(std::vector<int> costs)
{
    std::vector<std::pair<int, int>> pair_v;
    for (int i = 0; i < costs.size(); i++)
        pair_v.push_back({costs[i], i});
    return pair_v;
}
long long totalCost(std::vector<int> &costs, int k, int candidates)
{
    std::vector<std::pair<int, int>> pair_v = formPairVector(costs);
    long long total_cost = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, firstLowerTop> queue;
    for (int i = 0; i < candidates; i++)
        queue.push(pair_v[i]);
    int front_end = candidates - 1;
    int back_end = pair_v.size() - 1;
    for (; back_end >= static_cast<int>(pair_v.size()) - candidates; back_end--)
    {
        if (back_end <= front_end)
            break;
        queue.push(pair_v[back_end]);
        std::cout << "push" <<std::endl;
    }
    back_end++;
    for (int count = 0; count < k; count++)
    {
        auto [cost, index] = queue.top();
        queue.pop();
        total_cost += cost;

        if (index <= front_end)
        {
            front_end++;
            if (front_end < back_end)
                queue.push(pair_v[front_end]);
        }
        else
        {
            back_end--;
            if (back_end > front_end)
                queue.push(pair_v[back_end]);
        }
    }
    return total_cost;
}
long long totalCostTimedOut(std::vector<int> &costs, int k, int candidates)
{
    std::vector<std::pair<int, int>> pair_v = formPairVector(costs);

    long long total_cost = 0;
    for (int count = 0; count < k; count++)
    {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, firstLowerTop> left_pq, right_pq;
        for (int i = 0; i < candidates; i++)
        {
            if (i == pair_v.size())
                break;
            left_pq.push(pair_v[i]);
        }
        for (int i = pair_v.size() - 1; i >= static_cast<int>(pair_v.size()) - candidates; i--)
        {

            if (i == -1)
                break;
            right_pq.push(pair_v[i]);
        }

        auto [left_top_cost, left_top_index] = left_pq.top();
        auto [right_top_cost, right_top_index] = right_pq.top();

        if (left_top_cost < right_top_cost)
        {
            total_cost += left_top_cost;
            costs.erase(costs.begin() + left_top_index);
        }
        else if (left_top_cost > right_top_cost)
        {
            total_cost += right_top_cost;
            costs.erase(costs.begin() + right_top_index);
        }
        else
        {
            if (left_top_index <= right_top_index)
            {
                total_cost += left_top_cost;
                costs.erase(costs.begin() + left_top_index);
            }
            else if (left_top_index > right_top_index)
            {
                total_cost += right_top_cost;
                costs.erase(costs.begin() + right_top_index);
            }
        }
        pair_v = formPairVector(costs);
    }
    return total_cost;
}
int main()
{
    // std::vector<int> costs = {17, 12, 10, 2, 7, 2, 11, 20, 8};
    std::vector<int> costs = {1, 2, 4, 1};
    int k = 3;
    int candidates = 3;
    auto ans = totalCost(costs, k, candidates);

    return 0;
}