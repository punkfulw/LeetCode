// OJ: https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkZeroOnes(string s) {
        int one = 0, zero = 0;
        int cnt1 = 0, cnt0 = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '1'){
                cnt0 = 0;
                cnt1++;
                one = max(one, cnt1);
            }
            else{
                cnt1 = 0;
                cnt0++;
                zero = max(zero, cnt0);
            }
        }
        return one > zero;        
    }
};
