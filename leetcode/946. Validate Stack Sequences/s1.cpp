// OJ: https://leetcode.com/problems/validate-stack-sequences/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int q = 0;
        for (auto x: pushed){
            s.push(x);
            while (!s.empty() && s.top() == popped[q]){
                s.pop();
                q++;
            }
        }
        return s.size() == 0;
    }
};
