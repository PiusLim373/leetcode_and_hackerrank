#include <bits/stdc++.h>

using namespace std;

string isBalanced(string s){
    if (s.size() % 2) return "NO";
    vector<char> stack;
    stack.push_back(s[0]);
    for(int i = 1; i < s.size(); i++){
        if((stack.back() == '{' && s[i] == '}') ||  (stack.back() == '[' && s[i] == ']') || (stack.back() == '(' && s[i] == ')')) stack.pop_back();
        else stack.push_back(s[i]);
    }
    if (stack.size()) return "NO";
    else return "YES";
}

int main(){
    string aa = "{(([])[])[]}[]";
    string result = isBalanced(aa);
    cout << endl << result;
    return 0;
}

// {(([])[])[]}    YES
// {(([])[])[]]}   NO
// {(([])[])[]}[]  YES