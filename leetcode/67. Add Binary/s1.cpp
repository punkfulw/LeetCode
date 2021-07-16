// OJ: https://leetcode.com/problems/add-binary/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/add-binary/discuss/24475/Short-code-by-c%2B%2B
// Time: O(A+B)
// Space: O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        string ans;
        int i = a.size()-1, j = b.size()-1;
        while (i >= 0 || j >= 0 || c){
            c += i >= 0 ? (a[i--] - '0') : 0;
            c += j >= 0 ? (b[j--] - '0') : 0;
            ans += char(c % 2 + '0');
            c /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
