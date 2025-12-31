#include <vector>

// correct ans is to use a monotonic descreasing deque
std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    int max = nums[0];
    int max_pos = 0;
    std::vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        if (nums[i] >= max)
        {
            max = nums[i];
            max_pos = i;
        }
    }
    ans.push_back(max);

    int left = 0;
    for (int i = k; i < nums.size(); i++)
    {
        left++;
        if (left > max_pos)
        {
            max = nums[left];
            max_pos = left;
            for (int j = left; j <= i; j++)
            {
                if (nums[j] >= max)
                {
                    max = nums[j];
                    max_pos = j;
                }
            }
        }

        else if (nums[i] >= max)
        {
            max = nums[i];
            max_pos = i;
        }

        ans.push_back(max);
    }
    return ans;
}
int main()
{
    // std::vector<int> nums = {1, 10, -1, -3, 5, 3, 6, 7};
    std::vector<int> nums = {1};
    int k = 1;
    auto ans = maxSlidingWindow(nums, k);
    return 0;
}