# [830. Positions of Large Groups (Easy)](https://leetcode.com/problems/positions-of-large-groups/)

<p>In a string&nbsp;<code>S</code>&nbsp;of lowercase letters, these letters form consecutive groups of the same character.</p>

<p>For example, a string like <code>S = "abbxxxxzyy"</code> has the groups <code>"a"</code>, <code>"bb"</code>, <code>"xxxx"</code>, <code>"z"</code> and&nbsp;<code>"yy"</code>.</p>

<p>Call a group <em>large</em> if it has 3 or more characters.&nbsp; We would like the starting and ending positions of every large group.</p>

<p>The final answer should be in lexicographic order.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>"abbxxxxzzy"
<strong>Output: </strong>[[3,6]]
<strong>Explanation</strong>: <code>"xxxx" is the single </code>large group with starting  3 and ending positions 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>"abc"
<strong>Output: </strong>[]
<strong>Explanation</strong>: We have "a","b" and "c" but no large group.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>"abcdddeeeeaabbbcd"
<strong>Output: </strong>[[3,5],[6,9],[12,14]]</pre>

<p>&nbsp;</p>

<p><strong>Note:&nbsp;</strong>&nbsp;<code>1 &lt;= S.length &lt;= 1000</code></p>


**Companies**:  
[Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/positions-of-large-groups/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int i = 0, j = 0;
        vector<vector<int>> ans;
        s.push_back('A');
        for (; i < s.size(); i = j + 1, j = i){
            while (s[j+1] == s[i])
                j++;
            if (j - i + 1 >= 3)
                ans.push_back({i, j});
        }
        return ans;
    }
};
```
