#include <bits/stdc++.h>

using namespace std;

long countTriplets(vector<long> arr, long r){
    sort(arr.begin(), arr.end());
    long result;
    map<long, long>before, after;
    for(long i = 0; i<arr.size(); i++){
        after[arr[i]] ++;
    }

    // for(long i = 0; i<arr.size(); i++){
    //     after[arr[i]] --;
    //     if ((before.count(arr[i] / r)) && (arr[i]%r == 0) &&(after.count(arr[i] * r))){
    //         result +=  before[arr[i]/r]*after[arr[i]*r];
    //     }
    //     before[arr[i]] ++;
    // }

    for (auto x: arr){
        after[x]--;
        if((before.count(x/r)) && (x%r == 0) && (after.count(x*r))){
            result += before[x/r] * after[x*r];
        }
        before[x]++;
    }
    return result;
}

long countTripletsTimedOut(vector<long> arr, long r){
    sort(arr.begin(), arr.end());
    long result;
    for(int i = 0; i<arr.size(); i++){
        map<long, long>before, after;
        long current = arr[i];
        for (int j = i-1; j >= 0 ; j--){
            if(arr[j] < arr[i]/r) break;
            before[arr[j]] ++;
        }
        for (int k = i+1; k < arr.size() ; k++){
            if(arr[k] > arr[i]*r) break;
            after[arr[k]] ++;
        }
        result +=  before[arr[i]/r]*after[arr[i]*r];
    }
    return result;
}

long countTripletsSolutionICantUnderstand(vector<long> arr, long r){
    map<int,long> mp2, mp3;
    long res = 0;
    for(auto val: arr){
        if (mp3.count(val))		//This value completes mp3[val] triplets
            res += mp3[val];
        if (mp2.count(val))		//This value is valid as 2° part of mp2[val] triplets
            mp3[val*r] += mp2[val];
        mp2[val*r]++;			//"Push-up" this value as possible triplet start
    }
    return res;
}

long countTripletsFailedRatio1(vector<long> arr, long r) {
    unordered_map<long, long> maps;
    for(int i = 0; i < arr.size(); i++){
        if(maps.find(arr[i]) == maps.end()){
            maps.insert(make_pair(arr[i], 1));
        }
        else maps[arr[i]] ++;
    }
    long total_arr = maps.size() - 2;
    for (long j = 0; j < maps.size(); j++){
        total_arr *= maps[pow(r, j)];
    }
    return total_arr;
}

int main(){
    long ratio = 5;
    vector<long> arr = {1,5,5,5,25,25,125};
    
    // vector<long> arr = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    // vector<long> arr = {1,1,1,1,1};
    long result = countTriplets(arr, ratio);
    cout << result << endl;
    return 0;
}

// test case 2 
// 100 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 161700