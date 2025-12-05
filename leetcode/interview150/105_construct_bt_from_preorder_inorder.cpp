#include <vector>
#include <unordered_map>
class TreeNode
{
public:
  TreeNode *left;
  TreeNode *right;
  int val;

  TreeNode() : val(0), left(nullptr), right(nullptr) {};
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

TreeNode *recvBuild(int pre_l, int pre_r, int in_l, int in_r, std::vector<int> &preorder, std::vector<int> &inorder, std::unordered_map<int, int> &val_index_map)
{
  if (pre_l > pre_r)
    return nullptr;
  TreeNode *root = new TreeNode(preorder[pre_l]);
  int root_index_in_inorder = val_index_map[preorder[pre_l]];
  int left_tree_size = root_index_in_inorder - in_l;

  root->left = recvBuild(pre_l + 1,
                         pre_l + left_tree_size,
                         in_l,
                         root_index_in_inorder - 1,
                         preorder,
                         inorder,
                         val_index_map);
  root->right = recvBuild(pre_l + 1 + left_tree_size,
                          pre_r,
                          root_index_in_inorder + 1,
                          in_r,
                          preorder,
                          inorder,
                          val_index_map);
  return root;
}

TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
  std::unordered_map<int, int> val_index_map;
  for (int i = 0; i < inorder.size(); i++)
    val_index_map[inorder[i]] = i;

  TreeNode *root = new TreeNode();
  root = recvBuild(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder, val_index_map);

  return root;
}

int main()
{
  // std::vector<int> preorder = {3, 9, 20, 15, 7};
  // std::vector<int> inorder = {9, 3, 15, 20, 7};

  // std::vector<int> preorder = {1, 2, 4, 7, 5, 3, 6};
  // std::vector<int> inorder = {7, 4, 2, 5, 1, 3, 6};

  /*
                  1
               /     \
             2         3
           /   \        \
         4      5        6
       /
      7

  */

  std::vector<int> preorder = {1};
  std::vector<int> inorder = {1};
  TreeNode *root = buildTree(preorder, inorder);
  return 0;
}