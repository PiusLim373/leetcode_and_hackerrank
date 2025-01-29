#include <vector>
#include <iostream>
#include <queue>
int findKthLargest(std::vector<int>& nums, int k)
{
  std::priority_queue<int, std::vector<int>, std::greater<>> pq;
  for (auto x : nums)
  {
    pq.push(x);
    if (pq.size() > k)
      pq.pop();
  }
  return pq.top();
}

int main()
{
  std::vector<int> nums = { 1 };
  int k = 1;
  std::cout << findKthLargest(nums, k);
  return 0;
}