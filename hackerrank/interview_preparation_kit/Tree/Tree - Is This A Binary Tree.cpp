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
        right = NULL;
        left = NULL;
    }
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            root = new Node(data);
            return root;
        }
        else
        {
            if (data <= root->data)
            {
                Node *temp = insert(root->left, data);
                root->left = temp;
            }
            else if (data > root->data)
            {
                Node *temp = insert(root->right, data);
                root->right = temp;
            }
        }
    }
};

// void printInorder(Node *root)
// {
//     if (root == NULL)
//         return;
//     printInorder(root->left);
//     cout << root->data << endl;
//     printInorder(root->right);
// }

// bool isleftsmaller(Node *root, int value)
// {
//     if (root == NULL)
//         return true;
//     if (root->data <= value &&
//         isleftsmaller(root->left, value) &&
//         isleftsmaller(root->right, value))
//         return true;
//     else
//         return false;
// }

// bool isrightgreater(Node *root, int value)
// {
//     if (root == NULL)
//         return true;
//     if (root->data > value &&
//         isrightgreater(root->left, value) &&
//         isrightgreater(root->right, value))
//         return true;
//     else
//         return false;
// }

// bool checkBST(Node *root)
// {
//     if (root == NULL)
//         return true;
//     cout << root->data << endl;
//     if (isleftsmaller(root->left, root->data) &&
//         isrightgreater(root->right, root->data) &&
//         checkBST(root->left) &&
//         checkBST(root->right))
//         return true;
//     else
//         return false;
// }

bool isBST(Node *root, int min_val, int max_val)
{
    if (root == NULL)
        return true;
    if (
        root->data < max_val &&
        root->data > min_val &&
        isBST(root->left, min_val, root->data) &&
        isBST(root->right, root->data, max_val))
        return true;
    else
        return false;
}

bool checkBST(Node *root)
{
    if (isBST(root, INT_FAST16_MIN, INT_FAST16_MAX))
        return true;
    else
        return false;
}

int main()
{
    Node *sohai = new Node(5);
    sohai->insert(sohai, 3);
    sohai->insert(sohai, 2);
    sohai->insert(sohai, 7);
    sohai->insert(sohai, 8);
    sohai->insert(sohai, 6);
    sohai->insert(sohai, 4);
    // printInorder(sohai);
    if (checkBST(sohai))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    // cout << INT_FAST16_MIN << endl;
    // cout << INT_FAST16_MAX << endl;
}

// 4
// 2 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
// 2
// 2 3
// 4 5 6 7
// 8 9 10 11 12 13 14 15
// 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31