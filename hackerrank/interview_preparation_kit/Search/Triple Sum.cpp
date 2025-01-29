#include <bits/stdc++.h>

using namespace std;


long triplets(vector<int> a, vector<int> b, vector<int> c) {
    long triplets_count = 0;
    map<int, int>am, bm, cm;
    for(auto x: a) am[x] = x;
    for(auto x: b) bm[x] = x;
    for(auto x: c) cm[x] = x;

    a.clear();
    b.clear();
    c.clear();
    for(auto x: am) a.push_back(x.first);
    for(auto x: bm) b.push_back(x.first);
    for(auto x: cm) c.push_back(x.first);
    int i = 0, j = 0, k = 0;

    while(i < b.size()){
        while(j < a.size() && a[j] <= b[i]){
            j++;
        }
        while(k<c.size() && c[k] <= b[i]){
            k++;
        }
        triplets_count += (long)j*k;
        i++;
        
    }

    return triplets_count;
}


int main(){
    // vector<int> a = {1,3,5};
    // vector<int> b = {2,3};
    // vector<int> c = {1,2,3};

    vector<int> a = {1,4,5};
    vector<int> b = {3,2,3};
    vector<int> c = {1,2,3};
    long result = triplets(a, b, c);
    cout << endl << result;
    return 0;
}