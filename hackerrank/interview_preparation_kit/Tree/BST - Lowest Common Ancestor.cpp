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
    bool check_split(int root_data, int v1, int v2)
    {
        if (v1 == root_data || v2 == root_data)
            return true;
        else if (min(v1, v2) < root_data && max(v1, v2) > root_data)
            return true;
        return false;
    }

    Node *lca(Node *root, int v1, int v2)
    {
        // if (root == NULL) return root;
        if (check_split(root->data, v1, v2))
            return root;
        else
        {
            if (max(v1, v2) < root->data)
            {
                //travel left
                return lca(root->left, v1, v2);
            }
            else
                return lca(root->right, v1, v2);
        }
    }

}; //End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    int v1, v2;
    std::cin >> v1 >> v2;

    Node *ans = myTree.lca(root, v1, v2);

    std::cout << ans->data;

    return 0;
}
