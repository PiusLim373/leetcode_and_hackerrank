#include <bits/stdc++.h>

using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) {
    
    long max_val = 0;
    long sum = 0;
    vector<int> zeros(n+1, 0);
    // for(auto x: zeros) cout << x << " ";

    for(auto x: queries){
        zeros[x[0]-1] += x[2];
        zeros[x[1]] -= x[2]; 
    }

    for(auto y: zeros){
        sum += y;
        if(sum>max_val) max_val = sum;
    }

    return max_val;
}

long arrayManipulationTimedOut2(int n, vector<vector<int>> queries) {
    
    long max_val = 0;
    vector<int> zeros(n, 0);
    for(int i = 0; i < n; i ++){
        for(auto x: queries){
            if(i >= x[0]+1 && i <= x[1]+1 ){
                zeros[i] += x[2];
                if (zeros[i] >= max_val) max_val = zeros[i]; 
            }
        }
    }

    return max_val;
}

long arrayManipulationTimedOut(int n, vector<vector<int>> queries) {
    
    long max_val = 0;

    map<int, long> queries_sum;
    for(auto x: queries){
        for(int i = x[0]; i < x[1]+1; i++){
            if(queries_sum.find(i) != queries_sum.end()){
                //found key, update its value
                queries_sum[i] += x[2]; 
                if (queries_sum[i] > max_val) max_val = queries_sum[i];
            }
            else{
                //cant find key, create a new onw
                queries_sum.insert(make_pair(i, x[2]));
                if (x[2] > max_val) max_val = x[2];
            }
        }
        
    }

    return max_val;
}


int main(){
    int n = 5;
    vector<vector<int>> q = {{1,2,100}, {2,5,100}, {3,4,100}};
    long result = arrayManipulation(n, q);
    cout << result<<endl;
    return 0;
}