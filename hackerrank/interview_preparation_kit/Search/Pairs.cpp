#include <bits/stdc++.h>

using namespace std;

int pairs(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int counter = 0;
    int i = 0;
    int j = 1;
    while(i<arr.size()){
        if (j > arr.size()) break;
        int diff = abs(arr[i] - arr[j]);
        if (diff == k) {
            counter ++;
            i ++;
            j = i+1;
        }
        else if(diff < k )j++;
        else if(diff > k )i++;

    }
    return counter;
}

int pairsError(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    map<int, int> failure;
    int counter = 0;
    for (int i = 0; i< arr.size(); i++){
        int diff = abs(k - arr[i]); 
        auto it = failure.find(diff);
        if(it != failure.end()) counter++;
        failure.insert(make_pair(arr[i], i));
    }
    return counter;
}

int main(){
    int k = 2;
    vector<int> arr = {1, 3, 5, 8, 6, 4, 2};
    int result = pairs(k, arr);
    cout << endl << result;
    return 0;
}