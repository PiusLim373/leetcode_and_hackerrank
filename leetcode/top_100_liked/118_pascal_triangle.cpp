#include <vector>
std::vector<std::vector<int>> generate(int numRows)
{
    std::vector<std::vector<int>> ans;
    std::vector<int> prev;
    for (int i = 0; i < numRows; i++)
    {
        if (i == 0)
            ans.push_back({1});
        else if (i == 1)
        {
            prev = {1, 1};
            ans.push_back(prev);
        }
        else
        {
            std::vector<int> temp(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                temp[j] = prev[j - 1] + prev[j];
            }
            prev = temp;
            ans.push_back(temp);
        }
    }
    return ans;
}
int main()
{
    int n = 1;
    auto ans = generate(n);
    return 0;
}