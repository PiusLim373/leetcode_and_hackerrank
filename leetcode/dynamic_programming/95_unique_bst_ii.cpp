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

std::vector<TreeNode *> generateTreeHelper(int left, int right)
{
    if (left > right)
        return {nullptr};
    if (left == right)
        return {new TreeNode(left)};

    std::vector<TreeNode *> res;
    for (int i = left; i <= right; i++)
    {
        std::vector<TreeNode *> left_subtree = generateTreeHelper(left, i - 1);
        for (auto x : left_subtree)
        {
            std::vector<TreeNode *> right_subtree = generateTreeHelper(i + 1, right);
            for (auto y : right_subtree)
            {
                TreeNode *root = new TreeNode(i, x, y);
                res.push_back(root);
            }
        }
    }
    return res;
}

std::vector<TreeNode *> generateTrees(int n)
{
    return generateTreeHelper(1, n);
}

int main()
{
    int n = 1;
    auto ans = generateTrees(n);
    return 0;
}