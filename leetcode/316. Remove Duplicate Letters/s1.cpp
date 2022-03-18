// OJ: https://leetcode.com/problems/remove-duplicate-letters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int mp[256];
        bool visited[256];
        string ans = "0";
        
        for (auto c: s)
            mp[c]++;
        
        for (auto c: s)
        {
            mp[c]--;
            if (visited[c])
                continue;
            while (ans.back() > c && mp[ans.back()] && !visited[c])
            {
                visited[ans.back()] = false;
                ans.pop_back();
            }
            ans += c;
            visited[c] = true;
        }
        return ans.substr(1);
    }
};
