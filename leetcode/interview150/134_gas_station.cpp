#include <vector>
int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
{
  if (gas.size() == 1)
  {
    if (gas[0] >= cost[0])
      return 0;
    return -1;
  }
  std::vector<int> nett;
  std::vector<int> trial;

  for (int i = 0; i < gas.size(); i++)
  {
    int temp = gas[i] - cost[i];
    if (temp > 0)
      trial.push_back(i);
    nett.push_back(temp);
  }
  if (!trial.size())
    return -1;
  for (auto x : trial)
  {
    int start = x;
    int status = nett[start++];
    while (status >= 0)
    {
      if (start == x)
        return x;
      if (start >= nett.size())
      {
        start = 0;
        if (start == x)
          return x;
      }
      status += nett[start];
      start++;
    }
  }
  return -1;
}
int main()
{
  //   std::vector<int> gas = { 1, 2, 3, 4, 5 };
  //   std::vector<int> cost = { 3, 4, 5, 1, 2 };
  std::vector<int> gas = { 2 };
  std::vector<int> cost = { 2 };
  //   std::vector<int> gas = {2, 3, 4 };
  //   std::vector<int> cost = { 3, 4,3};
  auto ans = canCompleteCircuit(gas, cost);
  return 0;
}