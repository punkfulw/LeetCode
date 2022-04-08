# [703. Kth Largest Element in a Stream (Easy)](https://leetcode.com/problems/kth-largest-element-in-a-stream/)

<p>Design a class to find&nbsp;the <strong>k</strong>th largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.</p>

<p>Your&nbsp;<code>KthLargest</code>&nbsp;class will have a constructor which accepts an integer <code>k</code> and an integer array <code>nums</code>, which contains initial elements from&nbsp;the stream. For each call to the method <code>KthLargest.add</code>, return the element representing the kth largest element in the stream.</p>

<p><strong>Example:</strong></p>

<pre>int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);&nbsp; &nbsp;// returns 4
kthLargest.add(5);&nbsp; &nbsp;// returns 5
kthLargest.add(10);&nbsp; // returns 5
kthLargest.add(9);&nbsp; &nbsp;// returns 8
kthLargest.add(4);&nbsp; &nbsp;// returns 8
</pre>

<p><strong>Note: </strong><br>
You may assume that&nbsp;<code>nums</code>' length&nbsp;≥&nbsp;<code>k-1</code>&nbsp;and <code>k</code> ≥&nbsp;1.</p>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Author: github.com/punkfulw
// Time:
//     KthLargest: O(NlogK)
//     add: O(logK)
// Space: O(N)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (auto i: nums)
        {
            pq.push(i);
            if (pq.size() > K)
                pq.pop();
         }    
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K)
            pq.pop();
        return pq.top();
    }
};
```

## Solution 2.

```python3
# OJ: https://leetcode.com/problems/kth-largest-element-in-a-stream/
# Author: github.com/punkfulw
# Time:
#     KthLargest: O(NlogK)
#     add: O(logK)
# Space: O(N)
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.nums = nums
        self.k = k
        heapify(nums)
        while len(self.nums) > k:
            heappop(self.nums)

    def add(self, val: int) -> int:
        heappush(self.nums, val)
        if len(self.nums) > self.k:
            heappop(self.nums)
        return self.nums[0]
```
