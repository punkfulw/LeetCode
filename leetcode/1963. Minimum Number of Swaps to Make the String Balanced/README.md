# [1963. Minimum Number of Swaps to Make the String Balanced (Medium)](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/)

<p>You are given a <strong>0-indexed</strong> string <code>s</code> of <strong>even</strong> length <code>n</code>. The string consists of <strong>exactly</strong> <code>n / 2</code> opening brackets <code>'['</code> and <code>n / 2</code> closing brackets <code>']'</code>.</p>

<p>A string is called <strong>balanced</strong> if and only if:</p>

<ul>
	<li>It is the empty string, or</li>
	<li>It can be written as <code>AB</code>, where both <code>A</code> and <code>B</code> are <strong>balanced</strong> strings, or</li>
	<li>It can be written as <code>[C]</code>, where <code>C</code> is a <strong>balanced</strong> string.</li>
</ul>

<p>You may swap the brackets at <strong>any</strong> two indices <strong>any</strong> number of times.</p>

<p>Return <em>the <strong>minimum</strong> number of swaps to make </em><code>s</code> <em><strong>balanced</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "][]["
<strong>Output:</strong> 1
<strong>Explanation:</strong> You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "]]][[["
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][[]".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "[]"
<strong>Output:</strong> 0
<strong>Explanation:</strong> The string is already balanced.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == s.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>6</sup></code></li>
	<li><code>n</code> is even.</li>
	<li><code>s[i]</code> is either <code>'[' </code>or <code>']'</code>.</li>
	<li>The number of opening brackets <code>'['</code> equals <code>n / 2</code>, and the number of closing brackets <code>']'</code> equals <code>n / 2</code>.</li>
</ul>


**Similar Questions**:
* [Remove Invalid Parentheses (Hard)](https://leetcode.com/problems/remove-invalid-parentheses/)
* [Minimum Add to Make Parentheses Valid (Medium)](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)
* [Minimum Remove to Make Valid Parentheses (Medium)](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)
* [Minimum Insertions to Balance a Parentheses String (Medium)](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)

## Solution 1. stack


```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0;
        stack<char> stk;
        stk.push(s[0]);
        for (int i = 1; i < s.size(); i++){
            if (s[i] == '[')
                stk.push(s[i]);
            else {
                if (stk.empty())
                    stk.push(s[i]);
                if (stk.top() == '[')
                    stk.pop();
                else
                    stk.push(s[i]);
            }
        }
        cnt = stk.size()/2;
        return (cnt+1)/2;
    }
};
```
