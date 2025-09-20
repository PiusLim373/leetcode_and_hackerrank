#include <vector>
#include <unordered_map>

bool uniqueOccurrences(std::vector<int> &arr)
{
    std::unordered_map<int, int> m, fre_map;
    for (auto x : arr)
        m[x]++;
    for (auto x : m)
    {
        fre_map[x.second]++;
        if (fre_map[x.second] > 1)
            return false;
    }
    return true;
}

int main()
{
    std::vector<int> arr = {1, 2, 2, 1, 1, 3};
    return 0;
}