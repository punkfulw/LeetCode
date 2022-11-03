// OJ: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;  //word -> cnt;

        for(auto &word: words)
            mp[word]++;
        
        int flag = 0, ans = 0;
        for (auto &p: mp){
            string s = p.first, rev = string(s.rbegin(), s.rend());
            int a = p.second, b = mp.find(rev) == mp.end() ? 0 : mp[rev];
            if (s[0] == s[1]){
                if (!flag && a & 1)
                    flag = 1;
                ans += (a / 2 * 4);
            }
            else {
                ans += min(a, b) * 4;
                mp.erase(rev);
            }
        }
        return flag ? ans + 2 : ans;
    }
};
