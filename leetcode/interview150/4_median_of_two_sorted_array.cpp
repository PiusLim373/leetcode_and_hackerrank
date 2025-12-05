#include <vector>
#include <math.h>
using namespace std;
double findMedianSortedArraysWorking(vector<int> &nums1, vector<int> &nums2)
{
    // Ensure nums1 is the smaller array
    if (nums1.size() > nums2.size())
        return findMedianSortedArraysWorking(nums2, nums1);

    int n1 = nums1.size();
    int n2 = nums2.size();
    int total = n1 + n2;
    int half = total / 2;

    int left = 0;
    int right = n1;

    while (true)
    {
        // Cut positions (NOT indexes)
        int i = left + (right - left) / 2; // cut in nums1
        int j = half - i;                  // cut in nums2

        // Left and right values from nums1
        int nums1_left = (i == 0) ? -__INT32_MAX__ : nums1[i - 1];
        int nums1_right = (i == n1) ? __INT32_MAX__ : nums1[i];

        // Left and right values from nums2
        int nums2_left = (j == 0) ? -__INT32_MAX__ : nums2[j - 1];
        int nums2_right = (j == n2) ? __INT32_MAX__ : nums2[j];

        // Correct partition
        if (nums1_left <= nums2_right && nums2_left <= nums1_right)
        {
            // Odd total length
            if (total % 2)
                return min(nums1_right, nums2_right);

            // Even total length
            return (max(nums1_left, nums2_left) +
                    min(nums1_right, nums2_right)) /
                   2.0;
        }
        else if (nums1_left > nums2_right)
        {
            // Move cut in nums1 left
            right = i - 1;
        }
        else
        {
            // Move cut in nums1 right
            left = i + 1;
        }
    }
}

double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
        std::swap(nums1, nums2);
    int total_size = nums1.size() + nums2.size();
    if (!total_size)
        return 0.0;
    if (!nums1.size())
    {
        if (nums2.size() % 2)
            return nums2[nums2.size() / 2];
        else
            return ((nums2[(nums2.size() / 2) - 1] + nums2[nums2.size() / 2]) * 1.0) / 2;
    }
    int half = total_size / 2;

    // search for i
    int left = 0;
    int right = nums1.size() - 1;

    while (1)
    {
        int i = floor((left + right) / 2.0);
        int j = half - (i + 1) - 1; // convert number of element to index j

        int nums1_left = (i >= 0) ? nums1[i] : -__INT32_MAX__;
        int nums1_right = ((i + 1) < nums1.size()) ? nums1[i + 1] : __INT32_MAX__;
        int nums2_left = (j >= 0) ? nums2[j] : -__INT32_MAX__;
        int nums2_right = ((j + 1) < nums2.size()) ? nums2[j + 1] : __INT32_MAX__;
        if (nums1_left <= nums2_right && nums2_left <= nums1_right)
        {
            if (total_size % 2)
                return std::min(nums1_right, nums2_right);
            else
                return ((std::max(nums1_left, nums2_left) + std::min(nums1_right, nums2_right)) * 1.0) / 2;
        }
        if (nums1_left > nums2_right)
            right = i - 1;
        else
            left = i + 1;
    }
}

int main()
{
    // std::vector<int> nums1 = {1, 3, 7, 12, 18, 20, 25}; // 12
    // std::vector<int> nums2 = {2, 4, 6, 10, 15};         // 6

    // std::vector<int> nums1 = {1, 2, 3, 5, 5, 6, 7, 8}; // 12
    // std::vector<int> nums2 = {1, 2, 3, 4, 5};          // 6

    std::vector<int> nums1 = {1, 3}; // 12
    std::vector<int> nums2 = {2};    // 6
    auto ans = findMedianSortedArrays(nums1, nums2);
    return 0;
}