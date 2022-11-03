// OJ: https://leetcode.com/problems/beautiful-arrangement-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int l = 1, r = k + 1;
        
        while (l <= r){
            ans.push_back(l++);
            if (l <= r)
                ans.push_back(r--);
        }
        
        for (int i = k + 2; i <= n; ++i)
            ans.push_back(i);
        
        return ans;
    }
};
