# [14. Longest Common Prefix (Easy)](https://leetcode.com/problems/longest-common-prefix/)

<p>Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string <code>""</code>.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> strs = ["flower","flow","flight"]
<strong>Output:</strong> "fl"
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> strs = ["dog","racecar","car"]
<strong>Output:</strong> ""
<strong>Explanation:</strong> There is no common prefix among the input strings.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= strs.length &lt;= 200</code></li>
  <li><code>0 &lt;= strs[i].length &lt;= 200</code></li>
  <li><code>strs[i]</code> consists of only lower-case English letters.</li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [3Sum (Medium)](https://leetcode.com/problems/3sum/)
* [4Sum (Medium)](https://leetcode.com/problems/4sum/)
* [Two Sum II - Input array is sorted (Easy)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
* [Two Sum III - Data structure design (Easy)](https://leetcode.com/problems/two-sum-iii-data-structure-design/)
* [Subarray Sum Equals K (Medium)](https://leetcode.com/problems/subarray-sum-equals-k/)
* [Two Sum IV - Input is a BST (Easy)](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
* [Two Sum Less Than K (Easy)](https://leetcode.com/problems/two-sum-less-than-k/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-common-prefix/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = *min_element(strs.begin(), strs.end());
        int n = pre.size();
        for (int i = 0; i < strs.size(); i++){
            for (int j = 0; j < n; j++){
                if (pre[j] != strs[i][j] && j == 0)
                    return "";
                if (pre[j] != strs[i][j])
                        pre = pre.substr(0, j);
            }
        }
        return pre;
    }
};
```

