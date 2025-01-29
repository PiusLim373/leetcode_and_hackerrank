#include <bits/stdc++.h>

using namespace std;

int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());
    int upper_bound;
    for (int i = 0; i < prices.size(); i ++){
        if (prices[i] > k ) upper_bound = i-1;
    }
    int gift_counter = 0;
    int spent = 0;
    for (int i = 0; i < upper_bound; i++){
        spent += prices[i];
        if (spent <= k) gift_counter++;
        else break;
    }
    return gift_counter;
}

int main(){
    vector<int> prices = {1,12, 5, 111, 200, 1000, 10};
    int k = 50;
    int result = maximumToys(prices, k);
    cout << result <<endl;
    return 0;
}