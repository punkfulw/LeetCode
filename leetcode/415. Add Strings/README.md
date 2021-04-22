# [415. Add Strings (Easy)](https://leetcode.com/problems/add-strings/)

<p>Given two non-negative integers <code>num1</code> and <code>num2</code> represented as string, return the sum of <code>num1</code> and <code>num2</code>.</p>

<p><b>Note:</b>
</p><ol>
<li>The length of both <code>num1</code> and <code>num2</code> is &lt; 5100.</li>
<li>Both <code>num1</code> and <code>num2</code> contains only digits <code>0-9</code>.</li>
<li>Both <code>num1</code> and <code>num2</code> does not contain any leading zero.</li>
<li>You <b>must not use any built-in BigInteger library</b> or <b>convert the inputs to integer</b> directly.</li>
</ol>
<p></p>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Add Two Numbers (Medium)](https://leetcode.com/problems/add-two-numbers/)
* [Multiply Strings (Medium)](https://leetcode.com/problems/multiply-strings/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/add-strings/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans {};
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry {};
        
        while (i >= 0 || j >= 0 || carry){
            int sum {};
            if (i >= 0){
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0){
                sum += num2[j] - '0';
                j--;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum + '0');
         }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
