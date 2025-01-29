#include <bits/stdc++.h>

using namespace std;

long largestRectangle(vector<int> h) {
    long area = 0;
    stack<int> p_stack;
    stack<int> h_stack;
    p_stack.push(0);
    h_stack.push(h[0]);
    for(int i = 1; i < h.size(); i++){
        if(h[i] > h_stack.top()){
            p_stack.push(i);
            h_stack.push(h[i]);
        }
        else{
            //smaller, compute area 1st
            int lastpose;
            while(!h_stack.empty() && h_stack.top() > h[i]){
                long temp_area = h_stack.top() * (i - p_stack.top());
                lastpose = p_stack.top();
                area = max(area, temp_area);
                h_stack.pop(); 
                p_stack.pop();
            }
            h_stack.push(h[i]);
            p_stack.push(min(lastpose, i)); 
            
        }
    }
    while(!p_stack.empty()){
        long temp_area = h_stack.top() * (h.size() - p_stack.top());
        area = max(area, temp_area);
        h_stack.pop(); 
        p_stack.pop();
    }
    return area;
}

int main(){
    vector<int> bulding = {8979, 4570, 6436, 5083, 7780, 3269, 5400, 7579, 2324, 2116};
    long area = largestRectangle(bulding);
    cout << endl << area;
    return 0;
}