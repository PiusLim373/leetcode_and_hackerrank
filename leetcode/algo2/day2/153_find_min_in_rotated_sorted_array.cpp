#include <vector>
#include <iostream>
int findMin(std::vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    return nums[left];
}
int main()
{
    std::vector<int> matrix = {3, 4, 5, 1, 2};
    std::cout << findMin(matrix) << std::endl;
}