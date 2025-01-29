#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> tree;
    tree.push_back({1});
    for(int i = 0; i < indexes.size(); i++){
        vector<>
    }
}

int main(){
    vector<vector<int>> index = {{2, 3}, {-1, 4}, {-1, 5}, {-1,-1}, {-1,-1}};
    vector<vector<int>> result;
    vector<int> k = {2};
    result = swapNodes(index, k);
    cout << endl;
    for(auto x: result) {
        for(auto y: x) cout << y << " ";
    }
    return 0;
}