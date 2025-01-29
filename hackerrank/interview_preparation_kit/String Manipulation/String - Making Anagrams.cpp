#include <bits/stdc++.h>

using namespace std;

int makeAnagram(string a, string b) {
    int steps = 0;
    string combined = a+b;
    map<char, int>combined_map;
    for(auto x: combined) combined_map[x]++;
    for(auto x: combined_map) combined_map[x.first] = 0;

    map<char, int> a_map, b_map;
    for(auto x: a) a_map[x]++;
    for(auto x: b) b_map[x]++;
    
    for(auto x: combined_map){
        combined_map[x.first] = abs(a_map[x.first] - b_map[x.first]);
        steps += combined_map[x.first];
    }

    return steps;
}


int main(){
    string a = "fcrxzwscanmligyxyvym";
    string b = "jxwtrhvujlmrpdoqbisbwhmgpmeoke";

    int result = makeAnagram(a, b);
    cout << result << endl;
    return 0;
}