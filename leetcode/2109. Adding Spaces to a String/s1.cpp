// OJ: https://leetcode.com/problems/adding-spaces-to-a-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N) 
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int idx = 0;
        for (int i = 0; i < s.size(); i++){ 
            if (idx == spaces.size() || i < spaces[idx])
                ans += s[i];
            else{
                ans += ' ';
                ans += s[i]; 
                idx++;
            }
        }
        return ans;
    }
};
