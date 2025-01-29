#include <bits/stdc++.h>

using namespace std;

int minimumSwaps(vector<int> arr) {
    int swap = 0;
    for(int i = 0; i < arr.size(); i++){
        while(arr[i] != i+1){
            swap++;
            int temp = arr[arr[i] - 1];
            arr[arr[i] - 1] = arr[i];
            arr[i] = temp;
        }
    }
    return swap;
}

int main(){
    vector<int> arr = {4,3,1,2};
    // vector<int> arr = {1, 3, 5, 2, 4, 6, 7};
    int result = minimumSwaps(arr);
    cout << result << endl;
    return 0;
}