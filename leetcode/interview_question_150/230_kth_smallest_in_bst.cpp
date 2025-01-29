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

void inOrderTransversal(TreeNode* root, std::vector<int>& nums, int k, bool& has_finished)
{
  if (has_finished)
    return;
  if (root->left)
    inOrderTransversal(root->left, nums, k, has_finished);
  if (has_finished)
    return;
  nums.push_back(root->val);
  if (nums.size() == k)
  {
    has_finished = true;
    return;
  }
  if (root->right)
    inOrderTransversal(root->right, nums, k, has_finished);
}

int kthSmallest(TreeNode* root, int k)
{
  std::vector<int> nums;
  bool has_finished = false;
  inOrderTransversal(root, nums, k, has_finished);
  return nums[nums.size() - 1];
}

int main()
{
  std::vector<int> tree = { 5, 3, 6, 2, 4, -1, -1, 1 };

  TreeNode* root = buildTree(tree);
  int k = 3;
  std::cout << kthSmallest(root, k);

  return 0;
}