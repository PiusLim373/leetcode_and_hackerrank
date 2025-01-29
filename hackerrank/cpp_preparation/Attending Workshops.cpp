#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops
{
    int start_time, duration, end_time;
};

struct Available_Workshops
{
    vector<Workshops> vect;
};

Available_Workshops* initialize(int* starttime, int* duration, int count){
    struct Available_Workshops return_val;
    int k = 0;
    while(count--){
        struct Workshops temp;
        temp.start_time = starttime[k];
        temp.duration = duration[k];
        temp.end_time = temp.start_time + temp.duration;
        return_val.vect.push_back(temp);
        k++;
    }
    return &return_val;
    
}

int CalculateMaxWorkshops(Available_Workshops* aa){
    aa.
}

// int main(int argc, char *argv[]) {
//     int n; // number of workshops
//     cin >> n;
//     // create arrays of unknown size n
//     int* start_time = new int[n];
//     int* duration = new int[n];

//     for(int i=0; i < n; i++){
//         cin >> start_time[i];
//     }
//     for(int i = 0; i < n; i++){
//         cin >> duration[i];
//     }

//     Available_Workshops * ptr;
//     ptr = initialize(start_time,duration, n);
//     cout << CalculateMaxWorkshops(ptr) << endl;
//     return 0;
// }

int main(int argc, char *argv[]) {
    int n = 6; // number of workshops
    // create arrays of unknown size n

    int start_time[] = {1, 3, 0, 5, 5, 8};
    int duration[] = {1, 1, 6, 2, 4, 1};

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
