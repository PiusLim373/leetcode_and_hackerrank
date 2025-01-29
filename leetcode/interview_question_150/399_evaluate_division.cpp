#include <vector>
#include <string>
#include <map>
#include <queue>

std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values,
                                 std::vector<std::vector<std::string>>& queries)
{
  std::map<std::string, std::vector<std::pair<std::string, double>>> graph;
  for (int i = 0; i < equations.size(); i++)
  {
    graph[equations[i][0]].push_back({ equations[i][1], values[i] * 1.0 });
    graph[equations[i][1]].push_back({ equations[i][0], 1.0 / values[i] });
  }

  std::vector<double> ans;
  for (int i = 0; i < queries.size(); i++)
  {
    if (!graph.count(queries[i][0]) || !graph.count(queries[i][1]))
      ans.push_back(-1.0);
    else if (queries[i][0] == queries[i][1])
      ans.push_back(1.0);

    else
    {
      std::queue<std::pair<std::string, double>> queue;
      std::map<std::string, bool> visited;
      queue.push({ queries[i][0], 1.0 });
      visited[queries[i][0]] = true;
      bool done = false;

      while (!queue.empty() && !done)
      {
        auto [curr, cost] = queue.front();
        queue.pop();

        for (auto endpoint : graph[curr])
        {
          if (endpoint.first == queries[i][1])
          {
            ans.push_back(cost * endpoint.second);
            done = true;
            break;
          }
          if (!visited[endpoint.first])
          {
            queue.push({ endpoint.first, cost * endpoint.second });
            visited[endpoint.first] = true;
          }
        }
      }
      if (!done)
        ans.push_back(-1);
    }
  }
  return ans;
}
int main()
{
  //   std::vector<std::vector<std::string>> equations = { { "a", "b" }, { "b", "c" } };
  //   std::vector<double> values = { 2.0, 3.0 };
  //   std::vector<std::vector<std::string>> queries = {
  //     { "a", "c" }, { "b", "a" }, { "a", "e" }, { "a", "a" }, { "x", "x" }
  //   };

  //   std::vector<std::vector<std::string>> equations = { { "a", "b" }, { "b", "c" }, { "bc", "cd" } };
  //   std::vector<double> values = { 1.5, 2.5, 5.0 };
  //   std::vector<std::vector<std::string>> queries = { { "a", "c" }, { "c", "b" }, { "bc", "cd" }, { "cd", "bc" } };

  //   std::vector<std::vector<std::string>> equations = { { "x1", "x2" }, { "x2", "x3" }, { "x3", "x4" }, { "x4", "x5"
  //   } }; std::vector<double> values = { 3.0, 4.0, 5.0, 6.0 }; std::vector<std::vector<std::string>> queries = { {
  //   "x1", "x5" }, { "x5", "x2" }, { "x2", "x4" },
  //                                                     { "x2", "x2" }, { "x2", "x9" }, { "x9", "x9" } };

  std::vector<std::vector<std::string>> equations = { { "a", "b" }, { "b", "c" }, { "a", "c" }, { "d", "e" } };
  std::vector<double> values = { 2.0, 3.0, 6.0, 1.0 };
  std::vector<std::vector<std::string>> queries = { { "a", "c" }, { "b", "c" }, { "a", "e" },
                                                    { "a", "a" }, { "x", "x" }, { "a", "d" } };

  std::vector<double> output = calcEquation(equations, values, queries);
}