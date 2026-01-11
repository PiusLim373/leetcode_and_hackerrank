#include <stack>
#include <vector>

std::vector<int> longestObstacleCourseAtEachPosition(std::vector<int> &obstacles)
{
    std::vector<int> res;

    // database to keep track of lis
    std::vector<int> tail;
    for(int i = 0 ; i < obstacles.size(); i++)
    {
        // allow extending (or not strictly increase, so use upper_bound instead of lower_bound)
        auto it = std::upper_bound(tail.begin(), tail.end(), obstacles[i]);
        
        // if adding new element
        if(it == tail.end())
        {
            tail.push_back(obstacles[i]);
            res.push_back(tail.size());
        }

        // if bound found within tail
        else
        {
            tail[it - tail.begin()] = obstacles[i];
            res.push_back(it - tail.begin() + 1);

        }
    }
    return res;
}
int main()
{
    // std::vector<int> obstacles = {3, 1, 5, 6, 4, 2};
    std::vector<int> obstacles = {5,1,5,5,1,3,4,5,1,4};
    auto ans = longestObstacleCourseAtEachPosition(obstacles);
    return 0;
}