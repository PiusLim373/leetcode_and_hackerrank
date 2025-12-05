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

TreeNode *recvBuild(std::vector<int> &inorder, std::vector<int> &postorder, std::unordered_map<int, int> &val_index_map,
                    int in_l, int in_r, int post_l, int post_r)
{
  if (in_l > in_r)
    return nullptr;

  TreeNode *root = new TreeNode(postorder[post_r]);
  int root_index_inorder = val_index_map[postorder[post_r]];
  int left_size = root_index_inorder - in_l;

  root->left = recvBuild(inorder, postorder, val_index_map, in_l, root_index_inorder - 1, post_l, post_l + left_size - 1);
  root->right = recvBuild(inorder, postorder, val_index_map, root_index_inorder + 1, in_r, post_l + left_size, post_r - 1);
  return root;
}

TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
{
  std::unordered_map<int, int> val_index_map;
  for (int i = 0; i < inorder.size(); i++)
    val_index_map[inorder[i]] = i;

  TreeNode *root = recvBuild(inorder, postorder, val_index_map, 0, inorder.size() - 1, 0, postorder.size() - 1);
  return root;
}

int main()
{
  // std::vector<int> inorder = {9, 3, 15, 20, 7};
  // std::vector<int> postorder = {9, 15, 7, 20, 3};

  std::vector<int> inorder = {7, 4, 2, 5, 1, 3, 6};
  std::vector<int> postorder = {7, 4, 5, 2, 6, 3, 1};

  /*
                  1
               /     \
             2         3
           /   \        \
         4      5        6
       /
      7

  */

  // std::vector<int> preorder = {1};
  // std::vector<int> inorder = {1};
  TreeNode *root = buildTree(inorder, postorder);
  return 0;
}