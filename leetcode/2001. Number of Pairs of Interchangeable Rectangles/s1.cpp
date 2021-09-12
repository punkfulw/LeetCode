// OJ: https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rec) {
        long long ans = 0;
        unordered_map<double, int> mp;
        for (auto r: rec)
            mp[(double)r[0] / r[1]]++;
        for (auto p: mp){
            long long n = p.second;
            ans += n * (n - 1) / 2;
        }
        return ans;
    }
};
