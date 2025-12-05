#include <vector>
#include <algorithm>
int checkPower(long long power, long long threshold)
{
    if (power < threshold)
        return 1;
    else if (power > threshold)
        return -1;
    else
        return 0;
}

std::vector<int> successfulPairs(std::vector<int> &spells, std::vector<int> &potions, long long success)
{
    std::sort(potions.begin(), potions.end());
    std::vector<int> ans;
    for (auto x : spells)
    {
        int left = 0;
        int right = potions.size() - 1;
        int last_valid = potions.size();
        while (left < right)
        {
            int middle = left + (right - left) / 2;
            if (static_cast<long long>(potions[middle]) * x >= success)
            {
                right = middle - 1;
                last_valid = middle;
            }
            else
                left = middle + 1;
        }
        ans.push_back(potions.size() - last_valid);
    }
    return ans;
}
std::vector<int> successfulPairsTimedOut(std::vector<int> &spells, std::vector<int> &potions, long long success)
{
    std::sort(potions.begin(), potions.end());
    std::vector<int> ans;
    for (auto x : spells)
    {
        std::vector<long long> product;
        for (auto y : potions)
            product.push_back(static_cast<long long>(y) * x);

        auto it = std::lower_bound(product.begin(), product.end(), success);

        if (it == product.end())
            ans.push_back(0);
        else
            ans.push_back(product.size() - (it - product.begin()));
    }
    return ans;
}
int main()
{
    // std::vector<int> spells = {5, 1, 3};
    // std::vector<int> potions = {1, 2, 3, 4, 5};

    std::vector<int> spells = {3, 1, 2};
    std::vector<int> potions = {8, 5, 8};
    int success = 16;
    auto ans = successfulPairs(spells, potions, success);
    return 0;
}