#include <vector>

int largestAltitude(std::vector<int> &gain)
{
    int max = 0;
    int alt = 0;
    for (auto x : gain)
    {
        alt += x;
        max = std::max(max, alt);
    }
    return max;
}
int main()
{
    std::vector<int> gain = {-4,-3,-2,-1,4,3,2};
    auto ans = largestAltitude(gain);
    return 1;
}