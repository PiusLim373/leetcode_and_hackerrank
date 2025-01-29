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

int maxDepth(TreeNode* root)
{
  int depth = 1;
  std::map<TreeNode*, int> depth_counter;
  std::queue<TreeNode*> q;
  depth_counter[root] = 1;
  q.push(root);

  while (!q.empty())
  {
    int size = q.size();
    TreeNode* curr = q.front();
    q.pop();

    if (curr->left != nullptr)
    {
      q.push(curr->left);
      depth_counter[curr->left] = depth_counter[curr] + 1;
      if (depth_counter[curr->left] > depth)
        depth = depth_counter[curr->left];
    }
    if (curr->right != nullptr)
    {
      q.push(curr->right);
      depth_counter[curr->right] = depth_counter[curr] + 1;
      if (depth_counter[curr->right] > depth)
        depth = depth_counter[curr->right];
    }
  }

  return depth;
}

int main()
{
  std::vector<int> tree = { 3, 9, 20, -1, -1, 15, 7 };
  TreeNode* root = buildTree(tree);
  std::cout << maxDepth(root);
  return 0;
}