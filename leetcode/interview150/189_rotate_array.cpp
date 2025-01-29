#include <vector>
#include <iostream>
void rotate(std::vector<int> &nums, int k)
{
    std::vector<int> temp(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        int new_place = i + k;
        while( new_place >= nums.size())
            new_place -= nums.size();
        temp[new_place] = nums[i];
    }
    nums = temp;
}
int main()
{
    // std::vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    // std::vector<int> a = {-1,-100,3,99};
    std::vector<int> a = {3,2};
    
    rotate(a, 10);
    for (auto x : a)
        std::cout << x << " ";
}