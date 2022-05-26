// OJ: https://leetcode.com/problems/3sum-closest/
// Author: github.com/punkfulw
// Time: O(NS)
// Space: O(1)
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res = 0;
        for (auto& w : words)
            res += s.find(w) == 0;
        return res; 
    }
};
