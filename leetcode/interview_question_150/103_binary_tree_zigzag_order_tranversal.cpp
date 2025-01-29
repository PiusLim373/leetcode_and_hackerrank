#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
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
std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
{
  if (!root)
    return {};
  std::queue<TreeNode*> queue;
  queue.push(root);
  std::vector<std::vector<int>> ans;
  bool start_left = true;
  while (!queue.empty())
  {
    int level_size = queue.size();
    std::vector<int> temp;
    for (int i = 0; i < level_size; i++)
    {
      TreeNode* curr = queue.front();
      queue.pop();
      temp.push_back(curr->val);

      if (curr->left)
        queue.push(curr->left);
      if (curr->right)
        queue.push(curr->right);
    }
    if (!start_left)
      std::reverse(temp.begin(), temp.end());
    start_left = !start_left;
    ans.push_back(temp);
  }
  return ans;
}
int main()
{
  // std::vector<int> nums = { 3, 9, 20, -1, -1, 15, 7 };
  std::vector<int> nums = { 1, 2, 3, 4, -1, -1, 5 };

  TreeNode* root = buildTree(nums);
  auto ans = zigzagLevelOrder(root);
  return 0;
}