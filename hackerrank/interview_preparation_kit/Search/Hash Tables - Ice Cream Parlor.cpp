#include <bits/stdc++.h>

using namespace std;

void whatFlavors(vector<int> cost, int money) {
    map<int, int> remains;
    for(int i = 0; i < cost.size(); i++){
        int money_remains = money - cost[i];
        auto it = remains.find(money_remains);
        if(it != remains.end()){
            cout << it->second + 1 << " " << i+1<< endl;
            return;
        }
        remains.insert(pair<int, int>(cost[i], i));
    }
}

void whatFlavorstimeOut2(vector<int> cost, int money) {
    vector<int> remains;
    for(int i = 0; i < cost.size(); i++){
        vector<int>::iterator it = std::find(remains.begin(), remains.end(), money - cost[i]);
        if(it != remains.end()){
            cout << distance(remains.begin(), it)+1 << " "<< i+1 <<endl;
            return;
        }
        else remains.push_back(cost[i]);
    }
}

// map<int, int> flavor_position;


// int find_position(int a){
//     for(map<int,int>::iterator it=flavor_position.begin(); it!=flavor_position.end(); ++it){
//         if(it->second == a){
//             it-> second = -1;
//             return it->first;
//         }
//     }
//     return 0;
// }

// void whatFlavorsTimedOut(vector<int> cost, int money) {
//     flavor_position.clear();
//     for(int i = 0; i < cost.size(); i++){
//         flavor_position[i+1] = cost[i];
//     }
//     sort(cost.begin(), cost.end());
//     for(int i = 0; i< cost.size(); i++){
//         int money_spent = 0;
//         for(int j = i+1; j < cost.size(); j++){
//             money_spent = cost[i] + cost[j];
//             if (money_spent == money) {
//                 int pose1 = find_position(cost[i]);
//                 int pose2 = find_position(cost[j]);
//                 if (pose1 <= pose2) cout << pose1 << " " << pose2 << endl; 
//                 else cout << pose2 << " " << pose1 << endl; 
//                 // cout << find_position(cost[i]) << " " << find_position(cost[j]) << endl; 
//                 return;
//             }
//             else if(money_spent > money) break;
//         }

//     }

// }


int main(){
    int money = 12;
    int trip = 1;
    // vector<int> cost = {1, 4, 5, 3, 2};
    vector<int> cost2 = {7, 2, 5, 4, 11};
    // vector<int> cost2 = {1, 2, 3, 5, 6};
    // while (trip--){
    //     vector<int> temp_cost;
    //     if (trip == 1) temp_cost = cost;
    //     else temp_cost = cost2;
    //     whatFlavors(temp_cost, money);
    // }
    whatFlavors(cost2, money);
    return 0;
}