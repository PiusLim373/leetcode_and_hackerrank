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

bool isSameTree(TreeNode* p, TreeNode* q)
{
  if (p != nullptr && q != nullptr)
  {
    if (p->val == q->val)
      return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    else
      return false;
  }
  else if (p == nullptr && q == nullptr)
    return true;
  else
    return false;
}

int main()
{
  std::vector<int> tree1 = { 1, 2, 3 };
  std::vector<int> tree2 = { 1, 2, 3 };
  TreeNode* p = buildTree(tree1);
  TreeNode* q = buildTree(tree2);
  std::cout << isSameTree(p, q) << std::endl;
  return 0;
}