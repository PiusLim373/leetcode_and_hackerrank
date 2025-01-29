#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int>b){
    return a[0] > b[0];
}

int luckBalance(int k, vector<vector<int>> contests) {
    int luck = 0;
    vector<vector<int>> imp;
    for(auto x: contests) {
        if(!x[1]) luck += x[0];
        else imp.push_back(x);
    }
    sort(imp.begin(), imp.end(), cmp);
    for(auto x: imp){
        if(k>0) {luck += x[0]; k--;}
        else luck -= x[0];
    }
    return luck;
}

int main(){
    int n = 6;
    int k = 3;
    vector<vector<int>> arr = {{5, 1}, {2, 1}, {1, 1}, {8, 1}, {10, 0}, {5, 0}} ;
    int result = luckBalance(k, arr);
    cout << endl << result;
    return 0;
}