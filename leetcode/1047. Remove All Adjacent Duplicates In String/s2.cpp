// OJ: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        
        for (auto c: s){
            if (c == ans.back())
                ans.pop_back();
            else
                ans.push_back(c);
        }
        return ans;
    }
};
