#include <queue>
#include <vector>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode *curr, std::vector<int> &ans)
{
    if (!curr)
        return;

    if (curr->left)
        dfs(curr->left, ans);
    ans.push_back(curr->val);
    if (curr->right)
        dfs(curr->right, ans);
}

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> ans = {};
    dfs(root, ans);
    return ans;
}

TreeNode *buildTree(std::vector<int> &nums)
{
    if (!nums.size())
        return nullptr;
    TreeNode *root = new TreeNode(nums[0]);

    std::queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nums.size())
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

int main()
{
    // std::vector<int> nums = {1, 2, 3, 4, 5, -999, 8, -999, -999, 6, 7, 9};
    std::vector<int> nums = {1};
    TreeNode *root = buildTree(nums);
    auto ans = inorderTraversal(root);
    return 0;
}