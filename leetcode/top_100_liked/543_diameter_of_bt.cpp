#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(std::vector<int> nums)
{
    if (!nums.size())
        return nullptr;
    TreeNode *root = new TreeNode(nums[0]);
    std::queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (i < nums.size() && !q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (i < nums.size() && nums[i] != -999)
        {
            curr->left = new TreeNode(nums[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nums.size() && nums[i] != -999)
        {
            curr->right = new TreeNode(nums[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int dfs(TreeNode *curr, int &diameter)
{
    if (!curr)
        return 0;
    int left_height = dfs(curr->left, diameter);
    int right_height = dfs(curr->right, diameter);

    diameter = std::max(diameter, left_height + right_height);
    return 1 + std::max(left_height, right_height);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;
    dfs(root, diameter);
    return diameter;
}

int main()
{
    std::vector<int> nums = {};
    TreeNode *root = buildTree(nums);
    auto ans = diameterOfBinaryTree(root);
    return 0;
}