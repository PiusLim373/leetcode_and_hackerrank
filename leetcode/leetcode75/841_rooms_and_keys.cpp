#include <iostream>
#include <vector>
#include <stack>
#include <map>
bool canVisitAllRooms(std::vector<std::vector<int>> &rooms)
{

    std::stack<int> s;
    s.push(0);
    std::map<int, bool> visited;
    visited[0] = true;
    int total_room = rooms.size();
    while (!s.empty())
    {
        int curr = s.top();
        s.pop();
        total_room--;
        for (auto room : rooms[curr])
        {
            if (!visited[room])
            {
                s.push(room);
                visited[room] = true;
            }
        }
    }
    if (total_room)
        return false;
    return true;
}

int main()
{
    std::vector<std::vector<int>> rooms = {{1}, {2}, {3}, {}};
    // std::vector<std::vector<int>> rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
    auto res = canVisitAllRooms(rooms);
    return 0;
}