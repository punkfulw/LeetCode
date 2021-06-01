# [349. Intersection of Two Arrays (Easy)](https://leetcode.com/problems/intersection-of-two-arrays/)

<p>Given two integer arrays <code>nums1</code> and <code>nums2</code>, return <em>an array of their intersection. </em>
  Each element in the result must be <b>unique</b> and you may return the result in <b>any order</b>.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums1 = [1,2,2,1], nums2 = [2,2]
<strong>Output:</strong> [2]
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>Output:</strong> [9,4]
<strong>Explanation: </strong> [4,9] is also accepted.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
  <li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>



**Related Topics**:  
[Two Pointer](https://leetcode.com/tag/two-pointers/), [Hash Table](https://leetcode.com/tag/hash-table/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sort](https://leetcode.com/tag/sort/)



## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/intersection-of-two-arrays/
// Author: github.com/punkfulw
// Time: O(N+M)
// Space: O(1)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++){
            if (count(nums2.begin(), nums2.end(), nums1[i]) && !count(ans.begin(), ans.end(), nums1[i]))
                ans.push_back(nums1[i]);
        }
        return ans;
    }
};
```



## Solution 2. Hash Table

```cpp
// OJ: https://leetcode.com/problems/intersection-of-two-arrays/
// Author: github.com/punkfulw
// Time: O(N+M)
// Space: O(N)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int num: nums2){
           if (s.erase(num))
               ans.push_back(num);
        }
        return ans;
    }
};
```

