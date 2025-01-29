#include <iostream>
#include <vector>

// struct TreeNode
// {
//   int val;
//   TreeNode* left;
//   TreeNode* right;
//   TreeNode() : val(0), left(nullptr), right(nullptr)
//   {
//   }
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr)
//   {
//   }
//   TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
//   {
//   }
// };

struct TreeNode
{
  // public:
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr)
  {
  }
};

TreeNode* buildTree(std::vector<int> nums, int start, int end)
{
  if (start > end)
    return nullptr;
  int mid = start + (end - start) / 2;
  TreeNode* root = new TreeNode(nums[mid]);
  root->left = buildTree(nums, start, mid - 1);
  root->right = buildTree(nums, mid + 1, end);
  return root;
}

TreeNode* sortedArrayToBST(std::vector<int> nums)
{
    if (!nums.size())
        return nullptr;
    TreeNode* root = buildTree(nums, 0, nums.size() - 1);
    return root;
}

int main()
{
  std::vector<int> nums = { -10, -3, 0, 5, 9, 10 };
  TreeNode* root = sortedArrayToBST(nums);
//   TreeNode* root = buildBalancedTree(nums, 0, nums.size() - 1);
  return 0;
}
