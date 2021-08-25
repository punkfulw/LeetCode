# [537. Complex Number Multiplication (Medium)](https://leetcode.com/problems/complex-number-multiplication/)

<p>
Given two strings representing two <a href="https://en.wikipedia.org/wiki/Complex_number">complex numbers</a>.</p>

<p>
You need to return a string representing their multiplication. Note i<sup>2</sup> = -1 according to the definition.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> "1+1i", "1+1i"
<b>Output:</b> "0+2i"
<b>Explanation:</b> (1 + i) * (1 + i) = 1 + i<sup>2</sup> + 2 * i = 2i, and you need convert it to the form of 0+2i.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> "1+-1i", "1+-1i"
<b>Output:</b> "0+-2i"
<b>Explanation:</b> (1 - i) * (1 - i) = 1 + i<sup>2</sup> - 2 * i = -2i, and you need convert it to the form of 0+-2i.
</pre>
<p></p>

<p><b>Note:</b>
</p><ol>
<li>The input strings will not have extra blank.</li>
<li>The input strings will be given in the form of <b>a+bi</b>, where the integer <b>a</b> and <b>b</b> will both belong to the range of [-100, 100]. And <b>the output should be also in this form</b>.</li>
</ol>
<p></p>

## Solution 1.

```cpp
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
```
