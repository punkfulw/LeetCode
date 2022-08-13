// OJ: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Author: github.com/punkfulw
// Time: O(MNL)
// Space: O(ML)
class Solution {
public:
    int len, cnt, n;
    vector<int> ans;
    unordered_map<string, int> mp;
        
    void dfs(int &start, int i, string &s, int cnt){
        if (cnt == 0){
            ans.push_back(start);
            return;
        }
        string cur = s.substr(i, len);
        if (mp[cur]){
            mp[cur]--;
            dfs(start, i + len, s, cnt - 1);
            mp[cur]++;
        }
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        len = words[0].size(), cnt = words.size(), n = s.size();
        for (auto &w: words)                        
            mp[w]++;
        for (int i = 0; i < s.size() - cnt + 1; i++) 
            dfs(i, i, s, cnt);                        
        return ans;
    }
};
