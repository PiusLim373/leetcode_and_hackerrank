#include <queue>
#include <stack>
#include <vector>
#include <tuple>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(const std::vector<int> &tree)
{
    if (tree.empty() || tree[0] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(tree[0]);
    std::queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)tree.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        // Build left child
        if (i < (int)tree.size() && tree[i] != -1)
        {
            curr->left = new TreeNode(tree[i]);
            q.push(curr->left);
        }
        i++;

        // Build right child
        if (i < (int)tree.size() && tree[i] != -1)
        {
            curr->right = new TreeNode(tree[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int longestZigZag(TreeNode *root)
{
    int longest = 0;
    std::stack<std::tuple<TreeNode *, int, int>> s;
    // tuple of treenode, direction, count
    // direction 0: none, 1: left, 2: right
    s.push({root, 0, 0});
    while (!s.empty())
    {
        auto [curr_root, curr_direction, curr_count] = s.top();
        s.pop();
        longest = std::max(longest, curr_count);

        if (curr_root->left)
        {
            if (curr_direction == 2) // comes from right, can increase count
                s.push({curr_root->left, 1, curr_count + 1});
            else
                s.push({curr_root->left, 1, 1}); // reset scrore
        }
        if (curr_root->right)
        {
            if (curr_direction == 1) // comes from right, can increase count
                s.push({curr_root->right, 2, curr_count + 1});
            else
                s.push({curr_root->right, 2, 1}); // reset scrore
        }        
    }
    return longest;
}


// if (curr_direction == "")
        // {
        //     if (curr_root->left)
        //         s.push({curr_root->left, "left", 1});
        //     if (curr_root->right)
        //         s.push({curr_root->right, "right", 1});
        // }

        // else if (curr_direction == "left")
        // {
        //     if (curr_root->left)
        //         s.push({curr_root->left, "left", curr_count});
        //     if (curr_root->right)
        //         s.push({curr_root->right, "right", curr_count + 1});
        // }
        // else if (curr_direction == "right")
        // {
        //     if (curr_root->left)
        //         s.push({curr_root->left, "left", curr_count + 1});
        //     if (curr_root->right)
        //         s.push({curr_root->right, "right", curr_count});
        // }

int main()
{
    // std::vector<int> tree = {
    //     1, -1, 1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, -1, 1};

    std::vector<int> tree = {
        6, 9, 7, 3, -1, 2, 8, 5, 8, 9, 7, 3, 9, 9, 4, 2, 10, -1, 5, 4, 3, 10, 10, 9, 4, 1, 2, -1, -1, 6, 5, -1, -1, -1, -1, 9, -1, 9, 6, 5, -1, 5, -1, -1, 7, 7, 4, -1, 1, -1, -1, 3, 7, -1, 9, -1, -1, -1, -1, -1, -1, -1, -1, 9, 9, -1, -1, -1, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6, 8, 7, -1, -1, -1, 3, 10, -1, -1, -1, -1, -1, 1, -1, 1, 2};
    TreeNode *root = buildTree(tree);
    int ans = longestZigZag(root);
    return 0;
}
