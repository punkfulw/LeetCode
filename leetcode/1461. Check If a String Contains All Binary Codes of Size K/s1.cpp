// OJ: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(2^K)
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        long long fac = pow(2, k), n = s.size();
        if (fac > n - k + 1)
            return false;
        unordered_set<string> st;
        for (int i = 0; i < n - k + 1; i++){
            string cur = s.substr(i, k);
            st.insert(cur);
        }
        return st.size() == fac;
    }
};
