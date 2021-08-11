// OJ: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
// Ref: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/339959/One-Pass-O(N)-Time-and-Space
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> s;
        int ans = 0;
        s.push(INT_MAX);
        
        for (int a: arr){
            while (s.top() <= a){
                int num = s.top();
                s.pop();
                ans += num * min(s.top(), a);
            }
            s.push(a);
        }
        int pre = s.top();
        s.pop();
        while (s.size() > 1){
            ans += pre * s.top();
            pre = s.top();
            s.pop();
        }
        return ans;
    }
};
