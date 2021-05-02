// OJ: https://leetcode.com/problems/shortest-distance-to-a-character/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size());
        int pos = -s.size();
        
        for (int i = 0; i < s.size(); i++){
            if (s[i] == c){
                ans[i] = 0;
                pos = i;
            }
            else
                ans[i] = i - pos; 
        }
        pos = 2 * s.size();
        for (int i = s.size()-1; i >= 0; i--){
            if (s[i] == c)
                pos = i;
            else
                ans[i] = min(pos - i, ans[i]);  
        }
        return ans;
    }
};
