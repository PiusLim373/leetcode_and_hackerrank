#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>

std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
  std::map<int, std::vector<int>> graph;
  for (auto prerequisite : prerequisites)
  {
    graph[prerequisite[0]].push_back(prerequisite[1]);
  }
  std::vector<int> ans;
  std::vector<int> visited(numCourses, 0);  // 0 for unvisited, 1 for current, 2 for done
  for (int i = 0; i < numCourses; i++)
  {
    if (visited[i] == 0)  // only visit those haven been visited
    {
      std::stack<int> stack;
      stack.push(i);

      while (!stack.empty())
      {
        int curr = stack.top();

        if (visited[curr] == 0)
          visited[curr] = 1;

        bool has_unvisited_neigh = false;
        for (auto neigh : graph[curr])
        {
          if (visited[neigh] == 0)
          {
            has_unvisited_neigh = true;
            stack.push(neigh);
          }
          else if (visited[neigh] == 1)
            return {};
        }

        if (!has_unvisited_neigh)
        {
          stack.pop();
          if (visited[curr] != 2)
            ans.push_back(curr);
          visited[curr] = 2;
        }
      }
    }
  }
  return ans;
}

int main()
{
  // std::vector<std::vector<int>> prerequisites = { { 1, 0 }, { 0, 1 } };
  // int numCourses = 2;

  // std::vector<std::vector<int>> prerequisites = { { 1, 0 }, { 2, 0 }, { 3, 1 }, { 3, 2 } };
  // int numCourses = 4;

  // std::vector<std::vector<int>> prerequisites = { { 5, 0 }, { 4, 0 }, { 0, 1 }, { 0, 2 }, { 1, 3 }, { 3, 2 } };
  // int numCourses = 6;

  std::vector<std::vector<int>> prerequisites = { { 1, 0 }, { 0, 3 }, { 0, 2 }, { 3, 2 },
                                                  { 2, 5 }, { 4, 5 }, { 5, 6 }, { 2, 4 } };
  int numCourses = 7;
  auto ans = findOrder(numCourses, prerequisites);
  return 0;
}
