#include <vector>
#include <queue>
#include <map>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void recv(TreeNode *root, std::map<TreeNode *, std::pair<int, int>> &dp)
{
    // base case, leaf node, rob = curr val,
    if (!root->left && !root->right)
    {
        dp[root] = {root->val, 0};
        return;
    }

    if (root->left)
        recv(root->left, dp);
    if (root->right)
        recv(root->right, dp);

    // rob = val + norob(left) + norob(right)
    // no rob = max(rob left, no rob left) + max (rob right, no rob right)
    int rob = root->val + dp[root->left].second + dp[root->right].second;
    int no_rob = std::max(dp[root->left].first, dp[root->left].second) + std::max(dp[root->right].first, dp[root->right].second);
    dp[root] = {rob, no_rob};
}

int rob(TreeNode *root)
{
    std::map<TreeNode *, std::pair<int, int>> dp;
    recv(root, dp);
    return std::max(dp[root].first, dp[root].second);
}

TreeNode *buildTree(std::vector<int> nums)
{
    TreeNode *root = new TreeNode(nums[0]);
    std::queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (!q.empty())
    {
        auto curr = q.front();
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

int main()
{
    // std::vector<int> nums = {3, 2, 3, -1, 3, -1, 1};
    std::vector<int> nums = {3, 4, 5, 1, 3, -1, 1};

    TreeNode *root = buildTree(nums);
    auto ans = rob(root);
    return 0;
}