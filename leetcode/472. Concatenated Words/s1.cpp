// OJ: https://leetcode.com/problems/concatenated-words/
// Author: github.com/punkfulw
// Time: O(NW)
// Space: O(N) 
class Solution {
public:
    vector<string> ans;
    unordered_set<string> set;
    
    bool dfs(string &w, int idx, string cur, int cnt){
        if (idx == w.size()){
            if (cur.empty() && cnt > 1)
                return true;
            return false;
        }
        int ret = 0;
        cur += w[idx];
        if (set.find(cur) != set.end())
            ret |= dfs(w, idx + 1, "", cnt + 1);
        
        ret |= dfs(w, idx + 1, cur, cnt);
        return ret;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set = unordered_set<string> (words.begin(), words.end());
        
        for (auto w: words)
            if (dfs(w, 0, "", 0))
                ans.push_back(w);
        
        return ans;
    }
};
