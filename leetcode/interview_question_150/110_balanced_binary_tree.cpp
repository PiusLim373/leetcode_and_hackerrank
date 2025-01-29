#include <vector>
#include <queue>
#include <math.h>

class TreeNode
{
public:
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
  TreeNode() : val(0), left(nullptr), right(nullptr) {};
};

TreeNode* buildTree(std::vector<int> nums)
{
  TreeNode* root = new TreeNode(nums[0]);
  std::queue<TreeNode*> queue;
  queue.push(root);
  int index = 1;

  while (!queue.empty() && index < nums.size())
  {
    auto curr = queue.front();
    queue.pop();

    if (index < nums.size() && nums[index] != -1)
    {
      curr->left = new TreeNode(nums[index]);
      queue.push(curr->left);
      index++;
    }
    else
      index++;

    if (index < nums.size() && nums[index] != -1)
    {
      curr->right = new TreeNode(nums[index]);
      queue.push(curr->right);
      index++;
    }
    else
      index++;
  }

  return root;
}

std::pair<bool, int> isBalancedHelper(TreeNode* root)
{
  if (!root)
    return { true, 0 };

  auto [left_result, left_level] = isBalancedHelper(root->left);
  auto [right_result, right_level] = isBalancedHelper(root->right);
  if (left_result && right_result && std::abs(left_level - right_level) <= 1)
    return { true, std::max(left_level + 1, right_level + 1) };
  else
    return { false, std::max(left_level + 1, right_level + 1) };
}

bool isBalanced(TreeNode* root)
{
  return isBalancedHelper(root).first;
}

void dfs(TreeNode* root, int& max_depth, int& min_depth, int layer)
{
  if (!root)
    return;
  if (root->left)
    dfs(root->left, max_depth, min_depth, layer + 1);
  if (root->right)
    dfs(root->right, max_depth, min_depth, layer + 1);

  if (!root->left && !root->right)
  {
    // encounter a leaf node, record down layer
    max_depth = std::max(max_depth, layer);
    min_depth = std::min(min_depth, layer);
  }
}

bool isBalancedNotCorrect(TreeNode* root)
{
  if (!root)
    return true;
  int min_depth = __INT_MAX__;
  int max_depth = -__INT_MAX__;

  dfs(root, max_depth, min_depth, 0);
  if (min_depth == max_depth)
  {
    if (min_depth > 1)
      return false;
    return true;
  }
  if (std::abs(max_depth - min_depth) > 1)
    return false;
  return true;
}

int main()
{
  // std::vector<int> nums = { 3, 9, 20, -1, -1, 15, 7 };
  std::vector<int> nums = { 1, 2, 2, 3, 3, -1, -1, 4, 4 };

  // std::vector<int> nums = { 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, -1, -1, 5, 5 };

  TreeNode* root = buildTree(nums);
  auto ans = isBalanced(root);
  return 0;
}