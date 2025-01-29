#include <bits/stdc++.h>

using namespace std;

void countSwaps(vector<int> a) {
    int swap_counter = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size() - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swap_counter++;
            }
        }
    }
    cout << "Array is sorted in " << swap_counter << " swaps." <<endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[a.size()-1] << endl;
}

int main(){
    vector<int> a = {3,2,1};
    countSwaps(a);
    return 0;
}