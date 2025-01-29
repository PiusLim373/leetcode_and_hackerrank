#include <bits/stdc++.h>

using namespace std;

void checkMagazine(vector<string> magazine, vector<string> note) {
    sort(magazine.begin(), magazine.end());
    sort(note.begin(), note.end());
    vector<string> resultant(note.size());
    set_difference(note.begin(), note.end(), magazine.begin(), magazine.end(), resultant.begin());
    for (auto x: resultant) cout << x << " ";
    
    if (resultant[0] == "") cout << "Yes" <<endl;
    else cout << "No" <<endl;
}

int main(){
    vector<string> magazine = {"give", "me", "one", "grand", "today", "night", "huattt"};
    vector<string> note = {"one","give", "grand", "today"};
    checkMagazine(magazine, note);
    return 0;
}