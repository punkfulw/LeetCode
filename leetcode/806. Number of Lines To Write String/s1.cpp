// OJ: https://leetcode.com/problems/number-of-lines-to-write-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int row = 1, w = 0;
        
        for (auto c: s){
            int cur = widths[c-'a'];
            if (w + cur > 100){
                row++;
                w = cur;
            }
            else
                w += cur;
        }
        return {row, w};
    }
};
