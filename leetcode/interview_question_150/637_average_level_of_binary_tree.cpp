#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
class TreeNode
{
public:
  TreeNode* left;
  TreeNode* right;
  int val;

  TreeNode() : val(0), left(nullptr), right(nullptr) {};
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

TreeNode* buildTree(std::vector<int>& nums)
{
  if (!nums.size())
    return new TreeNode(0);

  TreeNode* root = new TreeNode(nums[0]);
  std::queue<TreeNode*> q;
  int index = 1;
  q.push(root);
  while (index < nums.size())
  {
    TreeNode* curr = q.front();
    q.pop();

    if (index < nums.size())
    {
      if (nums[index] != -1)
      {
        curr->left = new TreeNode(nums[index]);
        q.push(curr->left);
      }
      index++;
    }

    if (index < nums.size())
    {
      if (nums[index] != -1)
      {
        curr->right = new TreeNode(nums[index]);
        q.push(curr->right);
      }
      index++;
    }
  }
  return root;
}

std::vector<double> averageOfLevels(TreeNode* root)
{
  if (!root)
    return {};
  std::queue<TreeNode*> queue;
  queue.push(root);
  std::vector<double> ans;
  while (!queue.empty())
  {
    int level_size = queue.size();
    long long level_sum = 0;

    for (int i = 0; i < level_size; i++)
    {
      TreeNode* curr = queue.front();
      queue.pop();
      level_sum += curr->val;
      if (curr->left)
        queue.push(curr->left);
      if (curr->right)
        queue.push(curr->right);
    }
    ans.push_back(level_sum * 1.0 / level_size);
  }
  return ans;
}
std::vector<double> averageOfLevelsNotOptimzed(TreeNode* root)
{
  if (!root)
    return {};

  std::queue<TreeNode*> queue;
  queue.push(root);
  std::vector<double> ans = { root->val * 1.0 };
  std::map<TreeNode*, int> level_map;
  level_map[root] = 1;
  std::map<int, std::pair<int, double>> averager;
  int max_depth = 1;
  while (!queue.empty())
  {
    TreeNode* curr = queue.front();
    queue.pop();

    if (curr->left)
    {
      queue.push(curr->left);
      level_map[curr->left] = level_map[curr] + 1;
      int curr_level = level_map[curr->left];
      max_depth = std::max(curr_level, max_depth);
      if (averager.count(curr_level))
      {
        auto [num_of_nodes, average] = averager[curr_level];
        double new_ave = ((average * num_of_nodes) + curr->left->val) / (num_of_nodes + 1);
        averager[curr_level] = { num_of_nodes + 1, new_ave };
      }
      else
        averager[curr_level] = { 1, curr->left->val };
    }

    if (curr->right)
    {
      queue.push(curr->right);
      level_map[curr->right] = level_map[curr] + 1;
      int curr_level = level_map[curr->right];
      max_depth = std::max(curr_level, max_depth);
      if (averager.count(curr_level))
      {
        auto [num_of_nodes, average] = averager[curr_level];
        double new_ave = ((average * num_of_nodes) + curr->right->val) / (num_of_nodes + 1);
        averager[curr_level] = { num_of_nodes + 1, new_ave };
      }
      else
        averager[curr_level] = { 1, curr->right->val };
    }
  }

  for (int i = 2; i <= max_depth; i++)
  {
    ans.push_back(averager[i].second);
  }
  return ans;
}

int main()
{
  std::vector<int> nums = { 3, 9, 20, -1, -1, 15, 7 };
  TreeNode* root = buildTree(nums);
  std::vector<double> ans = averageOfLevels(root);
  return 0;
}