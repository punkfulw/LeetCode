// OJ: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = s.size() <= 1 ? s.size() : 1;
        queue<char> q;
        map<char, int> mp;
        q.push(s[0]);
        mp[s[0]] = 1;
        
        for (int i = 1; i < s.size(); i++){
            char c = s[i];
            if (mp[c] == 0)
                mp[c] = 1;
            else{
                while(q.front() != c){
                    mp[q.front()] = 0;
                    q.pop();
                }
                q.pop();
            }
            q.push(c);
            ans = max(ans, int(q.size()));
        }
        return ans;
    }
};
