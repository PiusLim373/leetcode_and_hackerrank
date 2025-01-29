#include <vector>
#include <iostream>

int minSubArrayLen(int target, std::vector<int> &nums)
{
    int left = 0;
    int right = 0;
    int min_length = INT16_MAX;
    int sum = nums[0];
    while (left < nums.size() && right < nums.size())
    {
        if (sum >= target)
        {
            min_length = std::min(min_length, right - left + 1);
            sum -= nums[left++];
        }
        else
            sum+= nums[++right];
    }
    if (min_length == INT16_MAX)
        return 0;
    return min_length;
}

int main()
{
    std::vector<int> a = {1,2,3,4,5};
    std::cout << minSubArrayLen(11, a);
}