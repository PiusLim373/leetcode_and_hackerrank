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

void inOrderTransversal(TreeNode* root, std::vector<int>& nums, int& min_diff)
{
  if (root->left)
    inOrderTransversal(root->left, nums, min_diff);
  nums.push_back(root->val);
  if (nums.size() >= 2)
  {
    int diff = abs(nums[nums.size() - 1] - nums[nums.size() - 2]);
    if (diff < min_diff)
      min_diff = diff;
  }
  if (root->right)
    inOrderTransversal(root->right, nums, min_diff);
}

int getMinimumDifference(TreeNode* root)
{
  std::vector<int> nums;
  int min_diff = INT16_MAX;
  inOrderTransversal(root, nums, min_diff);
  return min_diff;
}

/*
    didnt work for case [236,104,701,null,227,null,911]
*/
int getMinimumDifference_not_working(TreeNode* root)
{
  std::queue<TreeNode*> q;
  q.push(root);
  int min_diff = INT16_MAX;

  while (!q.empty())
  {
    TreeNode* curr = q.front();
    q.pop();

    if (curr->left)
    {
      q.push(curr->left);
      int diff = abs(curr->val - curr->left->val);
      if (diff < min_diff)
        min_diff = diff;
    }

    if (curr->right)
    {
      q.push(curr->right);
      int diff = abs(curr->val - curr->right->val);
      if (diff < min_diff)
        min_diff = diff;
    }
  }
  return min_diff;
}

int main()
{
    std::vector<int> tree = { 4, 2, 6, 1, 3 };
//   std::vector<int> tree = { 236, 104, 701, -1, 227, -1, 911 };

  TreeNode* root = buildTree(tree);
  std::cout << getMinimumDifference(root);

  return 0;
}