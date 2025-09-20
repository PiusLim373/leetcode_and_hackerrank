#include <vector>
#include <map>
#include <set>
std::vector<std::vector<int>> findDifference(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::map<int, int> m1, m2;
    for (auto x : nums1)
        m1[x]++;
    for (auto x : nums2)
        m2[x]++;

    std::vector<int> v1, v2;
    for (auto x : m1)
    {
        if (!m2[x.first])
            v1.push_back(x.first);
    }
    for (auto x : m2)
    {
        if (!m1[x.first])
            v2.push_back(x.first);
    }
    return {v1, v2};
}
int main()
{
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {2, 4, 6};
    auto res = findDifference(nums1, nums2);
    return 1;
}