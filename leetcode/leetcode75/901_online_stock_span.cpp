#include <stack>
#include <memory>
#include <vector>
#include <iostream>

class StockSpanner
{
public:
    StockSpanner()
    {
    }
    int next(int price)
    {
        int ans;
        if (s.empty())
            ans = 1;
        else
        {
            ans = 1;
            while (!s.empty())
            {
                auto [prev_price, prev_day] = s.top();
                if (price >= prev_price)
                {
                    s.pop();
                    ans += prev_day;
                }
                else
                    break;
            }
        }
        s.push({price, ans});
        return ans;
    }

private:
    std::stack<std::pair<int, int>> s;
};

class StockSpannerNotWorking
{
public:
    StockSpannerNotWorking()
    {
        index = 0;
    }

    int next(int price)
    {
        int ans = -1;
        if (s.empty())
        {
            s.push({price, index});
            ans = 1;
        }
        else
        {
            while (!s.empty())
            {
                auto [prev_price, prev_index] = s.top();
                if (prev_price > price)
                {
                    ans = index - prev_index;
                    break;
                }
                else
                {
                    ans = index - prev_index;
                    s.pop();
                }
            }
            s.push({price, index});
        }
        index++;
        return ans;
    }

private:
    std::stack<std::pair<int, int>> s;
    int index;
};

int main()
{
    auto ss = std::make_shared<StockSpanner>();
    std::vector<int> test = {100, 80, 60, 70, 60, 75};
    // std::vector<int> test = {7, 34, 1, 2, 8};
    // std::vector<int> test = {100, 31, 41, 48, 59, 79};
    for (auto x : test)
        std::cout << ss->next(x) << std::endl;
    return 0;
}