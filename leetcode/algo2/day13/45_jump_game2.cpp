#include <iostream>
#include <vector>
#include <queue>

int jump(std::vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;
    std::vector<bool> v(nums.size(), false);
    std::vector<int> j(nums.size(), 0);
    std::queue<int> q;

    q.push(0);
    v[0] = true;
    j[0] = 0;

    while (!q.empty())
    {
        int curr_index = q.front();
        int jumps = nums[curr_index];
        q.pop();
        if (nums[curr_index] == 0)
            continue;
        for (int i = curr_index + 1; i <= curr_index + jumps; i++)
        {
            if (i >= nums.size() - 1)
                return ++j[curr_index];
            else if (v[i] != true)
            {
                q.push(i);
                v[i] = true;
                j[i] = j[curr_index] + 1;
            }
        }
    }
    return -1;
}
int jump_bugged(std::vector<int> &nums)
{
    int curr = 0;
    int jump_count = 0;
    while (nums[curr] != 0)
    {
        int max = -1;
        int max_index = -1;
        for (int i = curr + 1; i <= curr + nums[curr]; i++)
        {
            if (i >= nums.size() - 1)
                return ++jump_count;
            else
            {
                if (nums[i] > max)
                {
                    max = nums[i];
                    max_index = i;
                }
            }
        }
        curr = max_index;
        jump_count++;
    }
}
int main()
{
    // std::vector<int> nums = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
    std::vector<int> nums = {0};
    std::cout << jump(nums) << std::endl;
}