#include <bits/stdc++.h>

using namespace std;

int minimumAbsoluteDifference(vector<int> arr) {
    vector<int> diff;
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < arr.size()- 1; i++)  diff.push_back(abs(arr[i] - arr[i+1]));
    return *min_element(diff.begin(), diff.end());
}

int main(){
    vector<int> arr = {-59, -36, -13, 1, -53, -92, -2, -96, -54, 75};
    int result = minimumAbsoluteDifference(arr);
    cout << result;
    return 0;
}