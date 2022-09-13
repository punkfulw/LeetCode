# [1525. Number of Good Ways to Split a String (Medium)](https://leetcode.com/problems/number-of-good-ways-to-split-a-string/)

<p>You are given a string <code>s</code>, a&nbsp;split is called <em>good</em>&nbsp;if you can split&nbsp;<code>s</code> into 2&nbsp;non-empty strings <code>p</code> and <code>q</code> where its concatenation is equal to <code>s</code> and the number of distinct letters in <code>p</code> and <code>q</code> are the same.</p>

<p>Return the number of <em>good</em> splits you can make in <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aacaba"
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 5 ways to split <code>"aacaba"</code> and 2 of them are good. 
("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abcd"
<strong>Output:</strong> 1
<strong>Explanation: </strong>Split the string as follows ("ab", "cd").
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aaaaa"
<strong>Output:</strong> 4
<strong>Explanation: </strong>All possible splits are good.</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "acbadbaada"
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>s</code> contains only lowercase English letters.</li>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool check(int (&left)[26], int (&right)[26]){
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < 26; i++){
            if (left[i]) cnt1++;
            if (right[i]) cnt2++;
        }
        return cnt1 == cnt2;
    }
    int numSplits(string s) {
        int left[26] = {}, right[26] = {}, n = s.size(), ans = 0;
        for (int i = 0; i < n; i++)
            right[s[i] - 'a']++;
        for (int i = 0; i < n - 1; i++){
            char c = s[i];
            right[c - 'a']--;
            left[c - 'a']++;
            ans += check(left, right);
        }
        return ans;
    }
};
```

