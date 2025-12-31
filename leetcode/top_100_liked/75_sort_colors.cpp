#include <vector>

void sortColors(std::vector<int> &nums)
{

    int low = 0;
    int high = nums.size() - 1;
    int mid = 0;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            std::swap(nums[low], nums[mid]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main()
{
    std::vector<int> nums = {2, 0};
    sortColors(nums);

    return 0;
}