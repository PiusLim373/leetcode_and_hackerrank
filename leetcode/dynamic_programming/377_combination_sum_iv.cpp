#include <vector>
#include <unordered_map>
// dp solution

int recv(std::vector<int> &nums, int remaining, std::unordered_map<int, int> &memo)
{
    if (remaining == 0)
        return 1; // only 1 way to get amount of 0, select nothing
    if (memo.contains(remaining))
        return memo[remaining]; // if memo has, no need solve again;

    int ways = 0;
    for (auto x : nums)
    {
        if (remaining >= x)
        {
            ways += recv(nums, remaining - x, memo);
        }
    }
    memo[remaining] = ways;
    return ways;
}

int combinationSum4(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> memo;
    return recv(nums, target, memo);
}

// pure backtracking solution
void recv_backtracking(std::vector<int> &nums, int remaining, int &ways)
{
    if (remaining == 0)
        ways++;
    for (auto x : nums)
    {
        if (remaining >= x)
            recv_backtracking(nums, remaining - x, ways);
    }
}
int combinationSum4_backtracking(std::vector<int> &nums, int target)
{
    int ways = 0;
    recv_backtracking(nums, target, ways);
    return ways;
}
int main()
{
    std::vector<int> nums = {1, 2, 3};
    // std::vector<int> nums = {9};
    int target = 4;
    auto ans = combinationSum4(nums, target);
    return 0;
}