#include <vector>
int findNumberOfLIS(std::vector<int> &nums)
{
    // len[] to keep track the length of lis at pos i, init to 1 becoz each element is a lis itself
    // cnt[] to keep track of number of lis with len[i] at pos i, init to 1 becoz each element is a lis itself
    std::vector<int> len(nums.size(), 1);
    std::vector<int> cnt(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++)
    {
        // check all previous elements
        for (int j = 0; j < i; j++)
        {
            // smaller element found
            if (nums[j] < nums[i])
            {
                // longer subsequent found
                if (len[j] + 1 > len[i])
                {
                    len[i] = len[j] + 1; // hence length + 1
                    cnt[i] = cnt[j];     // cnt just copy over becoz this only keep track of longest
                }

                // found another way to reach here
                else if (len[j] + 1 == len[i])
                    cnt[i] += cnt[j]; // update the count
            }
        }
    }

    // find the max length
    int max_length = *std::max_element(len.begin(), len.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // only count those with global max lis length
        if (len[i] == max_length)
            sum += cnt[i];
    }
    return sum;
}

int main()
{
    // std::vector<int> nums = {1, 3, 5, 4, 7};
    std::vector<int> nums = {2, 2, 2, 2, 2};
    auto ans = findNumberOfLIS(nums);
    return 0;
}