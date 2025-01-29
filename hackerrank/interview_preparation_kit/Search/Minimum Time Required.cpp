#include <bits/stdc++.h>

using namespace std;

long produced(vector<long> machines, long day){
    long product = 0;
    for(auto x: machines) product+= day/x;
    return product;
}

long minTime(vector<long> machines, long goal) {
    sort(machines.begin(), machines.end());
    long high = machines[machines.size()-1] * goal;
    long low = 1;
    
    while(low < high){
        long mid = (low+high)/2;
        long production = produced(machines, mid);
        if (production > goal) high = mid;
        else if(production < goal) low = mid+1;
        else return mid;
    }
    return high;
}

long minTimeTimedOut(vector<long> machines, long goal) {
    vector<long> have_produced(machines.size(), 0);
    long day_counter = 0;
    long produced = 0;
    while(produced < goal){
        for(int i = 0; i < machines.size(); i ++){
            if ((have_produced[i] + 1)*machines[i] == day_counter){
                produced++;
                have_produced[i] ++;
            }
        }
        if(produced == goal) break;
        day_counter++;
    }
    return day_counter;
}



int main(){
    long goal = 5;
    vector<long> machine = {2, 3};
    long result = minTime(machine, goal);
    cout << endl << result;
    return 0;
}