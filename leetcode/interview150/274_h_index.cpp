#include <vector>
#include <algorithm>
int hIndex(std::vector<int>& citations)
{
  std::sort(citations.begin(), citations.end());
  int left = 0;
  int right = citations.size();
  int mid;
  int ans;
  while (left <= right)
  {
    mid = left + (right - left) / 2;

    int ub = std::lower_bound(citations.begin(), citations.end(), mid) - citations.begin();
    if (citations.size() - ub >= mid)
    {
      ans = mid;
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return ans;
}
int main()
{
  std::vector<int> citations = { 3, 0, 6, 1, 5 };
  int ans = hIndex(citations);
  return 0;
}
