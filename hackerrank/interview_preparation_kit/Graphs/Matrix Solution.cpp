#include <bits/stdc++.h>
using namespace std;
int minTime(int n, vector<vector<int>> roads, vector<int> machines)
{
    int time = 0;
    vector<bool> base(n + 1);
    vector<int> nodes(n + 1);
    map<int, vector<pair<int, int>>> m;
    vector<unordered_set<int>> sets(n + 1);

    // Put each city in its own group.
    for (int i = 0; i <= n; i++)
    {
        nodes[i] = i;
        sets[i].insert(i);
    }

    // Mark each group with a machine.
    for (int m : machines)
    {
        base[m] = true;
    }

    // Build map indexed by road value.
    for (auto r : roads)
    {
        m[r[2]].push_back({r[0], r[1]});
    }

    // Add roads starting with largest time value.
    for (auto rs = m.rbegin(); rs != m.rend(); rs++)
    {
        for (auto r : rs->second)
        {
            int b1 = nodes[r.first];
            int b2 = nodes[r.second];

            // If both groups already have a machine delete this road.
            if (base[b1] && base[b2])
            {
                time += rs->first;
                // Merge the groups.
            }
            else
            {
                base[b1] = base[b1] || base[b2];
                for (auto n : sets[b2])
                {
                    sets[b1].insert(n);
                    nodes[n] = b1;
                }
            }
        }
    }
    return time;
}

int main()
{
    // vector<vector<int>> roads = {{2, 1, 8}, {1, 0, 5}, {2, 4, 5}, {1, 3, 4}};
    // vector<int> machines = {2, 4, 0};

    vector<vector<int>> roads = {{0, 1, 4}, {0, 2, 8}, {1, 3, 7}, {1, 4, 2}};
    vector<int> machines = {2, 4, 3};
    int n = 5;

    // vector<vector<int>> roads = {{0, 3, 3}, {1, 4, 4}, {1, 3, 4}, {0, 2, 5}};
    // vector<int> machines = {1, 4, 3};
    int ans = minTime(n, roads, machines);
    cout << ans << endl;
}