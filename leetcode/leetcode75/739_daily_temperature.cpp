#include <vector>
#include <stack>
std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
{
    std::stack<std::pair<int, int>> s;
    std::vector<int> ans;
    ans.resize(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++)
    {
        if(s.empty())
        {
            s.push({temperatures[i], i});
        }
        else
        {
            while(!s.empty())
            {
                auto [prev_temp, prev_index] = s.top();
                if(temperatures[i] > prev_temp)
                {
                    ans[prev_index] = i - prev_index;
                    s.pop();
                }
                else
                {
                    break;
                }
            }
            s.push({temperatures[i], i});

        }
    }
    return ans;
}
int main()
{
    // std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> temperatures = {30, 40, 50, 60};
    auto ans = dailyTemperatures(temperatures);
    return 0;
}
