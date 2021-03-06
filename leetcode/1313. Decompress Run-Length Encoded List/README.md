# [1313. Decompress Run-Length Encoded List (Easy)](https://leetcode.com/problems/decompress-run-length-encoded-list/)

<p>We are given a list <code>nums</code> of integers representing a list compressed with run-length encoding.</p>

<p>Consider each adjacent pair&nbsp;of elements <code>[a, b] = [nums[2*i], nums[2*i+1]]</code>&nbsp;(with <code>i &gt;= 0</code>).&nbsp; For each such pair, there are <code>a</code> elements with value <code>b</code> in the decompressed list.</p>

<p>Return the decompressed list.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> [2,4,4,4]
<strong>Explanation:</strong> The first pair [1,2] means we have freq = 1 and val = 2 so we generate the array [2].
The second pair [3,4] means we have freq = 3 and val = 4 so we generate [4,4,4].
At the end the concatenation [2] + [4,4,4,4] is [2,4,4,4].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>nums.length % 2 == 0</code></li>
	<li><code><font face="monospace">1 &lt;= nums[i] &lt;= 100</font></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [String Compression (Easy)](https://leetcode.com/problems/string-compression/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/decompress-run-length-encoded-list/
// Author: github.com/punkfulw
// Time: O(N) where N is the length of the output array.
// Space: O(1)
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans {};
        int size = nums.size();
        for (int i = 0; i < size; i+=2){
            for (int j = 0; j < nums.at(i); j++){
                int p = nums.at(i+1);
                ans.push_back(p);
            }
        }
        return ans;
    }
};
```
