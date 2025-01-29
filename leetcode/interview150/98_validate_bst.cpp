#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
class TreeNode
{
public:
  TreeNode* left;
  TreeNode* right;
  int val;

  TreeNode() : val(0), left(nullptr), right(nullptr) {};
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

TreeNode* buildTree(std::vector<int>& nums)
{
  if (!nums.size())
    return new TreeNode(0);

  TreeNode* root = new TreeNode(nums[0]);
  std::queue<TreeNode*> q;
  int index = 1;
  q.push(root);
  while (index < nums.size())
  {
    TreeNode* curr = q.front();
    q.pop();

    if (index < nums.size())
    {
      if (nums[index] != -1)
      {
        curr->left = new TreeNode(nums[index]);
        q.push(curr->left);
      }
      index++;
    }

    if (index < nums.size())
    {
      if (nums[index] != -1)
      {
        curr->right = new TreeNode(nums[index]);
        q.push(curr->right);
      }
      index++;
    }
  }
  return root;
}

bool isValidBSTHelper(TreeNode* root, std::vector<int>& nums)
{
  if (!root)
    return true;
  if (!isValidBSTHelper(root->left, nums))
    return false;
  nums.push_back(root->val);
  if (nums.size() >= 2 && nums[nums.size() - 1] <= nums[nums.size() - 2])
    return false;
  return isValidBSTHelper(root->right, nums);
}

bool isValidBST(TreeNode* root)
{
  if (!root)
    return true;
  std::vector<int> nums;
  bool has_finished = false;
  return isValidBSTHelper(root, nums);
}

/*
void isValidBSTHelperNotOptimzed(TreeNode* root, std::vector<int>& nums, bool& has_finished, bool& ans)
{
  if (has_finished)
    return;
  if (root->left)
    isValidBSTHelper(root->left, nums, has_finished, ans);
  if (has_finished)
    return;
  nums.push_back(root->val);
  if (nums.size() >= 2)
  {
    if (nums[nums.size() - 1] < nums[nums.size() - 2])
    {
      ans = false;
      has_finished = true;
      return;
    }
  }
  if (root->right)
    isValidBSTHelper(root->right, nums, has_finished, ans);
  if (has_finished)
    return;
}
bool isValidBSTNotOptimized(TreeNode* root)
{
  if (!root)
    return true;
  std::vector<int> nums;
  bool has_finished = false;
  bool ans = true;
  isValidBSTHelper(root, nums, has_finished, ans);
  return ans;
}
*/
int main()
{
//   std::vector<int> nums = { 5, 1, 4, -1, -1, 3, 6 };
  std::vector<int> nums = { 2, 2, 2 };
  TreeNode* root = buildTree(nums);
  bool ans = isValidBST(root);
  return 0;
}