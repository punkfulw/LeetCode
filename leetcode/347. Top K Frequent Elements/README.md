# [347. Top K Frequent Elements (Medium)](https://leetcode.com/problems/top-k-frequent-elements/)

<p>Given a non-empty array of integers, return the <b><i>k</i></b> most frequent elements.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-1-1">[1,1,1,2,2,3]</span>, k = <span id="example-input-1-2">2</span>
<strong>Output: </strong><span id="example-output-1">[1,2]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-2-1">[1]</span>, k = <span id="example-input-2-2">1</span>
<strong>Output: </strong><span id="example-output-2">[1]</span></pre>
</div>

<p><b>Note: </b></p>

<ul>
	<li>You may assume <i>k</i> is always valid, 1 ≤ <i>k</i> ≤ number of unique elements.</li>
	<li>Your algorithm's time complexity <b>must be</b> better than O(<i>n</i> log <i>n</i>), where <i>n</i> is the array's size.</li>
	<li>It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.</li>
	<li>You can return the answer in any order.</li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Heap](https://leetcode.com/tag/heap/)

**Similar Questions**:
* [Word Frequency (Medium)](https://leetcode.com/problems/word-frequency/)
* [Kth Largest Element in an Array (Medium)](https://leetcode.com/problems/kth-largest-element-in-an-array/)
* [Sort Characters By Frequency (Medium)](https://leetcode.com/problems/sort-characters-by-frequency/)
* [Split Array into Consecutive Subsequences (Medium)](https://leetcode.com/problems/split-array-into-consecutive-subsequences/)
* [Top K Frequent Words (Medium)](https://leetcode.com/problems/top-k-frequent-words/)
* [K Closest Points to Origin (Medium)](https://leetcode.com/problems/k-closest-points-to-origin/)

## Solution 1. Heap

```cpp
// OJ: https://leetcode.com/problems/top-k-frequent-elements/
// Author: github.com/punkfulw
// Time: O(NlogK)
// Space: O(U) Unique number in the array
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto i: nums)
            mp[i]++;
        
        for (auto p: mp)
        {
            pq.push({p.second, p.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
```


## Solution 2. Buckets Sort

```cpp
// OJ: https://leetcode.com/problems/top-k-frequent-elements/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(U)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        vector<int> ans;
        vector<vector<int>> buckets(n + 1);
        for (auto i: nums)
            cnt[i]++;
        
        for (auto p: cnt)
            buckets[p.second].push_back(p.first);
        
        for (int i = n; i >= 0 && ans.size() < k; i--)
        {
            if (!buckets[i].empty())
                ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
        }
        return ans;
    }
};
```


```python3
# OJ: https://leetcode.com/problems/top-k-frequent-elements/
# Author: github.com/punkfulw
# Time: O(N) 
# Space: O(U)
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums).items()  
        buckets = [[] for _ in range(len(nums) + 1)]
        for num, freq in cnt:
            buckets[freq].append(num)
        
        ans = []
        for i in range(len(buckets) - 1, -1, -1):
            if len(buckets[i]):
                for num in buckets[i]:
                    ans.append(num)
        return ans[:k]
  ```
