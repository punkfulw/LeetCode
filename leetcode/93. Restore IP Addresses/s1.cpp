// OJ: https://leetcode.com/problems/restore-ip-addresses
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<string> ans;
    
    void dfs(int i, string cur, string &s, int k){
        if (k > 4)
            return;
        if (i == s.size() && k == 4){
            cur.pop_back();
            ans.push_back(cur);
            return;
        }
        for (int dig = 1; dig <= 3 && i + dig - 1 < s.size(); dig++){
            string newNum = s.substr(i, dig), newS = cur + newNum + ".";
            int num = stoi(newNum);
            if (num >= 0 && num <= 255 && !(dig > 1 && newNum[0] == '0'))
                dfs(i + dig, newS, s, k + 1);
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        string cur = "";
        dfs(0, cur, s, 0);
        return ans;
    }
};
