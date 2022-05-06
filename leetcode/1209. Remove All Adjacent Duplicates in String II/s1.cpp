// OJ: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/1209.%20Remove%20All%20Adjacent%20Duplicates%20in%20String%20II/README.md
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stk;
        for (auto c: s)
        {
            if (stk.empty() || stk.back().first != c)
                stk.push_back({c, 1});
            else if (++stk.back().second == k)
                stk.pop_back();  
        }
        s = "";
        for (int i = 0; i < stk.size(); i++){
            string ss(stk[i].second, stk[i].first);
            s += ss;
        }           
        return s;
    }
};
