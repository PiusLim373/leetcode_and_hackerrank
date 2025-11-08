#include <vector>

int longestSubarray(std::vector<int> &nums)
{
    int left = 0;
    int max_streak;
    int delete_count = 0;
    bool has_zeros = false;
    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] == 0)
        {
            delete_count++;
            has_zeros = true;
        }
        while (delete_count > 1)
        {
            if (nums[left] == 0)
            {
                delete_count--;
            }
            left++;
        }
        int streak = right - left + 1;
        if (delete_count)
            streak -= 1;
        if (streak > max_streak)
            max_streak = streak;
    }
    if (!has_zeros)
        return max_streak - 1;
    else
        return max_streak;
}

int main()
{
    std::vector<int> nums = { 0};
    auto ans = longestSubarray(nums);

    return 1;
}