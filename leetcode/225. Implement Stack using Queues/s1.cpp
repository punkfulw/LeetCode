// OJ: https://leetcode.com/problems/implement-stack-using-queues
// Author: github.com/punkfulw
// Time: O(N) for push, O(1) for others
// Space: O(1)
class MyStack {
public:
    queue<int> q;
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        int n = q.size();
        while (--n)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int tp = top();
        q.pop();
        return tp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return !q.size();
    }
};
