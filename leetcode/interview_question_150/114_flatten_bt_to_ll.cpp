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

TreeNode* dfs(TreeNode* root)
{
  if (root == nullptr)
    return nullptr;
  TreeNode* left_tail = dfs(root->left);
  TreeNode* right_tail = dfs(root->right);

  if (root->left != nullptr)
  {
    left_tail->right = root->right;
    root->right = root->left;
    root->left = nullptr;
  }

  TreeNode* last;
  if (right_tail != nullptr)
    last = right_tail;
  else if (left_tail != nullptr)
    last = left_tail;
  else
    last = root;
  return last;
}

void flatten(TreeNode* root)
{
  dfs(root);
}
int main()
{
  std::vector<int> tree = { 1, 2, 5, 3, 4, -1, 6 };
  TreeNode* root = buildTree(tree);
  flatten(root);
  return 0;
}