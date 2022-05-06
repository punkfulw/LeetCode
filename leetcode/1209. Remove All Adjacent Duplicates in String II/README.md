# [1209. Remove All Adjacent Duplicates in String II (Medium)](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)

<p>Given a string&nbsp;<code>s</code>, a <em>k</em>&nbsp;<em>duplicate removal</em>&nbsp;consists of choosing <code>k</code>&nbsp;adjacent and equal letters from&nbsp;<code>s</code> and removing&nbsp;them causing the left and the right side of the deleted substring to concatenate together.</p>

<p>We repeatedly make <code>k</code> duplicate removals on <code>s</code> until we no longer can.</p>

<p>Return the final string after all such duplicate removals have been made.</p>

<p>It is guaranteed that the answer is unique.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcd", k = 2
<strong>Output:</strong> "abcd"
<strong>Explanation: </strong>There's nothing to delete.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "deeedbbcccbdaa", k = 3
<strong>Output:</strong> "aa"
<strong>Explanation: 
</strong>First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "pbbcggttciiippooaais", k = 2
<strong>Output:</strong> "ps"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>2 &lt;= k &lt;= 10^4</code></li>
	<li><code>s</code> only contains lower case English letters.</li>
</ul>


**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Remove All Adjacent Duplicates In String (Easy)](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)

## Solution 1. Stack

```cpp
// OJ: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/1209.%20Remove%20All%20Adjacent%20Duplicates%20in%20String%20II/README.md
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stk;
        for (auto c: s)
        {
            if (stk.empty() || stk.back().first != c)
                stk.push_back({c, 1});
            else if (++stk.back().second == k)
                stk.pop_back();  
        }
        s = "";
        for (int i = 0; i < stk.size(); i++){
            string ss(stk[i].second, stk[i].first);
            s += ss;
        }           
        return s;
    }
};
```

## Solution 1. Stack -py

```python3
# OJ: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(N)
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stk = []
        for c in s:
            if len(stk) == 0 or stk[-1][0] != c:
                stk.append([c, 1])
            else:
                stk[-1][1] += 1
                if (stk[-1][1] == k):
                    stk.pop()
        return "".join(c * k for c, k in stk)
            
                
```
