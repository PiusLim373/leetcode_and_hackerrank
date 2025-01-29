#include <vector>
#include <iostream>
#include <queue>
#include <map>
std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k)
{
  std::vector<std::vector<int>> return_data;
  std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>,
                      std::greater<>>
      pq;
  std::map<std::pair<int, int>, bool> visited;

  // put in the smallest
  pq.push({ nums1[0] + nums2[0], { 0, 0 } });
  visited[{ 0, 0 }] = true;
  while (!pq.empty())
  {
    std::vector<int> temp;
    auto [sum, indexes] = pq.top();
    pq.pop();
    temp = { nums1[indexes.first], nums2[indexes.second] };
    return_data.push_back(temp);

    if (return_data.size() >= k)
      return return_data;

    int new_i = indexes.first + 1;
    int new_j = indexes.second + 1;
    if (new_i < nums1.size() && visited.find({ new_i, indexes.second }) == visited.end())
    {
      pq.push({ nums1[new_i] + nums2[indexes.second], { new_i, indexes.second } });
      visited[{ new_i, indexes.second }] = true;
    }
    if (new_j < nums2.size() && visited.find({ indexes.first, new_j }) == visited.end())
    {
      pq.push({ nums1[indexes.first] + nums2[new_j], { indexes.first, new_j } });
      visited[{ indexes.first, new_j }] = true;
    }
  }
  return return_data;
}
std::vector<std::vector<int>> kSmallestPairs_notworking(std::vector<int>& nums1, std::vector<int>& nums2, int k)
{
  std::vector<std::vector<int>> return_data;
  int nums1_ptr = 0;
  int nums2_ptr = 0;

  int smallest_sum = nums1[0] + nums2[0];
  return_data.push_back({ nums1[0], nums2[0] });
  for (int count = 1; count < k; count++)
  {
    std::vector<int> temp;
    if (nums1[nums1_ptr + 1] > nums2[nums2_ptr + 1])
    {
      nums2_ptr++;
    }
    else
      nums1_ptr++;

    return_data.push_back({ nums1[nums1_ptr], nums2[nums2_ptr] });
  }

  return return_data;
}
int main()
{
  std::vector<int> nums1 = { 1, 2, 4, 5, 6 };
  std::vector<int> nums2 = { 3, 5, 7, 9 };
  int k = 3;
  std::vector<std::vector<int>> data = kSmallestPairs(nums1, nums2, k);
  for (auto x : data)
  {
    for (auto y : x)
    {
      std::cout << y << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}