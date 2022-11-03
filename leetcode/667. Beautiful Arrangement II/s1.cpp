// OJ: https://leetcode.com/problems/beautiful-arrangement-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int l = 1, r = n;
        
        while (k){
            if (k & 1)
                ans.push_back(l++);
            else
                ans.push_back(r--);
            k--;
        }
        
        while (l <= r)
            ans.push_back(l++);
        
        return ans;
    }
};
