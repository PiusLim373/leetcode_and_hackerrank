#include <vector>
#include <unordered_map>

int longestSubsequence(std::vector<int> &arr, int difference)
{
    // a hashmap to tell the longest subsequence at which value
    std::unordered_map<int, int> dp;
    for(int i = 0; i < arr.size(); i++)
    {
        int prev = arr[i] - difference;
        
        // if prev val found in the map, make curr longer by 1
        if(dp.contains(prev))
            dp[arr[i]] = dp[prev] + 1;
        
        // new entry should be 1            
        else
            dp[arr[i]] = 1;
    }

    // return the longest length
    int max = -1;
    for (auto x: dp)
    {
        max = std::max(max, x.second);
    }
    return max;
}

int longestSubsequenceTLE(std::vector<int> &arr, int difference)
{
    std::vector<int> len(arr.size(), 1);
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((arr[i] - arr[j] == difference) && (len[j] + 1 > len[i]))
                len[i] = len[j] + 1;
        }
    }

    return *std::max_element(len.begin(), len.end());
}
int main()
{
    std::vector<int> arr = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    // std::vector<int> arr = {1,2,3,4};
    int diff = -2;
    auto ans = longestSubsequence(arr, diff);
    return 0;
}