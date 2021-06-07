# [128. Longest Consecutive Sequence (Medium)](https://leetcode.com/problems/longest-consecutive-sequence/)

<p>Given an unsorted array of integers <code>nums</code>, return <em>the length of the longest consecutive elements sequence.</em></p>

<p>You must write an algorithm that runs in <code>O(n)</code> time.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums = [100,4,200,1,3,2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> nums = [0,3,7,2,5,8,4,6,0,1]
<strong>Output:</strong> 9
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>0 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
  <li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Union Find](https://leetcode.com/tag/union-find/)

**Similar Questions**:
* [Binary Tree Longest Consecutive Sequence (Medium)](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/)

## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/longest-consecutive-sequence/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/longest-consecutive-sequence/discuss/41060/A-simple-C%2B%2Bsolution-using-unordered_set.And-simple-consideration-about-this-problem
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        
        int ans = 1;
        for (int i: nums){
            if (s.find(i) == s.end()) continue;
            s.erase(i);
            int pre = i-1, next = i+1;
            while (s.find(pre) != s.end()) s.erase(pre--);
            while (s.find(next) != s.end()) s.erase(next++);
            ans = max(ans, next-pre-1);
        }
        
        return ans;
    }
};
```
