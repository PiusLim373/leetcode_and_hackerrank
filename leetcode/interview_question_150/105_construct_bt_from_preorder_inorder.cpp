#include <vector>
#include <algorithm>
class TreeNode
{
public:
  TreeNode* left;
  TreeNode* right;
  int val;

  TreeNode() : val(0), left(nullptr), right(nullptr) {};
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
  if (!preorder.size())
    return nullptr;
  TreeNode* root = new TreeNode(preorder[0]);
  auto it = std::find(inorder.begin(), inorder.end(), preorder[0]);
  int index = std::distance(inorder.begin(), it);

  std::vector<int> preorder_subarray(preorder.begin() + 1, preorder.end());
  std::vector<int> inorder_left(inorder.begin(), inorder.begin() + index);
  std::vector<int> inorder_right(inorder.begin() + index, inorder.end());
  root->left = buildTree(preorder_subarray, )
}

int main()
{
  // std::vector<int> nums = { 3, 9, 20, -1, -1, 15, 7 };
  std::vector<int> preorder = { 3, 9, 20, 15, 7 };
  std::vector<int> inorder = { 9, 3, 15, 20, 7 };

  TreeNode* root = buildTree(preorder, inorder);
  return 0;
}