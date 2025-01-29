#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <chrono>
using namespace std;

int main(){

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    set<int> s;
    for (int  i = 0; i < 1000; i++) s.insert(i);

    int query = 980;

    cout<<((s.find(query) != s.end()) ? "Yes":"No");
    return 0;
}