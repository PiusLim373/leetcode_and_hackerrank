#include <vector>
#include <queue>
class TreeNode
{
public:
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
  TreeNode() : val(0), left(nullptr), right(nullptr) {};
};

TreeNode* buildTree(std::vector<int> nums)
{
  TreeNode* root = new TreeNode(nums[0]);
  std::queue<TreeNode*> queue;
  queue.push(root);
  int index = 1;

  while (!queue.empty() && index < nums.size())
  {
    auto curr = queue.front();
    queue.pop();

    if (index < nums.size() && nums[index] != -999)
    {
      curr->left = new TreeNode(nums[index]);
      queue.push(curr->left);
      index++;
    }
    else
      index++;

    if (index < nums.size() && nums[index] != -999)
    {
      curr->right = new TreeNode(nums[index]);
      queue.push(curr->right);
      index++;
    }
    else
      index++;
  }

  return root;
}

int maxPathSumHelper(TreeNode* root, int& ans)
{
  if (!root)
    return 0;
  int left = maxPathSumHelper(root->left, ans);
  int right = maxPathSumHelper(root->right, ans);
  left = std::max(left, 0);
  right = std::max(right, 0);

  ans = std::max(ans, root->val + left + right);
  return (root->val + std::max(left, right));
}

int maxPathSum(TreeNode* root)
{
  int ans = root->val;
  maxPathSumHelper(root, ans);
  return ans;
}

void inorderTrans(TreeNode* root, std::vector<int>& val)
{
  if (!root)
    return;
  if (root->left)
    inorderTrans(root->left, val);
  val.push_back(root->val);
  if (root->right)
    inorderTrans(root->right, val);
}

int maxPathSumNotCorect(TreeNode* root)
{
  // inorder trans get the full array first
  std::vector<int> val;
  inorderTrans(root, val);
  if (val.size() == 1)
    return val[0];
  int max_sum = val[0];
  int curr = 0;
  for (auto x : val)
  {
    curr += x;
    max_sum = std::max(curr, max_sum);
    if (curr < 0)
      curr = 0;
  }
  return max_sum;
}

int main()
{
  std::vector<int> nums = { 1, -2, -3, 1, 3, -2, -999, -1 };
  TreeNode* root = buildTree(nums);
  int ans = maxPathSum(root);
  return 0;
}