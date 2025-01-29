#include <bits/stdc++.h>

using namespace std;

vector<int> rotLeft(vector<int> a, int d) {
    vector<int> shifted;
    shifted.push_back(a[d]);
    for(int i = d+1; i<a.size(); i++){
        shifted.push_back(a[i]);
    }
    for(int i = 0; i<d; i++){
        shifted.push_back(a[i]);
    }
    for (auto x: shifted) cout<<x<<" ";
    return shifted;
}


int main(){
    vector<int> a = {1, 2, 3, 4, 5};
    int step = 4;
    rotLeft(a, step);
    return 0;
}