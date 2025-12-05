#include <vector>
int candy(std::vector<int> &ratings)
{
    std::vector<int> ans(ratings.size(), 1);
    for (int i = 0; i < ratings.size() - 1; i++)
    {
        if (ratings[i + 1] > ratings[i])
            ans[i + 1] = ans[i] + 1;
    }
    for (int i = ratings.size() - 1; i > 0; i--)
    {
        if (ratings[i - 1] > ratings[i] && ans[i - 1] <= ans[i])
            ans[i - 1] = ans[i] + 1;
    }
    int sum = 0;
    for (auto x : ans)
        sum += x;
    return sum;
}
int main()
{
    // std::vector<int> ratings = {5, 4, 3, 5, 6, 2};
    std::vector<int> ratings = {0, 5, 4, 6, 3, 2, 1, 0};
    auto ans = candy(ratings);
    return 0;
}