// OJ: https://leetcode.com/problems/word-break-ii/
// Author: github.com/punkfulw
// Time: O(N!)
// Space: O(N + D)
class Solution {
public:
    vector<string> ans;
    int n;
    void dfs(int i, string s, string &ori, unordered_set<string> &dic){
        if (i == n){
            s.pop_back();
            ans.push_back(s);
            return;
        }
        for (int j = i; j < min(i + 10, n); j++){
            string cur = ori.substr(i, j - i + 1);
            if (dic.find(cur) != dic.end()){
                string new_s = s + cur + " ";
                dfs(j + 1, new_s, ori, dic);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        n = s.size();
        dfs(0, "", s, dic);
        return ans;
    }
};
