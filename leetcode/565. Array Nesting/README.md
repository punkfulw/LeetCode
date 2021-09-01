# [565. Array Nesting (Medium)](https://leetcode.com/problems/array-nesting/)

<p>You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].</p>

<p>You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:</p>

<ul>
  <li>The first element in s[k] starts with the selection of the element nums[k] of index = k.</li>
  <li>The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.</li>
  <li>We stop adding right before a duplicate element occurs in s[k].</li>
</ul>

<p>Return the longest length of a set s[k].</p>


<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> A = [5,4,0,3,1,6,2]
<b>Output:</b> 4
<b>Explanation:</b> 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
  <li><code>0 &lt;= nums[i] &lt;= nums.length</code></li>
  <li><code>All the values of nums are unique.</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Nested List Weight Sum (Easy)](https://leetcode.com/problems/nested-list-weight-sum/)
* [Flatten Nested List Iterator (Medium)](https://leetcode.com/problems/flatten-nested-list-iterator/)
* [Nested List Weight Sum II (Medium)](https://leetcode.com/problems/nested-list-weight-sum-ii/)

## Solution 1. dfs (not optimal, but if there's a interwine)  

```cpp
// OJ: https://leetcode.com/problems/array-nesting/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 1, n = nums.size();
        vector<int> cnt(n);
        for (int i = 0; i < n; i++){
            unordered_set<int> s;
            int cur = dfs(nums, cnt, i, s);
            ans = max(ans, cur);
        }
        return ans;
    }
    int dfs(vector<int>& nums, vector<int>& cnt, int start, unordered_set<int>& s){
        if (cnt[start] || s.count(nums[start]))
            return cnt[start];
        s.insert(nums[start]);
        int num = dfs(nums, cnt, nums[start], s);
        cnt[start] = num + 1;
        return num + 1 ;
    }
};
```

## Solution 2. record

```cpp
// OJ: https://leetcode.com/problems/array-nesting/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/array-nesting/discuss/102473/JavaC%2B%2BPython-Straight-Forward
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 1, n = nums.size();
        vector<bool> seen(n);
        for (int i: nums){
            int cur = 0;
            while (!seen[i]){
                cur++;
                seen[i] = 1;
                i = nums[i];
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
```
