// OJ: https://leetcode.com/problems/design-a-stack-with-increment-operation/
// Author: github.com/punkfulw
// Time:
//      CustomStack, push, pop: O(1)
//      increment: O(k)
// Space: O(N)
class CustomStack {
public:
    vector<int> stk;
    int cnt = 0, mx;
    CustomStack(int maxSize) {
        stk.resize(maxSize, 0);
        mx = maxSize;
    }
    
    void push(int x) {
        if (cnt < mx)
            stk[cnt++] = x;
    }
    
    int pop() {
        if (cnt == 0)
            return -1;
        return stk[--cnt];
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(cnt, k); i++){
            stk[i] += val;
        }
    }
};
