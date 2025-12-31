#include <vector>
int findDuplicate(std::vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    while (1)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];

        if (slow == fast)
            break;
    }

    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
int main()
{
    std::vector<int> nums = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
    auto ans = findDuplicate(nums);
    return 0;
}