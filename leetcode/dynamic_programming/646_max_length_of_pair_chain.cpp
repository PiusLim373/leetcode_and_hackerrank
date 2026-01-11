#include <vector>

int findLongestChain(std::vector<std::vector<int>> &pairs)
{
    // sort like intervals
    std::sort(pairs.begin(), pairs.end(), [](std::vector<int> &lhs, std::vector<int> &rhs)
              { return lhs[0] < rhs[0]; });

    // len that keep track of max pair chain up until pos i
    std::vector<int> len(pairs.size(), 1);
    for(int i = 1; i < pairs.size(); i++)
    {
        // check all previous pairs
        for(int j = 0; j < i; j++)
        {
            // requirements: no overlapping
            if(pairs[i][0] > pairs[j][1])
            {
                // found a longer chain, update len
                if(len[j] + 1 > len[i])
                {
                    len[i] = len[j]+ 1;
                }
            }
        }
    }

    // return max length
    return *std::max_element(len.begin(), len.end());
}

int main()
{
    // std::vector<std::vector<int>> pairs = {{1, 2}, {7, 8}, {3, 4}};
    std::vector<std::vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
    auto ans = findLongestChain(pairs);
    return 0;
}