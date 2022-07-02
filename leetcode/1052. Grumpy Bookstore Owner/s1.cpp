// OJ: https://leetcode.com/problems/grumpy-bookstore-owner/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxSatisfied(vector<int>& cus, vector<int>& g, int min) {
        int n = g.size(), sum = 0, cover = 0, mx = 0;
        for (int i = 0; i < n; i++){
            sum += g[i] == 0 ? cus[i] : 0;
            cover += g[i] == 1 ? cus[i] : 0;
            if (i >= min)
                cover -= g[i - min] == 1 ? cus[i - min] : 0;
            mx = max(mx, cover);
        } 
        return sum + mx;
    }
};
