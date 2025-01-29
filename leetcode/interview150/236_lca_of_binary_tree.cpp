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

TreeNode* buildTree(std::vector<int> nums, TreeNode*& p, TreeNode*& q, int p_num, int q_num)
{
  TreeNode* root = new TreeNode(nums[0]);
  std::queue<TreeNode*> qu;
  qu.push(root);
  int i = 1;
  while (i < nums.size())
  {
    TreeNode* curr = qu.front();
    qu.pop();
    if (i < nums.size() && nums[i] != -1)
    {
      curr->left = new TreeNode(nums[i]);
      if (nums[i] == q_num)
        q = curr->left;
      if (nums[i] == p_num)
        p = curr->left;
      qu.push(curr->left);
    }
    i++;

    if (i < nums.size() && nums[i] != -1)
    {
      curr->right = new TreeNode(nums[i]);
      if (nums[i] == q_num)
        q = curr->right;
      if (nums[i] == p_num)
        p = curr->right;
      qu.push(curr->right);
    }
    i++;
  }
  return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
  if (!root)
    return nullptr;

  if (root == p || root == q)
    return root;

  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);

  if (left && right)
    return root;
  else
  {
    if (left)
      return left;
    else
      return right;
  }
}

int main()
{
  std::vector<int> tree = { 3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4 };
  int p_num = 5;
  int q_num = 1;
  TreeNode* p;
  TreeNode* q;
  TreeNode* root = buildTree(tree, p, q, p_num, q_num);
  TreeNode* ans = lowestCommonAncestor(root, p, q);

  return 0;
}