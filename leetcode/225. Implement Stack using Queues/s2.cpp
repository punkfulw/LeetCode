// OJ: https://leetcode.com/problems/implement-stack-using-queues/
// Author: github.com/punkfulw
// Time: O(N) for pop, O(1) for others
// Space: O(1)
class MyStack {
public:
    queue<int> q;
    int t;
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        t = x;
    }
    
    int pop() {
        int n = q.size(), ret = t;
        while (--n)
        {
            if (n == 1)
                t = q.front();
            q.push(q.front());
            q.pop();
        }
        q.pop();
        return ret;
    }
    
    int top() {
        return t;
    }
    
    bool empty() {
        cout << q.front() << endl;
        return !q.size();
    }
};
