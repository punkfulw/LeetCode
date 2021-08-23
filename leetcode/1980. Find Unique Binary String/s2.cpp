// OJ: https://leetcode.com/problems/find-unique-binary-string/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/find-unique-binary-string/discuss/1418687/Detailed-Explanation-O(N)-Java-C%2B%2B-Python-short-concise-code-Cantor's-Diagonalization
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for (int i = 0; i < nums.size(); i++)
            ans += nums[i][i] == '0' ? '1' : '0';
        return ans;
    }
};
