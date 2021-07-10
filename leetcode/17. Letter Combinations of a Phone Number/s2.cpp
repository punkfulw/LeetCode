// OJ: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author: github.com/punkfulw
// Time: O(4^N * N)
// Space: O(4^N * N)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> mp = {{'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}}, 
                                                {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}}, 
                                                {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
                                                {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};
        vector<string> ans;
        if (digits.empty())
            return ans;
        ans.push_back("");
        for (int i = 0; i < digits.size(); i++){
            vector<string> cur;
            for (auto c: mp[digits[i]]){
                for (auto pre: ans){
                    pre.push_back(c);
                    cur.push_back(pre);
                }
            }
            ans = cur;
        }
        return ans;
    }
    
};
