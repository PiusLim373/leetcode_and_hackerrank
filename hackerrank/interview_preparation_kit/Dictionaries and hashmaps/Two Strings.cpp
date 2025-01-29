#include <bits/stdc++.h>

using namespace std;

string twoStrings(string s1, string s2) {
    vector<char> ss1(s1.begin(), s1.end());
    vector<char> ss2(s2.begin(), s2.end());
    unordered_map<char, int> c1;
    for(int i = 0; i < ss1.size(); i++){
        if (c1.find(ss1[i]) == c1.end()){
            // #not found
            c1.insert(make_pair(ss1[i], 1));
        }
        else c1[ss1[i]] ++;
    }
    for (int j = 0; j < ss2.size(); j++){
        if(c1.find(ss2[j]) != c1.end()){
            return "YES";
        }
    }
    return "NO";

}

int main(){
    string s1 = "hi";
    string s2 = "world";
    string result = twoStrings(s1,s2);
    cout << result << endl;
    return 0;
}