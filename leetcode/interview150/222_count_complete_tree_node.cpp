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
      curr->left = new TreeNode(nums[index]);
      q.push(curr->left);
      index++;
    }

    if (index < nums.size())
    {
      curr->right = new TreeNode(nums[index]);
      q.push(curr->right);
      index++;
    }
  }
  return root;
}

void countNodesHelper(TreeNode* root, int& count)
{
  if (!root)
    return;
  if (root->left)
    countNodesHelper(root->left, count);
  count++;
  if (root->right)
    countNodesHelper(root->right, count);
}

int countNodes(TreeNode* root)
{
  int count = 0;
  countNodesHelper(root, count);
  return count;
}

int main()
{
  std::vector<int> nums = { 1, 2, 3, 4, 5};
  TreeNode* root = buildTree(nums);
  bool ans = countNodes(root);
  return 0;
}