# [350. Intersection of Two Arrays II (Easy)](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

<p>Given two integer arrays nums1 and nums2, return an array of their intersection. 
  Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums1 = [1,2,2,1], nums2 = [2,2]
<strong>Output:</strong> [2,2]
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>Output:</strong> [4,9]
<strong>Explanation:</strong> [9,4] is also accepted.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length, nums2.length &lt;= 1000</code></li>
  <li><code>0 &lt;= nums[i], nums2[i] &lt;= 1000</code></li>
</ul>


<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
  <li>What if the given array is already sorted? How would you optimize your algorithm?</li>
  <li>What if nums1's size is small compared to nums2's size? Which algorithm is better?</li>
  <li>What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)



## Solution 1. Hash map

```cpp
// OJ: https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (auto i: nums1)
            mp[i]++;
        for (auto i: nums2){
            if (mp[i]){
                mp[i]--;
                ans.push_back(i);
            }  
        }
        return ans;
    }
};
```

## Solution 2. sort + two pointer

```python3
# OJ: https://leetcode.com/problems/intersection-of-two-arrays-ii/
# Author: github.com/punkfulw
# Time: O(NlogN)
# Space: O(1)
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        i = j = 0
        ans = []
        nums1, nums2 = sorted(nums1), sorted(nums2)
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                ans.append(nums1[i])
                i, j = i + 1, j + 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        return ans;
```

