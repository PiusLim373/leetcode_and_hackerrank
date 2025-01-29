#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }
    /*The tree node has data, left child and right child
    class Node {
        int data;
        Node* left;
        Node* right;
    };

    */
    int height(Node *root)
    {
        // Write your code here.
        int left_h = 0;
        int right_h = 0;
        if (root->left != NULL)
            left_h += 1 + height(root->left);
        if (root->right != NULL)
            right_h += 1 + height(root->right);
        vector<int> compare = {left_h, right_h};
        return *max_element(compare.begin(), compare.end());
    }

}; // End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    vector<int> data = {3, 5, 2, 1, 4, 6, 7};
    for (auto x : data)
        root = myTree.insert(root, x);

    int height = myTree.height(root);
    std::cout << height;

    return 0;
}
