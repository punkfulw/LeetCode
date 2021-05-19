// OJ: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string removeDuplicates(string s) {
        string ans = s;
        
        for (int i = 0; i < s.size()-1;){
            if (ans[i] == ans[i+1]){
                ans.erase(i, 2);
                if (i > 0)
                    i--;
            }
            else
                i++;
        }
        return ans;
    }
};
