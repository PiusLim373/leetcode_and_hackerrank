#include <vector>
#include <stack>
#include <string>
#include <algorithm>
std::string getDirection(int a)
{
    return (a < 0) ? "left" : "right";
}

std::vector<int> asteroidCollision(std::vector<int> &asteroids)
{
    std::stack<int> s;
    for (auto a : asteroids)
    {
        while (!s.empty() && s.top() > 0 && a < 0)
        {
            int diff = abs(s.top()) - abs(a);
            if (diff > 0)
                a = 0;
            else if (diff < 0)
            {
                s.pop();
            }
            else
            {
                a = 0;
                s.pop();
            }
        }
        if (a != 0)
            s.push(a);
    }

    std::vector<int> ans;

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
}
std::vector<int> asteroidCollisionNotWorking2(std::vector<int> &asteroids)
{
    std::stack<int> asteroid_s;
    std::stack<std::string> direction_s;

    direction_s.push(getDirection(asteroids[0]));
    asteroid_s.push(asteroids[0]);

    for (int i = 1; i < asteroids.size(); i++)
    {
        int curr_asteroid = asteroids[i];
        std::string curr_direction = getDirection(asteroids[i]);

        if (direction_s.top() == curr_direction || (direction_s.top() == "left" && curr_direction == "right"))
        {
            asteroid_s.push(curr_asteroid);
            direction_s.push(curr_direction);
        }

        else
        {
            if (abs(asteroid_s.top()) == abs(curr_asteroid))
            {
                asteroid_s.pop();
                direction_s.pop();
            }
            else if (abs(asteroid_s.top()) > abs(curr_asteroid))
            {
                // incoming exploded, nothing to do
            }
            else
            {
                bool incoming_exploded = false;

                // incoming bigger, keep popping stack if direction diff
                int check_asteriod = asteroid_s.top();
                std::string check_direction = direction_s.top();
                while (
                    !asteroid_s.empty() && check_direction == "right" && (abs(curr_asteroid) >= abs(check_asteriod)))
                {
                    asteroid_s.pop();
                    direction_s.pop();
                    if (abs(curr_asteroid) == abs(check_asteriod))
                    {
                        incoming_exploded = true;
                    }
                    if (!asteroid_s.empty())
                    {
                        check_asteriod = asteroid_s.top();
                        check_direction = direction_s.top();
                    }
                }

                if (!incoming_exploded && (asteroid_s.empty() || curr_direction == direction_s.top()))
                {
                    asteroid_s.push(curr_asteroid);
                    direction_s.push(curr_direction);
                }
            }
        }
    }

    std::vector<int> ans;

    while (!asteroid_s.empty())
    {
        ans.push_back(asteroid_s.top());
        asteroid_s.pop();
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
}

std::vector<int> asteroidCollision2(std::vector<int> &asteroids)
{
    std::string direction = getDirection(asteroids[0]);
    std::stack<int> s;
    s.push(asteroids[0]);

    for (int i = 1; i < asteroids.size(); i++)
    {
        std::string new_direction = getDirection(asteroids[i]);
        if (direction == new_direction || (direction == "left" && new_direction == "right"))
        {
            s.push(asteroids[i]);
            direction = new_direction;
        }
        else
        {
            if (abs(s.top()) == abs(asteroids[i]))
                s.pop(); // both exploded
            else if (abs(s.top()) > abs(asteroids[i]))
            {
                // incoming exploded
            }
            else
            {
                while (!s.empty() && abs(s.top()) < abs(asteroids[i]))
                    s.pop(); // keep remove from stack
                if (s.empty())
                {
                    s.push(asteroids[i]);
                    direction = new_direction;
                }
            }
        }
    }

    std::vector<int> ans;

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    // std::vector<int> asteroids = {-2, -2, 1, -2};
    // std::vector<int> asteroids = {5, 10, -5};
    // std::vector<int> asteroids = {3, 5, -6, 2, -1, 4};
    // std::vector<int> asteroids = {-2, 2, 1, -2};
    std::vector<int> asteroids = {1, -1, -2, -2};

    auto ans = asteroidCollision(asteroids);
    return 0;
}