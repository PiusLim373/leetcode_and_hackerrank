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

bool isSymmetricHelper(TreeNode* left, TreeNode* right)
{
  std::stack<std::pair<TreeNode*, TreeNode*>> s;
  s.push({ left, right });
  while (!s.empty())
  {
    auto [l, r] = s.top();
    s.pop();
    if (l == nullptr && r == nullptr)
      continue;
    if (l == nullptr || r == nullptr || l->val != r->val)
      return false;
    s.push({ l->left, r->right });
    s.push({ l->right, r->left });
  }
  return true;
}

bool isSymmetric(TreeNode* root)
{
  if (!root)
    return true;
  return isSymmetricHelper(root->left, root->right);
}

int main()
{
  std::vector<int> nums = { 1, 2, 2, 3, 4, 4, 3, 5 };
  TreeNode* root = buildTree(nums);
  bool ans = isSymmetric(root);
  return 0;
}