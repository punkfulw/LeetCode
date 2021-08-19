# [921. Minimum Add to Make Parentheses Valid (Medium)](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)

<p>Given a string&nbsp;<code>S</code> of <code>'('</code> and <code>')'</code> parentheses, we add the minimum number of parentheses ( <code>'('</code> or <code>')'</code>, and in any positions ) so that the resulting parentheses string is valid.</p>

<p>Formally, a parentheses string is valid if and only if:</p>

<ul>
	<li>It is the empty string, or</li>
	<li>It can be written as <code>AB</code>&nbsp;(<code>A</code> concatenated with <code>B</code>), where <code>A</code> and <code>B</code> are valid strings, or</li>
	<li>It can be written as <code>(A)</code>, where <code>A</code> is a valid string.</li>
</ul>

<p>Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"())"</span>
<strong>Output: </strong><span id="example-output-1">1</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">"((("</span>
<strong>Output: </strong><span id="example-output-2">3</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">"()"</span>
<strong>Output: </strong><span id="example-output-3">0</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong><span id="example-input-4-1">"()))(("</span>
<strong>Output: </strong><span id="example-output-4">4</span></pre>

<p>&nbsp;</p>
</div>
</div>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li><code>S.length &lt;= 1000</code></li>
	<li><code>S</code> only consists of <code>'('</code> and <code>')'</code> characters.</li>
</ol>

<div>
<div>
<div>
<div>&nbsp;</div>
</div>
</div>
</div>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [ServiceNow](https://leetcode.com/company/servicenow)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for (auto c: s){
            if (c == '(')
                stk.push(c);
            else{
                if (stk.empty() || stk.top() != '(')
                    stk.push(c);
                else
                    stk.pop();
            }
        }
        return stk.size();
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Author: github.com/punkfulw
// Ref: https://github.com/punkfulw/LeetCode-1/edit/master/leetcode/921.%20Minimum%20Add%20to%20Make%20Parentheses%20Valid/README.md
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int left = 0, invalidright = 0;
        for (auto c: s){
            if (c == '(') left++;
            else{
                if (!left)
                    invalidright++;
                else
                    left--;
            }
        }
        return left + invalidright;
    }
};
```
