// OJ: https://leetcode.com/problems/monotone-increasing-digits/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        
        for (int i = s.size() - 1; i >= 1; i--){
            if (s[i] >= s[i - 1])
                continue;
            else {
                s[i - 1]--;
                for (int j = i; j < s.size(); j++)
                    s[j] = '9';
            }
        }
        return stoi(s);
    }
};
