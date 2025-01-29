#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank)
{
  if (std::find(bank.begin(), bank.end(), endGene) == bank.end())  // cant find endgene in bank;
    return -1;
  std::map<std::string, bool> visited;
  std::queue<std::pair<std::string, int>> queue;
  queue.push({ startGene, 0 });
  visited[startGene] = true;
  std::string gene = "ATGC";

  while (!queue.empty())
  {
    auto [curr, mutation] = queue.front();
    queue.pop();

    // generate mutations
    for (int i = 0; i < curr.size(); i++)
    {
      for (auto character : gene)
      {
        if (character != curr[i])
        {
          std::string temp = curr;
          temp[i] = character;

          if (temp == endGene)
            return mutation + 1;
          if (std::find(bank.begin(), bank.end(), temp) != bank.end() && !visited[temp])
          {
            queue.push({ temp, mutation + 1 });
            visited[temp] = true;
          }
        }
      }
    }
  }
  return -1;
}
int main()
{
  //   std::string startGene = "AACCGGTT";
  //   std::string endGene = "AAACGGTA";
  //   std::vector<std::string> bank = { "AACCGGTA", "AACCGCTA", "AAACGGTA" };

  std::string startGene = "AAAAAAAT";
  std::string endGene = "CCCCCCCC";
  std::vector<std::string> bank = { "AAAAAAAC", "AAAAAAAA", "CCCCCCCC" };
  int ans = minMutation(startGene, endGene, bank);
  return 0;
}