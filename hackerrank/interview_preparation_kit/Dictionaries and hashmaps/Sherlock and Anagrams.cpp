#include <bits/stdc++.h>

using namespace std;

int sherlockAndAnagrams(string s) {
    int anagram_count = 0;
    map<char, int> s_map;
    for(auto x: s) s_map[x]++;
    for (int i = 0; i < s.size(); i++){

    }
}

int main(){
    string s = "ifailuhkqq";
    int result = sherlockAndAnagrams(s);
    cout << endl << result;
    return 0;
}