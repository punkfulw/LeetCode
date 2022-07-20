// OJ: https://leetcode.com/problems/number-of-matching-subsequences/
// Author: github.com/punkfulw
// Time: O(S + NWlogS)
// Space: O(S)
class Solution {
public:
    int solve(vector<vector<int>> &rec, string w){
        int pre = -1;
        vector<int> idx(26, 0);
        for (auto c: w){
            int pos = c - 'a';
            auto it = upper_bound(rec[pos].begin() + idx[pos], rec[pos].end(), pre);
            if (it == rec[pos].end())
                return false;
            pre = *it;
            idx[pos] = it - rec[pos].begin() + 1;
        }
        return true;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0, n = s.size(), m = words.size();
        vector<vector<int>> rec(26); 
        for (int i = 0; i < n; i++)
            rec[s[i] - 'a'].push_back(i);      
        for (auto w: words)
            ans += solve(rec, w);        
        return ans;
    }
};
