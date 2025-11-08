#include <vector>
#include <map>

int longestOnes(std::vector<int> &nums, int k)
{
    int left = 0;
    int max_streak = 0;
    int zeros_flipped = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!nums[i])
        {
            zeros_flipped++;
        }

        while (zeros_flipped > k)
        {
            if (!nums[left])
            {
                zeros_flipped--;
            }
            left++;
        }
        int streak = i - left + 1;
        if (streak > max_streak)
            max_streak = streak;
    }
    return max_streak;
}
int longestOnesNotWorking(std::vector<int> &nums, int k)
{
    int max_streak = 0;
    int streak = 0;
    int chance = k;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            streak++;
            if (streak > max_streak)
                max_streak = streak;
        }
        else
        {
            if (chance)
            {
                chance--;
                streak++;
                if (streak > max_streak)
                    max_streak = streak;
            }
            else
            {
                // slide window to reclaim chance
                for (int j = i - streak; j < i; j++)
                {
                    if (nums[j])
                        streak--;
                    else
                    {
                        streak--;
                        chance++;
                        if (j == i - 1)
                            streak++;
                    }
                    if (chance)
                        break;
                }
            }
        }
    }
    return max_streak;
}

int main()
{
    std::vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    // std::vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    // std::vector<int> nums = {0, 0, 1, 1};
    // std::vector<int> nums = {0, 0, 0, 0, 1};
    // 0,0,0,0,1
    int k = 2;
    auto ans = longestOnes(nums, k);
    return 1;
}