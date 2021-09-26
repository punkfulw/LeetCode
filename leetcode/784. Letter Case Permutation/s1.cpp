// OJ: https://leetcode.com/problems/letter-case-permutation/
// Author: github.com/punkfulw
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        perm(s, 0, n);
        return ans;
    }
    
    void perm(string cur, int start, int n){
        ans.push_back(cur);
        if (start == n)
            return;
        for (int i = start; i < n; i++){
            if (isalpha(cur[i])){
                cur[i] ^= 32;
                perm(cur, i+1, n);
                cur[i] ^= 32;
            }
        }
    }
};
