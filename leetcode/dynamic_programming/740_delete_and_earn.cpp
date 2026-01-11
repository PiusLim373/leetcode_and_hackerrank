#include <vector>
#include <map>

int deleteAndEarn(std::vector<int> &nums)
{
    // since decide to take that number will always ends up take all nums, so convert to a point vector to remove duplicate
    std::vector<int> fre_vec(10e4, 0);
    for (auto x : nums)
        fre_vec[x]++;
    std::vector<int> points = {0, 0}; // start with 2 * 0 point, coz we need to decide backwards until i - 2
    for (int i = 0; i < fre_vec.size(); i++)
        points.push_back(i * fre_vec[i]);

    // we init a dp to store the best points up until i
    std::vector<int> dp(points.size(), 0);
    for (int i = 2; i < points.size(); i++)
    {
        dp[i] = std::max(
            dp[i - 2] + points[i], // take curr and prev (we cant take i-1)
            dp[i - 1]              // skip curr and take prev
        );
    }
    return dp[dp.size() - 1]; // return last, also the best result
}

int main()
{
    // std::vector<int> nums = {2, 2, 3, 3, 3, 4};
    std::vector<int> nums = {1, 2, 3, 15, 16, 17, 18};
    auto ans = deleteAndEarn(nums);
    return 0;
}
