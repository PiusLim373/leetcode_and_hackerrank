#include <iostream>
#include <queue>
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
};
// correct but i cant understand
Node *connect(Node *root)
{
    if (root == nullptr)
        return nullptr;
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = nullptr;
        Node *next = nullptr;
        int counter = q.size();
        while (counter--)
        {
            if (curr == nullptr)
            {
                curr = q.front();
                q.pop();
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
            }
            else if (next == nullptr)
            {
                next = q.front();
                q.pop();
                curr->next = next;
                if (next->left != nullptr)
                    q.push(next->left);
                if (next->right != nullptr)
                    q.push(next->right);
            }
            else
            {
                curr = q.front();
                q.pop();
                next->next = curr;
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
                next = curr;
            }
        }
    }
    return root;
}
Node *connect2(Node *root)
{
    if (root == nullptr)
        return nullptr;
    Node *head = root;
    while (head != nullptr)
    {
        Node *dummy = new Node;
        Node *temp = dummy;

        while (head != nullptr)
        {
            if (head->left != nullptr)
            {
                temp->next = head->left;
                temp = temp->next;
            }
            if (head->right != nullptr)
            {
                temp->next = head->right;
                temp = temp->next;
            }
            if (head->next)
            {
                try
                {
                    std::cout << head->next->val << std::endl;
                }
                catch (...)
                {
                    std::cout << "rrror";
                }
            }
            head = head->next;
        }
        head = dummy->next;
    }
    return root;
}
// Node *connect_failure(Node *root)
// {
//     if (root == nullptr)
//         return root;
//     if (root->left != nullptr)
//     {
//         if (root->right == nullptr)
//         {
//             if (root->next != nullptr)
//             {
//                 if (root->next->left != nullptr)
//                     root->left->next = root->next->left;
//                 else if ((root->next->right != nullptr))
//                     root->left->next = root->next->right;
//                 else
//                 {
//                     cout << "here" << endl;
//                     root->left->next = nullptr;
//                 }
//             }
//         }
//         else
//             root->left->next = root->right;
//     }

//     if (root->next != nullptr && root->right != nullptr)
//     {
//         if (root->next->left != nullptr)
//             root->right->next = root->next->left;
//         else if ((root->next->right != nullptr))
//             root->right->next = root->next->right;
//         else
//         {
//             cout << "here" << endl;
//             root->right->next = nullptr;
//         }
//     }
//     connect(root->left);
//     connect(root->right);
//     return root;
// }