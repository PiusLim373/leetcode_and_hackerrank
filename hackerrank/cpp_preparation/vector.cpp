#include <iostream>
#include <exception>
#include <string>
#include <cstring>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <typeinfo>
#include <algorithm>

using namespace std;


int main(){
    vector<int> v = {1, 1, 2, 2, 6, 9, 9, 15};


    int query = 4;
    
    vector<int>::iterator low = lower_bound(v.begin(), v.end(), query);
    int index = distance(v.begin(), low) + 1;
    if((v[index -1] - query) == 0){
        cout << "Yes ";
    }
    else{
        cout << "No ";
    }
    cout << index << endl;


}
