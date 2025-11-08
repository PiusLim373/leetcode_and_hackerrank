#include <vector>
#include <iostream>
#include <algorithm>
std::vector<bool> kidsWithCandies(std::vector<int> &candies, int extraCandies)
{
    int greatest = *std::max_element(candies.begin(), candies.end());
    std::vector<bool> ans;
    for (auto x: candies)
    {
        if(x + extraCandies >= greatest)
            ans.push_back(true);
        else
            ans.push_back(false);
    }
    return ans;
}
int main()
{
    std::vector<int> candies = {12,1,12};
    int extraCandies = 10;

    auto ans = kidsWithCandies(candies, extraCandies);
    return 0;
}