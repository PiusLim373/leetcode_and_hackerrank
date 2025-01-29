#include <bits/stdc++.h>

using namespace std;

int getMinimumCost(int k, vector<int> c) {
    int cost = 0;
    int bought[k] = {0};
    int flower_bought = 0;
    sort(c.begin(), c.end(), greater<int>());
    
    while (flower_bought < c.size()){
        for(int i = 0; i < k; i++){
            cost += (1+bought[i])*c[flower_bought];
            bought[i] ++;
            flower_bought++;
            if (flower_bought >= c.size()) break;
        }
    }
    
    return cost;
}


int main(){
    int k = 3;
    vector<int> c = {1,3,5,7,9};
    int result = getMinimumCost(k, c);
    cout <<endl<<result;
    return 0;
}