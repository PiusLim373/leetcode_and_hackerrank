#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>

bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
  std::map<int, std::vector<int>> graph;
  for (auto prerequisite : prerequisites)
  {
    graph[prerequisite[0]].push_back(prerequisite[1]);
  }

  std::vector<int> visited(numCourses, 0);
  for (int i = 0; i < numCourses; i++)
  {
    if (visited[i] == 0)
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
            return false;
        }

        if (!has_unvisited_neigh)
        {
          stack.pop();
          visited[curr] = 2;
        }
      }
    }
  }
  return true;
}

bool dfs(int course, std::map<int, int>& visited, std::map<int, std::vector<int>>& graph)
{
  if (visited[course] == 1)
    return false;
  if (visited[course] == 2)
    return true;
  visited[course] = 1;
  for (auto neight : graph[course])
  {
    if (!dfs(neight, visited, graph))
      return false;
  }
  visited[course] = 2;
  return true;
}

bool canFinishCantUnderStand(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
  std::map<int, std::vector<int>> graph;
  for (auto prerequisite : prerequisites)
  {
    graph[prerequisite[0]].push_back(prerequisite[1]);
  }

  std::map<int, int> visited;
  for (int i = 0; i < numCourses; i++)
  {
    if (!dfs(0, visited, graph))
      return false;
  }
  return true;
}
int main()
{
  // std::vector<std::vector<int>> prerequisites = { { 1, 0 }, { 0, 1 } };
  // int numCourses = 2;

//   std::vector<std::vector<int>> prerequisites = { { 0, 1 }, { 3, 1 }, { 1, 3 }, { 3, 2 } };
//   int numCourses = 4;

    std::vector<std::vector<int>> prerequisites = { { 0, 1 }, { 0, 2 }, { 1, 3 }, { 1, 4 }, { 3, 4 } };
    int numCourses = 5;
  bool ans = canFinish(numCourses, prerequisites);
  return 0;
}
