#include <bits/stdc++.h>

using namespace std;

long candies(int n, vector<int> arr) {
    vector<int> candies(n, 1);
    long sum = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i-1]) {
            candies[i] = candies[i-1] + 1;
        }
    }
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > arr[i+1] && candies[i] <= candies[i+1]) candies[i] = candies[i+1] + 1;
    }
    for(auto x: arr) cout << x << " "; 
    cout << endl;
    for(auto x: candies) {
        sum += x;
        cout << x << " ";
    }
    return sum;
}

long candiesNotFinished(int n, vector<int> arr) {
    vector<int> candies(n, 0);
    candies[0] = 1;
    int last_add = 0;
    long sum = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i-1]) {
            candies[i] = candies[i-1] + 1;
            last_add = i;
        }
        else if(arr[i] == arr[i-1]){

        }
        else if(arr[i] < arr[i-1]){
            if (candies[i-1] > 1) candies[i] = 1;
            else{
                for(int j = last_add; j < i; j++) candies[j]++;
                candies[i] = 1;
            }
        }
    }
    for(auto x: arr) cout << x << " "; 
    cout << endl;
    for(auto x: candies) {
        sum += x;
        cout << x << " ";
    }
    return sum;
}

int main(){
    vector<int> arr = {2,4,2,6,1,7,8,9,2,1};
    // vector<int> arr = {1,9,8,7};
    int n = arr.size();
    long result = candies(n, arr);
    cout << endl << result;
    return 0;
}