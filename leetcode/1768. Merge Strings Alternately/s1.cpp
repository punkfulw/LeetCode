// OJ: https://leetcode.com/problems/merge-strings-alternately/
// Author: github.com/punkfulw
// Time: O(M + N)
// Space: O(M + N)
class Solution {
public:
    string mergeAlternately(string A, string B) {
        int i {};
        string ans;
        while (i < A.size() || i < B.size()){
            if (i < A.size())
                ans.push_back(A[i]);
            if (i < B.size())
                ans.push_back(B[i]);
            i++;
        }
        return ans;
    }
};
