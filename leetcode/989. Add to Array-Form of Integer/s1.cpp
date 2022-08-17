// OJ: https://leetcode.com/problems/add-to-array-form-of-integer/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        int carry = 0, i = 0, n = num.size();
        while (k || carry){
            int a = k % 10, b = i < n ? num[i] : 0;
            int newDig = (a + b + carry) % 10;
            carry = (carry + a + b) / 10;
            if (i < n)
                num[i] = newDig;
            else
                num.push_back(newDig);
            k /= 10;
            i++;
        }
        reverse(num.begin(), num.end());
        return num;
    }
};
