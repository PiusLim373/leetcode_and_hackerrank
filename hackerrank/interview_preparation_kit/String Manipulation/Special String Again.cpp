#include <bits/stdc++.h>

using namespace std;

long substrCount(int n, string s) {
    int special_string_counter = s.size();
    for(int i = 0 ; i < s.size(); i++){
        char temp_char = s[i];
        int j;
        for (j = 0; j < s.size()-i; j++){
            if(s[i+j] != temp_char) char temp_char2 = s[i+j];
        }
        if (j>1) {
            for(;j>1;j--) special_string_counter += j- 
        } 
    }

}

int main(){
    string s = "asasd";
    int n = 5;
    long result = substrCount(n, s);
    cout << result;
    return 0;
}