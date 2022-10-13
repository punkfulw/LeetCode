# [394. Decode String (Medium)](https://leetcode.com/problems/decode-string/)

<p>Given an encoded string, return its decoded string.</p>

<p>The encoding rule is: <code>k[encoded_string]</code>, where the <code>encoded_string</code> inside the square brackets is being repeated exactly <code>k</code> times. Note that <code>k</code> is guaranteed to be a positive integer.</p>

<p>You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.</p>

<p>Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, <code>k</code>. For example, there won't be input like <code>3a</code> or <code>2[4]</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s = "3[a]2[bc]"
<strong>Output:</strong> "aaabcbc"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = "3[a2[c]]"
<strong>Output:</strong> "accaccacc"
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> s = "2[abc]3[cd]ef"
<strong>Output:</strong> "abcabccdcdcdef"
</pre><p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> s = "abc3[cd]xyz"
<strong>Output:</strong> "abccdcdcdxyz"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 30</code></li>
	<li><code>s</code> consists of lowercase English letters, digits, and square brackets <code>'[]'</code>.</li>
	<li><code>s</code> is guaranteed to be <strong>a valid</strong> input.</li>
	<li>All the integers in <code>s</code> are in the range <code>[1, 300]</code>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg), [Amazon](https://leetcode.com/company/amazon), [Snapchat](https://leetcode.com/company/snapchat), [Cisco](https://leetcode.com/company/cisco), [Apple](https://leetcode.com/company/apple), [Uber](https://leetcode.com/company/uber), [tiktok](https://leetcode.com/company/tiktok), [Microsoft](https://leetcode.com/company/microsoft), [Oracle](https://leetcode.com/company/oracle), [Facebook](https://leetcode.com/company/facebook), [SAP](https://leetcode.com/company/sap), [Jump Trading](https://leetcode.com/company/jump-trading)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Encode String with Shortest Length (Hard)](https://leetcode.com/problems/encode-string-with-shortest-length/)
* [Number of Atoms (Hard)](https://leetcode.com/problems/number-of-atoms/)
* [Brace Expansion (Medium)](https://leetcode.com/problems/brace-expansion/)

## Solution 1. Stack

```cpp
// OJ: https://leetcode.com/problems/decode-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string ans = "";
        stack<string> stk;
        
        for (int i = 0; i < n; i++){
            if (s[i] == ']'){
                string inside = "", mul;
                while (stk.top() != "["){
                    inside = stk.top() + inside;
                    stk.pop();
                }
                stk.pop();
                mul = stk.top();
                stk.pop();
                string newS = "";
                for (int i = 0; i < stoi(mul); i++)
                    newS += inside;
                stk.push(newS);
            }
            else if (isdigit(s[i])){
                string dig = "";
                while (isdigit(s[i])){
                    dig += s[i++];
                }
                i--;
                stk.push(dig);
            }
            else{
                stk.push(string(1, s[i]));
            }
        }
        
        while (!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        
        return ans;
    }
};
```

## Solution 2. Recursion

```cpp
// OJ: https://leetcode.com/problems/decode-string/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/394.%20Decode%20String/README.md
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string sol(string &s, int &i){
        string ans = "";
        while (i < s.size() && s[i] != ']'){
            if (isdigit(s[i])){
                int mul = 0;
                while (isdigit(s[i]))
                    mul = 10 * mul + (s[i++] - '0');
                i++;
                string tail = sol(s, i);
                i++;
                for (int i = 0; i < mul; i++)
                    ans += tail;
            }
            else
                ans += s[i++];
        }
        return ans;
    }
    
    string decodeString(string s) {
        int i = 0;
        return sol(s, i);
    }
};
```
