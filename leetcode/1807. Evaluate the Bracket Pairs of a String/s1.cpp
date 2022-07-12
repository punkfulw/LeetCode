// OJ: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        string ans = "";
        for (auto &k: knowledge)
            mp[k[0]] = k[1];
        
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                int j = i + 1;
                string cur = "";
                while (s[j] != ')')
                    cur += s[j++];
                i = j;
                if (mp.find(cur) == mp.end())
                    ans += '?';
                else
                    ans += mp[cur];
            }
            else
                ans += s[i];
        }
        return ans;
    }
};
