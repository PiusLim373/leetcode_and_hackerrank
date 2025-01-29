#include <bits/stdc++.h>
using namespace std;

vector<int> freqQuery(vector<vector<int>> queries) {
    map<int, int> arr;
    map<int, int> fre_map;
    vector<int> return_val;
    for(int i = 0; i < queries.size(); i++){
        if(queries[i][0] == 1){
            if(arr[queries[i][1]]) fre_map[arr[queries[i][1]]] --;
            arr[queries[i][1]]++;
            fre_map[arr[queries[i][1]]] ++;
        }
        else if(queries[i][0] == 2 && arr.count(queries[i][1])){
            
            fre_map[arr[queries[i][1]]] --;
            arr[queries[i][1]]--;
            fre_map[arr[queries[i][1]]] ++;
           
        }
        else if(queries[i][0] == 3){
            if(fre_map[queries[i][1]]) return_val.push_back(1);
            else return_val.push_back(0);
        }
    }
    
    return return_val;
}

int main()
{
    int q;
    long x, y;
    unordered_map<long,long> arr, fre_map;
    
    cin >> q;
    while(q--){
        cin >> x >> y;
        if (x == 1){
            if(arr[y]) fre_map[arr[y]] --;
            arr[y]++;
            fre_map[arr[y]] ++;
        }
        else if (x == 2){
            fre_map[arr[y]] --;
            arr[y]--;
            fre_map[arr[y]] ++;
        }
        else if(x == 3){
            if(fre_map[y]) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}

vector<int> freqQueryBugged(vector<vector<int>> queries) {
    map<int, int> array;
    map<int, int> fre_map;
    vector<int> return_val;

    int last_query = 0; 
    for (int i = 0; i < queries.size(); i++){
        if(queries[i][0] == 3){
            last_query = i;
        }
    }
    for (int i = 0; i < last_query+1; i++){
        if(queries[i][0] == 1) {
            if(array[queries[i][1]] > 0){
                int original_fre = array[queries[i][1]];
                fre_map[original_fre+1] ++;
                if(original_fre>0) fre_map[original_fre] --;
            }
            else  fre_map[1] ++;
            array[queries[i][1]] ++;
        }
        else if((queries[i][0] == 2) && (array.count(queries[i][1]))) {
            int original_fre = array[queries[i][1]];
            if(original_fre-1>0) fre_map[original_fre-1] ++;
            fre_map[original_fre] --;

            array[queries[i][1]] --; 
        }
        else if(queries[i][0] == 3){
            if (fre_map[queries[i][1]]) return_val.push_back(1);
            else return_val.push_back(0);
        } 
    }
    return return_val;
}

vector<int> freqQuerybugged(vector<vector<int>> queries) {
    map<int, int> array;
    map<int, int> fre_map;
    vector<int> checkpoint;
    vector<int> return_val;
    for(int i = 0; i < queries.size(); i++){
        if (queries[i][0] == 3) checkpoint.push_back(i);
    }
    int last_processed_checkpoint = 0;
    for(int i = 0; i < checkpoint.size(); i++){
        int query_val = queries[checkpoint[i]][1];
        int found = 0;
        for (int j = last_processed_checkpoint; j < checkpoint[i]; j ++){
            if(queries[j][0] == 1) {
                array[queries[j][1]] ++;
            }
            else if(queries[j][0] == 2 && array.count(queries[j][1])) array[queries[j][1]] --;
        }
        for(auto x: array){
            if (x.second == query_val) {
                found = 1;
                break;
            }
        }
        return_val.push_back(found);
        last_processed_checkpoint = checkpoint[i]+1;
    }
    return return_val;
}

int main(){
    // vector<vector<int>> queries = {{1,5}, {2,5}, {1,5}, {1,6}, {3,1}, {1,10}, {1, 10}, {1,6}, {2,5}, {3,2}, {3,1}};
    vector<vector<int>> queries = {{3, 4},{2, 1003},{1, 16},{3, 1}};
    vector<int> result = freqQuery(queries);
    for(auto x: result) cout << x <<endl;
    return 0;
}
