#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 3, 5, 6};
    int target = 7;
    cout << lower_bound(arr.begin(), arr.end(), target) - arr.begin() << endl;
}