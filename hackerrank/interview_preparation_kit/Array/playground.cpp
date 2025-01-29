#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    map<int, long> hi;
    hi.insert(make_pair(1, 100));
    hi[1] += 200;
    cout << hi[1];
}