// OJ: https://leetcode.com/problems/min-stack/
// Author: github.com/punkfulw
// Time: O(1) 
// Space: O(N)
class MinStack {
public:
    vector<pair<int, int>> stk;
    MinStack() {
    }
    
    void push(int val) {
        if (stk.empty())
            stk.push_back({val, val});
        else
            stk.push_back({val, min(stk.back().second, val)});
    }
    
    void pop() {
        stk.pop_back();
    }
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }
};
