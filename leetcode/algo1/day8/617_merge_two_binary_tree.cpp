#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    // queue<TreeNode *> node_queue1;
    // queue<TreeNode *> node_queue2;
    // node_queue1.push(root1);
    // node_queue2.push(root2);

    // TreeNode *current3 = new TreeNode();
    // TreeNode *current1, *current2;
    // while (!node_queue1.empty() and !node_queue2.empty())
    // {
    //     if (!node_queue1.empty())
    //     {
    //         current1 = node_queue1.front();
    //         node_queue1.pop();
    //     }
    //     if (!node_queue2.empty())
    //     {
    //         current2 = node_queue2.front();
    //         node_queue2.pop();
    //     }
    //     if (current1 != nullptr and current2 != nullptr)
    //         current3->val = current2->val + current1->val;
    //     else if (current1 == nullptr)
    //         current3->val = current2->val;
    //     else if (current2 == nullptr)
    //         current3->val = current1->val;
    //     current3 = current3->left;
    // }

    if (root1 == nullptr)
        return root2;
    if (root2 == nullptr)
        return root1;
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
}