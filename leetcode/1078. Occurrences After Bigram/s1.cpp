// OJ: https://leetcode.com/problems/occurrences-after-bigram/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        stringstream ss(text);
        string pre2, pre;
        string cur;
        while (ss >> cur){
            if (pre2 == first && pre == second)
                ans.push_back(cur);
            pre2 = pre;
            pre = cur;
        }
        return ans;
    }
};
