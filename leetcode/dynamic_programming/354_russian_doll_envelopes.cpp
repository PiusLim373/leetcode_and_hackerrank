#include <vector>
#include <algorithm>
int maxEnvelopes(std::vector<std::vector<int>> &envelopes)
{
    // conventinal lis need On^2, loop j < i from 0 to i, but this quest will TLE, so need to use this sort
    // for same width, sort decending for height
    // else sort ascending width
    std::sort(envelopes.begin(), envelopes.end(), [](std::vector<int> &lhs, std::vector<int> &rhs)
              {
                  if (lhs[0] == rhs[0])
                  {
                      return lhs[1] > rhs[1];
                  }
                  else
                      return lhs[0] < rhs[0]; });

    // data to hold the lis
    std::vector<int> tail;
    for (int i = 0; i < envelopes.size(); i++)
    {
        // use lower bound so that the serach is binary and faster
        auto it = std::lower_bound(tail.begin(), tail.end(), envelopes[i][1]);
        if (it == tail.end())
            tail.push_back(envelopes[i][1]);
        else
            tail[it - tail.begin()] = envelopes[i][1];
    }

    return tail.size();
}
int main()
{
    std::vector<std::vector<int>> envelopes = {{4,5},{4,6},{6,7},{2,3},{1,1}};
    // std::vector<std::vector<int>> envelopes = {{2, 100}, {3, 200}, {4, 300}, {5, 500}, {5, 400}, {5, 250}, {6, 370}, {6, 360}, {7, 380}};
    auto ans = maxEnvelopes(envelopes);
    return 0;
}