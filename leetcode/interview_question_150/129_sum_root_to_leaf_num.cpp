#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <string>
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

int sumNumbers(TreeNode* root)
{
  if (!root)
    return 0;
  std::stack<TreeNode*> s;
  s.push(root);
  std::vector<std::string> nums;
  std::map<TreeNode*, std::string> sum_map;
  sum_map[root] = std::to_string(root->val);

  while (!s.empty())
  {
    TreeNode* curr = s.top();
    s.pop();

    if (curr->left)
    {
      s.push(curr->left);
      sum_map[curr->left] = sum_map[curr] + std::to_string(curr->left->val);
    }
    if (curr->right)
    {
      s.push(curr->right);
      sum_map[curr->right] = sum_map[curr] + std::to_string(curr->right->val);
    }

    if (curr->left == nullptr && curr->right == nullptr)
    {
      // leaf node
      nums.push_back(sum_map[curr]);
    }
  }

  int total = 0;
  for (auto x : nums)
    total += std::stoi(x);

  return total;
}
int main()
{
  //   std::vector<int> nums = { 4, 9, 0, 5, 1 };
  std::vector<int> nums = { 1, 2 };
  TreeNode* root = buildTree(nums);
  int ans = sumNumbers(root);
  return 0;
}