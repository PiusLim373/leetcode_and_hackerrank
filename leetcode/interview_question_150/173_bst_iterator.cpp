#include <vector>
#include <iostream>
#include <queue>
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

class BSTIterator
{
private:
  std::vector<int> nums = { -1 };
  int index = 0;

public:
  BSTIterator(TreeNode* root)
  {
    _inorder_trans(root, nums);
  }
  int next()
  {
    index++;
    return nums[index];
  }
  bool hasNext()
  {
    if (index < nums.size() - 1)
      return true;
    return false;
  }

  void _inorder_trans(TreeNode* root, std::vector<int>& nums)
  {
    if (!root)
      return;
    if (root->left)
      _inorder_trans(root->left, nums);
    nums.push_back(root->val);
    if (root->right)
      _inorder_trans(root->right, nums);
  }
};
int main()
{
  std::vector<int> nums = { 7, 3, 15, -1, -1, 9, 20 };
  TreeNode* root = buildTree(nums);

  BSTIterator bSTIterator(root);
  std::cout << bSTIterator.next() << std::endl;     // return 3
  std::cout << bSTIterator.next() << std::endl;     // return 7
  std::cout << bSTIterator.hasNext() << std::endl;  // return True
  std::cout << bSTIterator.next() << std::endl;     // return 9
  std::cout << bSTIterator.hasNext() << std::endl;  // return True
  std::cout << bSTIterator.next() << std::endl;     // return 15
  std::cout << bSTIterator.hasNext() << std::endl;  // return True
  std::cout << bSTIterator.next() << std::endl;     // return 20
  std::cout << bSTIterator.hasNext() << std::endl;  // return False
  return 0;
}