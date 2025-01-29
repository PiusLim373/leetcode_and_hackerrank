#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    map<string, int> m;
    m.insert(make_pair("hello", 10));
    int type;
    string name;
    int mark;
    cin >> type >> name;

    switch(type) {
        case 1:
            int marks;
            cin >> marks; 
            if(m.find(name) == m.end()) m.insert(make_pair(name, marks));
            else m[name] += marks;    
            break; 
            
        case 2:
            m.erase(name);
            break;
            
        case 3:
            if(m.find(name) != m.end()) cout << m[name] << endl;
            break;
    }
    
    return 0;
}