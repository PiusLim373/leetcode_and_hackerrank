#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

TreeNode* invertTree(TreeNode* root)
{
  if (root == nullptr)
    return root;

  TreeNode* temp = root->left;
  root->left = root->right;
  root->right = temp;
  if (root->left != nullptr)
    invertTree(root->left);

  if (root->right != nullptr)
    invertTree(root->right);
  return root;
}

int main()
{
  std::vector<int> tree = { 4, 2, 7, 1, 3, 6, 9 };
  TreeNode* root = buildTree(tree);
  invertTree(root);
  return 0;
}