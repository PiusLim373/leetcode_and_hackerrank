#include <queue>
#include <vector>
#include <unordered_map>

struct Compare
{
    bool operator()(std::pair<int, int> &lhs, std::pair<int, int> &rhs)
    {
        return lhs.first > rhs.first;
    }
};

std::vector<int> topKFrequent(std::vector<int> &nums, int k)
{
    std::unordered_map<int, int> fre_map;
    for (auto x : nums)
        fre_map[x]++;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;
    for (auto x : fre_map)
    {
        if (pq.size() < k)
            pq.push({x.second, x.first});
        else
        {
            auto [fre, num] = pq.top();
            if (x.second > fre)
            {
                pq.pop();
                pq.push({x.second, x.first});
            }
        }
    }
    std::vector<int> ans;
    while (!pq.empty())
    {
        auto [fre, num] = pq.top();
        ans.push_back(num);
        pq.pop();
    }
    return ans;
}
int main()
{
    std::vector<int> nums = {1};
    int k = 2;
    auto ans = topKFrequent(nums, k);
    return 0;
}