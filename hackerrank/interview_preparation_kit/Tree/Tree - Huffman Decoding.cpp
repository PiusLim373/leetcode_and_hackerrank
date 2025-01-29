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
;

void decode_huff(Node *root, string s)
{
    Node *curr;
    curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            curr = curr->right;
        else
            curr = curr->left;
        if (curr->data)
        {
            cout << curr->data;
            curr = root;
        }
    }
}

int main()
{
    Node *sohai = new Node(4);
    sohai->insert(sohai, 1);
    sohai->insert(sohai, 2);
    sohai->insert(sohai, 3);
    sohai->insert(sohai, 5);

    string s = "1001011";
    decode_huff(sohai, s);
}