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

bool hasPathSum(TreeNode* root, int targetSum)
{
  if (!root)
    return false;

  targetSum -= root->val;
  if (!root->left && !root->right)
    return targetSum == 0;
  return (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum));
}

int main()
{
  std::vector<int> tree = { 5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1 };
  int target = 22;
  TreeNode* root = buildTree(tree);
  std::cout << hasPathSum(root, target);

  return 0;
}