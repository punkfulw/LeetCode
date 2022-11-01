// OJ: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        
        for (int i = 0; i < s.size();){
            string cur;
            for (int j = 0; j < k; ++j){
                if (i < s.size())
                    cur += s[i++];
                else
                    cur += fill;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
