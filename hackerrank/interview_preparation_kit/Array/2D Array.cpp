#include <bits/stdc++.h>

using namespace std;


int hourglassSum(vector<vector<int>> arr) {
    vector<int> temp(4, 0); 
    vector<vector<int>> hourglass(4, temp);

    // cout << hourglass[0][0];
    for (int i = 0; i < hourglass.size(); i ++){
        for (int j = 0; j < hourglass.size(); j ++){
            hourglass[i][j] = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
        }
    }
    int max = hourglass[0][0];
    for (int i = 0; i < hourglass.size(); i ++){
        for (int j = 0; j < hourglass.size(); j ++) {
            if(hourglass[i][j] > max) max = hourglass[i][j];
        }
    }
    
    return max;
}

int main(){
    vector<vector<int>> arr(6);
    arr[0] = {1, 1, 1, 0, 0, 0};
    arr[1] = {0, 1, 0, 0, 0, 0};
    arr[2] = {1, 1, 1, 0, 0, 0};
    arr[3] = {0, 0, 2, 4, 4, 0};
    arr[4] = {0, 0, 0, 2, 0, 0};
    arr[5] = {0, 0, 1, 2, 4, 0};

    cout << hourglassSum(arr)<<endl;

    return 0;
}

// for (auto x:hourglass) {
    //     for(auto y: x) cout<< y << " ";
    //     cout <<'\n';
    // }