// OJ: https://leetcode.com/problems/largest-substring-between-two-equal-characters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size(), ans = -1;
        vector<vector<int>> rec(26, vector<int> (2, -1));
        for (int i = 0; i < n; i++){
            int c = s[i] - 'a';
            if (rec[c][0] != -1)
                rec[c][1] = i;
            else
                rec[c][0] = i;
        }
        
        for (int i = 0; i < 26; i++){
            if (rec[i][1] == -1)
                continue;
            ans = max(ans, rec[i][1] - rec[i][0] - 1);
        }
        return ans;
    }
};
