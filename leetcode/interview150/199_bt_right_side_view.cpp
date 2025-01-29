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
std::vector<int> rightSideView(TreeNode* root)
{
  if (root == nullptr)
    return {};
  std::vector<int> views = { root->val };
  std::queue<TreeNode*> q;
  q.push(root);
  int depth = 1;
  std::map<TreeNode*, int> depth_map;
  depth_map[root] = 1;

  while (!q.empty())
  {
    TreeNode* curr = q.front();
    q.pop();

    if (curr->right != nullptr)
    {
      q.push(curr->right);
      int new_depth = depth_map[curr] + 1;
      depth_map[curr->right] = new_depth;
      if (new_depth > depth)
      {
        views.push_back(curr->right->val);
        depth = new_depth;
      }
    }
    if (curr->left != nullptr)
    {
      q.push(curr->left);
      int new_depth = depth_map[curr] + 1;
      depth_map[curr->left] = new_depth;
      if (new_depth > depth)
      {
        views.push_back(curr->left->val);
        depth = new_depth;
      }
    }
  }
  return views;
}
int main()
{
  std::vector<int> tree = { 1, 2, 3, -1, 5, -1, 4 };
  TreeNode* root = buildTree(tree);
  std::vector<int> views = rightSideView(root);
  return 0;
}