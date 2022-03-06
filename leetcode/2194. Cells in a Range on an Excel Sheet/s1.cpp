// OJ: https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/
// Author: github.com/punkfulw
// Time: O(1) 
// Space: O(1) 
class Solution {
public:
    vector<string> cellsInRange(string s) {
        char start = s[0], end = s[3];
        int s1 = s[1], e1 = s[4];
        vector<string> ans;
        for (char c = start; c <= end; c++)
        {
            for (int i = s1; i <= e1; i++)
            {
                string cur = string(1, c) + string(1, i);
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
