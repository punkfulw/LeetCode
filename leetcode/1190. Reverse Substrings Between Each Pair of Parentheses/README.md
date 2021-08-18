# [1190. Reverse Substrings Between Each Pair of Parentheses (Medium)](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/)

<p>Given a string <code>s</code> that consists of lower case English letters and brackets.&nbsp;</p>

<p>Reverse the strings&nbsp;in each&nbsp;pair of matching parentheses, starting&nbsp;from the innermost one.</p>

<p>Your result should <strong>not</strong> contain any bracket.</p>

<p>&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "(abcd)"
<strong>Output:</strong> "dcba"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "(u(love)i)"
<strong>Output:</strong> "iloveu"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "(ed(et(oc))el)"
<strong>Output:</strong> "leetcode"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "a(bcdefghijkl(mno)p)q"
<strong>Output:</strong> "apmnolkjihgfedcbq"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> only contains lower case English characters and parentheses.</li>
	<li>It's guaranteed that all parentheses are balanced.</li>
</ul>


**Companies**:  
[Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/)

## Solution 1. Recursive


```cpp
// OJ: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    string reverseParentheses(string s) {
        int index = 0;
        return recur(s, index);
    }
    string recur(string s, int& index){
        string ans;
        int n = s.size();
        while (index < n){
            if (s[index] == '('){
                string mid = recur(s, ++index);
                reverse(mid.begin(), mid.end());
                ans += mid;
            }
            else if (s[index] == ')')
                break;
            else
                ans += s[index];
            index++;
        }
        return ans;
    }
};
```

## Solution 2. stack


```cpp
// OJ: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        string ans;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(')
                stk.push(i);
            else if (s[i] == ')'){
                int top = stk.top();
                reverse(s.begin() + top, s.begin() + i);
                stk.pop();
            }
        }
        for (auto c: s)
            if (c != '(' && c != ')')
                ans += c;
        return ans;
    }
};
```

