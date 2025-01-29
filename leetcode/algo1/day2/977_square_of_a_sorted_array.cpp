#include <bits/stdc++.h>
using namespace std;

bool custom_cmp(int &a, int &b)
{
    a = a * a;
    b = b * b;
    return a < b;
}

int main()
{
    vector<int> arr = {-4, -1, 0, 3, 10};
    // vector<int> ans;
    // for (auto x : arr)
    // {
    //     // cout << x * x << " ";
    //     ans.push_back(x * x);
    // }
    // cout << endl;
    // sort(ans.begin(), ans.end());
    // for (auto x : ans)
    //     cout << x << " ";

    // sort(arr.begin(), arr.end(), custom_cmp);
    // for (auto x : arr)
    //     cout << x << " ";

    // best ans
    vector<int> res(arr.size());
    int l = 0, r = arr.size() - 1;
    for (int k = arr.size() - 1; k >= 0; k--)
    {
        if (abs(arr[r]) > abs(arr[l]))
            res[k] = arr[r] * arr[r--];
        else
            res[k] = arr[l] * arr[l++];
    }
    for (auto x : res)
        cout << x << " ";
}