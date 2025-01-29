#include <bits/stdc++.h>

using namespace std;

int freArr[201] = {0};

int twice_median(int d){
    int sum = 0;
    for(int j = 0; j < 201; j++){
        sum += freArr[j];
        if (2*sum > d){
            return 2*j;
        }
        else if (2*sum == d){
            for (int k = j+1;; k++){
                    if (freArr[k]){
                        return (j+k);
                }
            }
        }      
    }
    return -1;
}

int activityNotifications(vector<int> expenditure, int d) {
    int noti_counter = 0;
    
    for(int i = 0; i < expenditure.size(); i++){
        if (i >= d){
            
            if (expenditure[i] >= twice_median(d)) noti_counter++;
            freArr[expenditure[i-d]]--;
        }
        freArr[expenditure[i]] ++;
    }
    return noti_counter;
}
// void countSort(vector<int>& arr)
// {
//     int max = *max_element(arr.begin(), arr.end());
//     int min = *min_element(arr.begin(), arr.end());
//     int range = max - min + 1;
 
//     vector<int> count(range), output(arr.size());
//     for (int i = 0; i < arr.size(); i++)
//         count[arr[i] - min]++;
 
//     for (int i = 1; i < count.size(); i++)
//         count[i] += count[i - 1];
 
//     for (int i = arr.size() - 1; i >= 0; i--) {
//         output[count[arr[i] - min] - 1] = arr[i];
//         count[arr[i] - min]--;
//     }
 
//     for (int i = 0; i < arr.size(); i++)
//         arr[i] = output[i];
// }
// int activityNotifications(vector<int> expenditure, int d) {
//     int noti_counter = 0;
//     vector<int> expenditure_sorted = expenditure;
//     vector<int> median_vec;
//     vector<int> sorted_median_vec(0, d);
//     map<int, int> sorter;
    
//     for (int i = 0; i < expenditure.size() - d; i++){
//         float median = 0;
//         int first_value = expenditure[i];
        
//         if(i == 0){
//             for(int j = 0+i; j < d+i; j++){
//                 median_vec.push_back(expenditure[j]);
//             }
//             for (auto x:median_vec){
//                 sorter[x]++;
//             }
//             map<int, int>::iterator it;
//             for(it = sorter.begin()+1; it != sorter.end(); it++){

//             }
//             for(int k = 0; k < d; k++){
//                 sorted_median_vec[k] = sorter[median_vec[k]];
//                 sorter[median_vec[k]]--;
//             }
//         }
//         else{
//             sorter[first_value]--;
//             sorter[expenditure[i+d]]++;
//         }
        
        
        
        
//         sort(median_vec.begin(), median_vec.end());

//         if(d%2) median = median_vec[(float)d/2 - 0.5];
//         else median = (float)(median_vec[d/2] + median_vec[d/2 -1])/2;

//         int spending = expenditure[d+i];
//         if (spending >= 2*median) noti_counter++;
    
//     }
//     return noti_counter;
// }

// int activityNotificationsTimedOut2(vector<int> expenditure, int d) {
//     int noti_counter = 0;
//     vector<int> expenditure_sorted = expenditure;
//     vector<int> median_vec;
    
//     for (int i = 0; i < expenditure.size() - d; i++){
//         float median = 0;
//         int first_value = expenditure[i];

//         if(i != 0){
//             remove(median_vec.begin(), median_vec.end(), first_value);
//             median_vec.push_back(expenditure[i+d]);
//         }
//         else{
//             for(int j = 0+i; j < d+i; j++){
//                 median_vec.push_back(expenditure[j]);
//             }
//         }
        
//         countSort(median_vec);

//         if(d%2) median = median_vec[(float)d/2 - 0.5];
//         else median = (float)(median_vec[d/2] + median_vec[d/2 -1])/2;

//         int spending = expenditure[d+i];
//         if (spending >= 2*median) noti_counter++;
    
//     }
//     return noti_counter;
// }

// int activityNotificationsTimedOut(vector<int> expenditure, int d) {
//     int noti_counter = 0;
    
//     vector<float> median_vec;
//     for (int i = 0; i < expenditure.size() - d; i++){
//         vector<int> exp_copy = expenditure;
//         sort(exp_copy.begin()+i, exp_copy.begin()+d+i);

//         float median = 0;
//         if(d%2) median = exp_copy[(float)d/2 + 0.5+i-1];
//         else median = (float)(exp_copy[d/2+i] + exp_copy[d/2 -1+i])/2;

//         int spending = expenditure[d+i];
//         if (spending >= 2*median) noti_counter++;
    
//     }
//     return noti_counter;
// }

int main(){
    vector<int> expenditure = {2, 3, 4, 2, 3, 6, 8, 4, 5};
    int days = 5;

    // vector<int> expenditure = {1, 2, 3, 4, 4};
    // int days = 4;

    int notification = activityNotifications(expenditure, days);
    cout << notification <<endl;
    return 0;
}