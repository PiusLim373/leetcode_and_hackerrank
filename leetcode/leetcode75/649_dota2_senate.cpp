#include <deque>
#include <string>
std::string predictPartyVictory(std::string senate)
{
    std::deque<int> r_d;
    std::deque<int> d_d;
    for (int i = 0; i < senate.size(); i++)
    {
        if (senate[i] == 'R')
            r_d.push_back(i);
        else
            d_d.push_back(i);
    }

    while (!r_d.empty() && !d_d.empty())
    {
        if (r_d.front() < d_d.front())
            r_d.push_back(r_d.front() + senate.size());
        else
            d_d.push_back(d_d.front() + senate.size());
        d_d.pop_front();
        r_d.pop_front();
    }
    if (r_d.empty())
        return "Dire";
    else
        return "Radiant";
}
int main()
{
    // std::string senate = "RDD";
    std::string senate = "DDDDRRDDDRDRDRRDDRDDDRDRRRRDRRRRRDRDDRDDRRDDRRRDDRRRDDDDRRRRRRRDDRRRDDRDDDRRRDRDDRDDDRRDRRDRRRDRDRDR";
    auto ans = predictPartyVictory(senate);
    return 0;
}
