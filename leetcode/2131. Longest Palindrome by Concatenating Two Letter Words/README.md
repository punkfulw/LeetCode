# [2131. Longest Palindrome by Concatenating Two Letter Words (Medium)](https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/)

<p>You are given an array of strings <code>words</code>. Each element of <code>words</code> consists of <strong>two</strong> lowercase English letters.</p>

<p>Create the <strong>longest possible palindrome</strong> by selecting some elements from <code>words</code> and concatenating them in <strong>any order</strong>. Each element can be selected <strong>at most once</strong>.</p>

<p>Return <em>the <strong>length</strong> of the longest palindrome that you can create</em>. If it is impossible to create any palindrome, return <code>0</code>.</p>

<p>A <strong>palindrome</strong> is a string that reads the same forward and backward.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["lc","cl","gg"]
<strong>Output:</strong> 6
<strong>Explanation:</strong> One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["ab","ty","yt","lc","cl","ab"]
<strong>Output:</strong> 8
<strong>Explanation:</strong> One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> words = ["cc","ll","xx"]
<strong>Output:</strong> 2
<strong>Explanation:</strong> One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>5</sup></code></li>
	<li><code>words[i].length == 2</code></li>
	<li><code>words[i]</code> consists of lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Palindrome Pairs (Hard)](https://leetcode.com/problems/palindrome-pairs/)
* [Longest Palindrome (Easy)](https://leetcode.com/problems/longest-palindrome/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;  //word -> cnt;

        for(auto &word: words)
            mp[word]++;
        
        int flag = 0, ans = 0;
        for (auto &p: mp){
            string s = p.first, rev = string(s.rbegin(), s.rend());
            int a = p.second, b = mp.find(rev) == mp.end() ? 0 : mp[rev];
            if (s[0] == s[1]){
                if (!flag && a & 1)
                    flag = 1;
                ans += (a / 2 * 4);
            }
            else {
                ans += min(a, b) * 4;
                mp.erase(rev);
            }
        }
        return flag ? ans + 2 : ans;
    }
};
```
