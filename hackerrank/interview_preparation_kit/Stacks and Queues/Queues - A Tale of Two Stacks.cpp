#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> first, second;   
        void push(int x) {
            first.push(x);
        }

        void pop() {
            if(second.empty()){
                while(!first.empty()){
                    second.push(first.top());
                    first.pop();
                }
            }
            second.pop();
        }

        int front() {
            if(second.empty()){
                while(!first.empty()){
                    second.push(first.top());
                    first.pop();
                }
            }
            return second.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    // vector<vector<int>> queries = {{1, 42}, {2, 0}, {1, 14}, {3, 0}, {1, 28}, {3, 0}, {1, 60}, {1, 78}, {2, 0}, {2, 0}};
    vector<vector<int>> queries = {{1, 1}, {1,2}, {1, 3}, {3, 0}, {1, 4}, {1, 5}, {3,0}};
    for(int i = 0; i < queries.size(); i++) {
        type = queries[i][0];
        if(type == 1) {
            x = queries[i][1];
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    // 14, 14
    return 0;
}