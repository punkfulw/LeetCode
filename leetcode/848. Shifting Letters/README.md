# [848. Shifting Letters (Medium)](https://leetcode.com/problems/shifting-letters/)

<p>You are given a string s of lowercase English letters and an integer array shifts of the same length.</p>

<p>Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').</p>

<il>
	<li>For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.</li>
</il>

<p></p>

<p>Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.</p>

<p>Return the final string after all such shifts to s are applied.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>s = "abc", shifts = [3,5,9]
<strong>Output: </strong>"rpl"
<strong>Explanation: </strong>
We start with "abc".
After shifting the first 1 letters of S by 3, we have "dbc".
After shifting the first 2 letters of S by 5, we have "igc".
After shifting the first 3 letters of S by 9, we have "rpl", the answer.
</pre>

<p><strong>Note:</strong></p>

<il>
	<li><code>1 &lt;= s.length = shifts.length &lt;= 20000</code></li>
	<li><code>0 &lt;= shifts[i] &lt;= 10<sup>9</sup></code></li>
</il>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Replace All Digits with Characters (Easy)](https://leetcode.com/problems/replace-all-digits-with-characters/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/shifting-letters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string shiftingLetters(string s, vector<int>& nums) {
        int shift = 0;
        for (int i = s.size()-1; i >= 0; i--){
            shift = (nums[i] + shift) % 26;
            s[i] = (s[i] - 'a' + shift) % 26 + 'a';
        }
        return s;
    }
};
```
