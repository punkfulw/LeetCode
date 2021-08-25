// OJ: https://leetcode.com/problems/complex-number-multiplication/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int r1 = 0, r2 = 0, i1 = 0, i2 = 0;
        convert(num1, r1, i1);
        convert(num2, r2, i2);
        string ans;
        int r = (r1 * r2) - (i1 * i2);
        int i = r1 * i2 + r2 * i1;
        ans += to_string(r) + "+" + to_string(i) + "i";
        
        return ans;
    }
    void convert(string s, int& real, int& ima){
        int len = s.size(), i = 0;
        while (i < len && s[i] != '+')
            i++;
        real = stoi(s.substr(0, i));
        ima = stoi(s.substr(i + 1));
        return;
    }
};
