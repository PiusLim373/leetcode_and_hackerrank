#include <bits/stdc++.h>

using namespace std;

int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int fairness = arr[arr.size()-1];
    deque<int> chosen;
    for(int i = 0; i < arr.size()-k+1; i++){
        if (chosen.size() < k){
            for(int j = 0; j < k; j++) chosen.push_back(arr[j+i]);
        }
        else{
            chosen.pop_front();
            chosen.push_back(arr[i+k-1]);
        }
        int diff = chosen[k-1] - chosen[0];
        if (fairness > diff) fairness = diff;
    }
    return fairness;
}


int maxMinBugged(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    vector<int> chosen;
    for(int i = 0; i < k; i++){
        chosen.push_back(arr[i]);
    }
    return *max_element(chosen.begin(), chosen.end()) - *min_element(chosen.begin(), chosen.end());
}


int main(){
    int k = 3;
    // vector<int> arr = {1,2,3,4,10,20,30,40,100,200};
    // vector<int> arr = {5,2,1,2,1,2,1};
    vector<int> arr = {10,100,300,200,1000,20,30};
    // vector<int> arr = {10,20,30,100,101,102};
    int result = maxMin(k, arr);
    cout << endl << result;
    return 0;
}