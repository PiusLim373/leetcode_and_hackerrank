#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> partitionLabels(std::string s)
{
    std::unordered_map<char, int> last_index_map;
    for (int i = 0; i < s.size(); i++)
        last_index_map[s[i]] = i;
    std::vector<int> ans;

    int size = 0;
    int last = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char curr = s[i];
        int curr_last_index = last_index_map[curr];
        size++;
        last = std::max(last, curr_last_index);
        if (i == last)
        {
            // push size, reset
            ans.push_back(size);
            size = 0;
        }
    }
    if (size)
        ans.push_back(size);
    return ans;
}
int main()
{
    std::string s = "a";

    auto ans = partitionLabels(s);
    return 0;
}