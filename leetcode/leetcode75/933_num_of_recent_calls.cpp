#include <deque>
#include <memory>
class RecentCounter
{
public:
    std::deque<int> calls;
    RecentCounter()
    {
    }
    int ping(int t)
    {
        while (!calls.empty() && calls.front() < t - 3000)
            calls.pop_front();
        calls.push_back(t);
        return calls.size();
    }
};

int main()
{
    std::shared_ptr<RecentCounter> recent_counter_ptr = std::make_shared<RecentCounter>();
    int ans = 0;
    ans = recent_counter_ptr->ping(1);
    ans = recent_counter_ptr->ping(100);
    ans = recent_counter_ptr->ping(3001);
    ans = recent_counter_ptr->ping(3002);
    return 0;
}