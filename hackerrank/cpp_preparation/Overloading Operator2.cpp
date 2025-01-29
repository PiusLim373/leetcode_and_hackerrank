#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix{
    public:
        vector<vector<int>> a; //row
};

Matrix operator+(Matrix m1, Matrix m2){
    Matrix return_val;
    vector<int> temp;
    for (int i = 0; i < m1.a.size(); i ++){
        temp.clear();
        for(int j = 0; j < m1.a[i].size(); j++){
            
            temp.push_back(m1.a[i][j] + m2.a[i][j]);
        }
        return_val.a.push_back(temp);
    }
    return return_val;
}

int main () {
   int cases,k;
    Matrix x;
    Matrix y;
    Matrix result;
    int n = 2,m = 2,i,j;
    for(i=0;i<n;i++) {
        vector<int> b;
        int num;
        for(j=0;j<m;j++) {
        b.push_back(2);
        }
        x.a.push_back(b);
    }
    for(i=0;i<n;i++) {
        vector<int> b;
        int num;
        for(j=0;j<m;j++) {
        b.push_back(3);
        }
        y.a.push_back(b);
    }
    result = x+y;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
        cout << result.a[i][j] << " ";
        }
        cout << endl;
    }

   return 0;
}
