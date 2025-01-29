#include <bits/stdc++.h>

using namespace std;

int maxSubsetSum(vector<int> arr) {
    vector<int> sum_arr(arr.size());
    sum_arr[0] = arr[0];
    sum_arr[1] = max(sum_arr[0], arr[1]);
    for(int i = 2; i < arr.size(); i++){
        sum_arr[i] = max({arr[i], sum_arr[i-1], sum_arr[i-2]+arr[i]});
    }
    return sum_arr[sum_arr.size()-1];
}

int main(){
    vector<int> arr = {3, 5, -7, 8, 10};
    int result = maxSubsetSum(arr);
    cout << endl << result;
    return 0;
}