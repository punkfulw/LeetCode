// OJ: https://leetcode.com/problems/implement-queue-using-stacks
// Author: github.com/punkfulw
// Time: O(1) 
// Space: O(1)
class MyQueue {
public:
    stack<int> InStack, OutStack;
    MyQueue() {}

    void push(int x) {
        InStack.push(x);
    }

    int pop() {
        auto x = peek();
        OutStack.pop();
        return x;
    }

    int peek() {
        if (OutStack.empty()){  
            while (!InStack.empty()){
                auto x = InStack.top();
                InStack.pop();
                OutStack.push(x);
            }
        }
        return OutStack.top();
    }

    bool empty() {
        return InStack.empty() && OutStack.empty();
    }
};
