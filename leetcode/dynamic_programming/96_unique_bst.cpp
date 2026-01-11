#include <vector>
int numTrees(int n)
{
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        /*
            tree[4] =   tree[0] * tree[3] +
                        tree[1] * tree[2] +
                        tree[2] * tree[1] +
                        tree[3] * tree[0]

            tree[2] = tree[0] * tree[1] + tree[1] * tree[0]
        */
        int total_tree = 0;
        for(int left_tree = 0; left_tree < i; left_tree++)
        {
            total_tree += (dp[left_tree] * dp[i - left_tree - 1]);
        }
        dp[i] = total_tree;
    }

    return dp[n];
}
int main()
{
    int n = 1;
    auto ans = numTrees(n);
    return 0;
}