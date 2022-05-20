# [1630. Arithmetic Subarrays (Medium)](https://leetcode.com/problems/arithmetic-subarrays/)

<p>A sequence of numbers is called <b>arithmetic</b> if it consists of at least two elements, and the difference between every two consecutive elements is the same. 
  More formally, a sequence s is arithmetic if and only if <code>s[i+1] - s[i] == s[1] - s[0]</code> for all valid <code>i</code>.</p>

<p>For example, these are <b>arithmetic</b> sequences:</p>
<pre>
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
</pre>

<p>The following sequence is not <b>arithmetic</b>:</p>
<pre>
1, 1, 2, 5, 7
</pre>

<p>You are given an array of <code>n</code> integers, <code>nums</code>, 
  and two arrays of <code>m</code> integers each, <code>l</code> and <code>r</code>, representing the <code>m</code> range queries,
  where the <code>i<sup>th</sup></code> query is the range <code>[l[i], r[i]]</code>. All the arrays are <b>0-indexed</b>.</p>

<p>Return a list of <code>boolean</code> elements <code>answer</code>, where <code>answer[i]</code> is <code>true</code> if the subarray <code>nums[l[i]], nums[l[i]+1], ... , 
  nums[r[i]]</code> can be <b>rearranged</b> to form an <b>arithmetic</b> sequence, and <code>false</code> otherwise.</p>
  
  
<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
<strong>Output:</strong> [true,false,true]
<strong>Explanation:</strong> 
In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
<strong>Output:</strong> [false,true,false,false,true,true]
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>n == nums.length</code></li>
  <li><code>m == l.length</code></li>
  <li><code>m == r.length</code></li>
  <li><code>2 &lt;= n &lt;= 500</code></li>
  <li><code>1 &lt;= m &lt;= 500</code></li>
  <li><code>0 &lt;= l[i] &lt; r[i] &lt; n</code></li>
  <li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/two-sum/
// Author: github.com/punkfulw
// Time: O(N*M*logN)
// Space: O(N)
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> ans;
        
        for (int i = 0; i < m; i++){
            bool found = true;
            int left = l[i], right = r[i];
            vector<int> cur(nums.begin() + left, nums.begin() + right + 1);
            sort(cur.begin(), cur.end());

            int dif = cur[1] - cur[0];
            for (int j = 1; j < cur.size() && found; j++)
                if (dif != cur[j] - cur[j - 1])
                    found = false;

            ans.push_back(found);
        } 
        return ans;
    }
};
```
