// OJ: https://leetcode.com/problems/positions-of-large-groups/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int i = 0, j = 0;
        vector<vector<int>> ans;
        s.push_back('A');
        for (; i < s.size(); i = j + 1, j = i){
            while (s[j+1] == s[i])
                j++;
            if (j - i + 1 >= 3)
                ans.push_back({i, j});
        }
        return ans;
    }
};
