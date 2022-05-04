# [1679. Max Number of K-Sum Pairs (Medium)](https://leetcode.com/problems/max-number-of-k-sum-pairs/)

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>.</p>

<p>In one operation, you can pick two numbers from the array whose sum equals <code>k</code> and remove them from the array.</p>

<p>Return <em>the maximum number of operations you can perform on the array</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4], k = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,1,3,4,3], k = 6
<strong>Output:</strong> 1
<strong>Explanation:</strong> Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)

## Solution 1. map

```cpp
// OJ: https://leetcode.com/contest/weekly-contest-218/problems/max-number-of-k-sum-pairs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> mp, vis;
        
        for (auto i: nums)
        {
            if (i >= k)
                continue;
            mp[i]++;
        }  
        
        for (auto p: mp)
        {
            // cout << p.first << " " << p.second << endl;
            int cur = p.first, match = k - cur;
            if (vis[cur])
                continue;
            vis[cur] = vis[match] = 1;    
            ans += cur == match ? mp[cur] / 2 : min(mp[cur], mp[match]);
        }
        return ans;
    }
};
```

## Solution 2. One Pass

```cpp
// OJ: https://leetcode.com/problems/max-number-of-k-sum-pairs/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/max-number-of-k-sum-pairs/discuss/1023235/C%2B%2B4-approaches-a-variation-of-two-sum
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> mp;
        
        for (auto i: nums)
        {
            int match = k - i;
            if (mp[match])
            {
                ans++;
                mp[match]--;
            }  
            else
                mp[i]++;
        }
        return ans;
    }
};
```

## Solution 2. One Pass -py

```python3
# OJ: https://leetcode.com/problems/max-number-of-k-sum-pairs/
# Author: github.com/punkfulw
# Ref: https://leetcode.com/problems/max-number-of-k-sum-pairs/discuss/1023235/C%2B%2B4-approaches-a-variation-of-two-sum
# Time: O(N)
# Space: O(N)
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        ans = 0
        for i in nums:
            if i >= k:
                continue
            match = k - i
            if mp[match] >= 1:
                ans += 1
                mp[match] -= 1
            else:
                mp[i] += 1
        return ans
```
