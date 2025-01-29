#include <bits/stdc++.h>

using namespace std;

void minimumBribes(vector<int>q){
    int bribe_count = 0;
    for(int i = q.size() - 1; i > 0; i-- ){
        if(q[i] != (i+1)){
            if (q[i-1] == (i+1)){
                bribe_count ++;
                int temp = q[i];
                q[i] = q[i-1];
                q[i-1] = temp;
            }
            else if(q[i-2] == (i+1)){
                bribe_count += 2;
                int temp1 = q[i], temp2 = q[i-1];
                q[i] = q[i-2];
                q[i-2] = temp2;
                q[i-1] = temp1;
            }
            else{
                cout << "Too chaotic" <<endl;
                return;
            }
        }
    }
    cout << bribe_count <<endl;
}

void minimumBribesTimeout(vector<int> q) {
    vector<int> reference(q.size());
    iota(reference.begin(), reference.end(), 1);
    // for(auto x:reference) cout << x << " ";
    int bribe_count = 0;
    vector<int> intermediate = reference;
    while(!intermediate.empty()){
        // cout << intermediate[0] << " " << q[0] <<endl;
        if(q[0] != intermediate[0]){
            bool found = false;
            int j = 1;
            while(!found && j<=2){
                if(q[0] == intermediate[j]){
                    found = true;
                    break;
                }
                else j++;
            }
            if(!found){
                cout << "Too chaotic" <<endl;
                return;
            }
            bribe_count += j;
            if(j == 1){
                cout<<"hi" <<endl;
                intermediate[0] = q[0];
                intermediate[1] = reference[0];
            }
            if(j == 2){
                cout<<"hi2" <<endl;
                intermediate[0] = q[0];
                intermediate[1] = reference[0];
                intermediate[2] = reference[1];
            }
        }
        // cout << "=======" << endl;
        
        intermediate.erase(intermediate.begin());
        q.erase(q.begin());
        reference = intermediate;
        // for (auto x: intermediate) cout << x <<" ";
        // cout << endl;
        // for (auto y: q) cout << y <<" ";
        // cout << endl;
    }
    cout<< bribe_count;
}


    // for(int i = 0; i < reference.size(); i++){
    //     if (q[i] != reference[i]){
    //         bool found = false;
    //         int j = 0;
    //         while(!found && j<2){
    //             if(q[i] == reference[i+j]){
    //                 found = true;
    //                 break;
    //             }
    //             else j++;
    //         }
    //         if(!found){
    //             cout << "Too chaotic" <<endl;
    //             return;
    //         }
    //         bribe_count += j;

    //     }
    // }
// }

void minimumBribesBugged(vector<int> q) {
    vector<int> reference(q.size());
    iota(reference.begin(), reference.end(), 1);
    // for(auto x:reference) cout << x << " ";
    int total = 0;
    bool chaotic = false;
    for(int i = 0; i < q.size(); i++){
        if (chaotic) break;
        bool found = false;
        int count = 0;
        signed int j = -2;
        while(j<3 && !found){
            // cout<<"trying" << i <<" "<<j <<" "<<reference[i]<<" "<<q[i+j] <<endl;

            if(reference[i] == q[i+j]) {
                // cout<<"found" << i <<" "<<i+j <<endl;
                count += abs(j);
                found = true;
            }
            
            j++;
        }
        if (!found){
            chaotic = true;
            break;
        }
        // cout << count <<endl;
        total+=count;
    }
    if(!chaotic){
        int divisor = total/2;
        int remainder = total%2;
        cout<< divisor+remainder <<endl;
    }
    else cout << "Too chaotic" <<endl;
    
}

void test(){
    vector<int> reference(5);
    iota(reference.begin(), reference.end(), 1);
    cout << reference[-1];
}

int main(){
    // vector<int> q = {3,2,1,6,5,4};
    vector<int> q = {1, 2, 5, 3, 7, 8, 6, 4};
    minimumBribes(q);
    // test();
    return 0;
}