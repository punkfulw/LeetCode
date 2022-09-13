# [2182. Construct String With Repeat Limit (Medium)](https://leetcode.com/problems/construct-string-with-repeat-limit/)

<p>You are given a string <code>s</code> and an integer <code>repeatLimit</code>. Construct a new string <code>repeatLimitedString</code> using the characters of <code>s</code> such that no letter appears <strong>more than</strong> <code>repeatLimit</code> times <strong>in a row</strong>. You do <strong>not</strong> have to use all characters from <code>s</code>.</p>

<p>Return <em>the <strong>lexicographically largest</strong> </em><code>repeatLimitedString</code> <em>possible</em>.</p>

<p>A string <code>a</code> is <strong>lexicographically larger</strong> than a string <code>b</code> if in the first position where <code>a</code> and <code>b</code> differ, string <code>a</code> has a letter that appears later in the alphabet than the corresponding letter in <code>b</code>. If the first <code>min(a.length, b.length)</code> characters do not differ, then the longer string is the lexicographically larger one.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "cczazcc", repeatLimit = 3
<strong>Output:</strong> "zzcccac"
<strong>Explanation:</strong> We use all of the characters from s to construct the repeatLimitedString "zzcccac".
The letter 'a' appears at most 1 time in a row.
The letter 'c' appears at most 3 times in a row.
The letter 'z' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aababab", repeatLimit = 2
<strong>Output:</strong> "bbabaa"
<strong>Explanation:</strong> We use only some of the characters from s to construct the repeatLimitedString "bbabaa". 
The letter 'a' appears at most 2 times in a row.
The letter 'b' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= repeatLimit &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


**Similar Questions**:
* [Rearrange String k Distance Apart (Hard)](https://leetcode.com/problems/rearrange-string-k-distance-apart/)

## Solution 1. PQ


```cpp
// OJ: https://leetcode.com/problems/construct-string-with-repeat-limit/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        int cnt[26] = {};
        string ans;
        for (char c : s) cnt[c - 'a']++;
        while (true) {
            int i = 25;
            bool onlyOne = false;
            for (; i >= 0; --i) {
                if (ans.size() && i == ans.back() - 'a' && cnt[i]) { // the character of our last batch still has some count left, so we only insert a single character in this batch
                    onlyOne = true;
                    continue;
                }
                if (cnt[i]) break; // found a character with positive count, fill with this character
            }
            if (i == -1) break; // no more characters to fill, break;
            int fill = onlyOne ? 1 : min(cnt[i], limit);
            cnt[i] -= fill;
            while (fill--) ans += 'a' + i;
        }
        return ans;
    }
};
```


## Solution 1. CountSort


```cpp
// OJ: https://leetcode.com/problems/construct-string-with-repeat-limit/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/2182.%20Construct%20String%20With%20Repeat%20Limit/README.md
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int cnt[26] = {};
        
        for (auto c: s)
            cnt[c - 'a']++;
        string ans = "";
        
        while (true){
            int i = 25, onlyOne = 0;
            
            for (; i >= 0; i--){
                if (ans.size() && ans.back() == i + 'a' && cnt[i]){
                    onlyOne = 1;
                    continue;
                }
                if (cnt[i])
                    break;
            }
            if (i == -1)
                break;
            int mn = onlyOne ? 1 : min(repeatLimit, cnt[i]);
            ans += string(mn, (i + 'a'));
            cnt[i] -= mn;
        }
        return ans;
    }
};
```
## Discuss

https://leetcode.com/problems/construct-string-with-repeat-limit/discuss/1784718
