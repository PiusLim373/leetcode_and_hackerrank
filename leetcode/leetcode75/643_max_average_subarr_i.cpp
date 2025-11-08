#include <vector>

double findMaxAverage(std::vector<int> &nums, int k)
{
    std::vector<double> d_nums;
    for (int i = 0; i < nums.size(); i++)
        d_nums.push_back(nums[i] * 1.0 / k);

    double max_ave = 0;
    for (int i = 0; i < k; i++)
    {
        max_ave += d_nums[i];
    }
    double window_ave = max_ave;
    for (int i = k; i < d_nums.size(); i++)
    {
        window_ave -= d_nums[i - k];
        window_ave += d_nums[i];
        if (window_ave > max_ave)
            max_ave = window_ave;
    }
    return max_ave;
}
int main()
{
    std::vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    auto ans = findMaxAverage(nums, k);
    return 1;
}