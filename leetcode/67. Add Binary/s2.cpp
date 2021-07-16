// OJ: https://leetcode.com/problems/add-binary/
// Author: github.com/punkfulw
// Time: O(A+B)
// Space: O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int n = a.size(), m = b.size();
        for (int i = 1; i <= max(n, m); i++){
            int x = 0, y = 0;
            if (i <= n)
                x = a[n-i] - '0';
            if (i <= m)
                y = b[m-i] - '0';
            switch(x + y + carry){
                case 0:
                    ans.insert(0, "0");
                    carry = 0;
                    break;
                case 1:
                    ans.insert(0, "1");
                    carry = 0;
                    break;
                case 2:
                    ans.insert(0, "0");
                    carry = 1;
                    break;
                case 3:
                    ans.insert(0, "1");
                    carry = 1;
                    break;
            }
        }
        if (carry)
            ans.insert(0, "1");
        return ans;
    }
};
