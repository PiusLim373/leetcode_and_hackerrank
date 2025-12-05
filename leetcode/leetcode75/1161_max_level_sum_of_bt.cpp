#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(std::vector<int> input)
{
    TreeNode *root = new TreeNode(input[0]);
    std::queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (i < input.size())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (i < input.size() && input[i] != INT32_MAX)
        {
            curr->left = new TreeNode(input[i]);
            q.push(curr->left);
        }
        i++;
        if (i < input.size() && input[i] != INT32_MAX)
        {
            curr->right = new TreeNode(input[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int maxLevelSum(TreeNode *root)
{
    int max_sum = -INT32_MAX;
    int max_sum_level = -1;
    std::queue<TreeNode *> q;
    q.push(root);

    int level = 0;
    while (!q.empty())
    {
        int level_size = q.size();
        level++;
        int temp = 0;
        for (int i = 0; i < level_size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            temp += curr->val;

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        if (temp > max_sum)
        {
            max_sum = temp;
            max_sum_level = level;
        }
    }
    return max_sum_level;
}

int main()
{
    // std::vector<int> input = {1, 7, 0, 7, -8, INT32_MAX, INT32_MAX};
    std::vector<int> input = {989, INT32_MAX, 10250, 98693, -89388, INT32_MAX, INT32_MAX, INT32_MAX, -32127};
    TreeNode *root = buildTree(input);
    auto ans = maxLevelSum(root);
    return 0;
}