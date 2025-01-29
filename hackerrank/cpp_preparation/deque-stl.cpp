#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    deque<int> dq;
    for (int i = 0; i < n; i++){
        if (dq.empty()) dq.push_back(i);
        if (arr[i] > dq.front()) dq.pop_front();
        if (i >= k) cout << dq.front() ;
    }
}



void printKMax_soln(int arr[], int n, int k){
    deque<int> maxs;
    for(int i = 0; i < n; i++) {
        
        while(!maxs.empty() && arr[i] > arr[maxs.back()]) {
            maxs.pop_back();
        }
        maxs.push_back(i);
        
        while(!maxs.empty() && maxs.front() <= (i - k)) {
            maxs.pop_front();
        }

        if (i >= k-1) {
            cout << arr[maxs.front()] << " ";
        }
        cout << "i = " << i << " ";
        for (int m = 0; m < maxs.size(); m++) cout << maxs[m] ;
        cout <<endl;
    }
    cout << endl;
}

// void printKMax_timedout(int arr[], int n, int K){
//     deque<int> dq;
//     deque<int> temp_dq;
//     for(int i = 0; i < n; i ++){
//         dq.push_back(arr[i]);
//     }
//     for(int j = 0; j <= n-K; j++){
//         temp_dq = dq;
//         for (int k = 0; k < j; k ++){
//             temp_dq.pop_front();
//         }
//         for (int l = j+K; l < n; l++ ){
//             temp_dq.pop_back();
//         }
//         cout << *max_element(temp_dq.begin(), temp_dq.end()) << " ";
//     }
//     cout << endl;
// }

int main(){
    int K = 4;
    int size = 5;
    int size2 = 7;
    int arr[size] = {3,4,6,3,4};
    int arr2[size2] = {3,4,5,8,1,4,10};
    // for (auto x: arr) cout <<x<< endl;
    printKMax(arr2, size2, K);
}