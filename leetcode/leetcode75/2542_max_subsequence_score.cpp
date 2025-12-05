#include <queue>
#include <algorithm>
#include <vector>

long long maxScore(std::vector<int> &nums1, std::vector<int> &nums2, int k)
{
    std::vector<std::pair<int, int>> pair_v;
    for (int i = 0; i < nums1.size(); i++)
        pair_v.push_back({nums1[i], nums2[i]});
    std::sort(pair_v.begin(), pair_v.end(), [](std::pair<int, int> lhs, std::pair<int, int> rhs)
              { return (lhs.second > rhs.second); });

    int first_sum = 0;
    long long ans = 0;

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (auto x : pair_v)
    {
        first_sum += x.first;
        pq.push(x.first);

        if (pq.size() > k)
        {
            first_sum -= pq.top();
            pq.pop();
        }
        if (pq.size() == k)
        {
            long long product = first_sum * x.second;
            ans = std::max(ans, product);
        }
    }

    return ans;
    
}
int main()
{
    // std::vector<int> nums1 = {4, 2, 3, 1, 1};
    // std::vector<int> nums2 = {7, 5, 10, 9, 6};

    std::vector<int> nums1 = {2, 1, 14, 12};
    std::vector<int> nums2 = {11, 7, 13, 6};
    int k = 3;
    auto ans = maxScore(nums1, nums2, k);
    return 0;
}