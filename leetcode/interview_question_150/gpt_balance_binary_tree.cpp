#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr)
  {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr)
  {
  }
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
  {
  }
};

TreeNode* buildTree(std::vector<int> nums)
{
  TreeNode* root = new TreeNode(nums[0]);
  std::queue<TreeNode*> q;
  q.push(root);
  int i = 1;
  while (i < nums.size())
  {
    TreeNode* curr = q.front();
    q.pop();
    if (i < nums.size() && nums[i] != -1)
    {
      curr->left = new TreeNode(nums[i]);
      q.push(curr->left);
    }
    i++;

    if (i < nums.size() && nums[i] != -1)
    {
      curr->right = new TreeNode(nums[i]);
      q.push(curr->right);
    }
    i++;
  }
  return root;
}
int depth(TreeNode* root)
{
  if (root == nullptr)
    return 0;
  int left_depth = depth(root->left);
  if (left_depth == -1)
    return -1;
  int right_depth = depth(root->right);
  if (right_depth == -1)
    return -1;

  if (abs(left_depth - right_depth) > 1)
    return -1;
  return 1 + std::max(left_depth, right_depth);
}
bool isBalanced(TreeNode* root)
{
  return depth(root) != -1;
}

void inOrderTranversal(TreeNode* root, std::vector<int>& nums)
{
  if (root == nullptr)
    return;

  inOrderTranversal(root->left, nums);
  nums.push_back(root->val);
  inOrderTranversal(root->right, nums);
}

TreeNode* buildBalancedTree(std::vector<int> nums, int start, int end)
{
  if (start > end)
    return nullptr;

  int mid = start + (end - start) / 2;
  TreeNode* root = new TreeNode(nums[mid]);
  root->left = buildBalancedTree(nums, start, mid - 1);
  root->right = buildBalancedTree(nums, mid + 1, end);
  return root;
}

int main()
{
  // std::vector<int> tree = { 1, 2, 3, 4, -1, -1, -1, 5 };
  // TreeNode* root = buildTree(tree);
  // TreeNode* balanced_root;
  // std::vector<int> nums;
  // bool is_balanced = isBalanced(root);
  // if (!is_balanced)
  // {
  //   inOrderTranversal(root, nums);
  //   std::sort(nums.begin(), nums.end());
  //   balanced_root = buildBalancedTree(nums, 0, nums.size() - 1);
  // }

  std::vector<int> nums{ -10, -3, 0, 5, 9 };
  TreeNode* balanced_root = buildBalancedTree(nums, 0, nums.size() - 1);
  return 0;
}