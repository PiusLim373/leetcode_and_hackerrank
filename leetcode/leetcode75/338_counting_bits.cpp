#include <vector>
#include <unordered_map>
std::vector<int> countBits(int n)
{
    std::unordered_map<int, int> zeros;
    std::vector<int> ans;
    zeros[0] = 0;
    zeros[1] = 1;
    zeros[2] = 1;
    for (int i = 0; i <= n; i++)
    {
        if (i <= 2)
            ans.push_back(zeros[i]);
        else
        {
            int count = zeros[i / 2] + i % 2;
            zeros[i] = count;
            ans.push_back(count);
        }
    }
    return ans;
}
int main()
{
    int n = 10;
    auto ans = countBits(n);
    return 0;
}