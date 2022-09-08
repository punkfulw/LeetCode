# [912. Sort an Array (Medium)](https://leetcode.com/problems/sort-an-array/)

<p>Given an array of integers <code>nums</code>, sort the array in ascending order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [5,2,3,1]
<strong>Output:</strong> [1,2,3,5]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [5,1,1,2,0,0]
<strong>Output:</strong> [0,0,1,1,2,5]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-5 * 10<sup>4</sup> &lt;= nums[i] &lt;= 5 * 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Merge Sort](https://leetcode.com/tag/merge-sort/), [Bucket Sort](https://leetcode.com/tag/bucket-sort/), [Radix Sort](https://leetcode.com/tag/radix-sort/), [Counting Sort](https://leetcode.com/tag/counting-sort/)


## Solution 1. Bucket Sort

```cpp
// OJ: https://leetcode.com/problems/sort-an-array/
// Author: github.com/punkfulw
// Time: O(N + K) 
// Space: O(K) 
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int idx = 0, offset = 5 * 1e4;
        vector<int> bucket(1e5 + 2);
        for (auto i: nums)
            bucket[i + offset]++;

        for (int i = 0; i < 1e5 + 2; i++){
            while (bucket[i]){
                nums[idx++] = i - offset;
                bucket[i]--;
            }
        }
        return nums;
    }
};
```

## Solution 3. Merge Sort

```cpp
// OJ: https://leetcode.com/problems/sort-an-array/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    void merge(int l, int m, int r, vector<int> &nums){
        int i = l, j = m + 1, idx = 0;
        vector<int> arr(r - l + 1);
        while (i <= m && j <= r){
            if (nums[i] <= nums[j])
                arr[idx++] = nums[i++];
            else
                arr[idx++] = nums[j++];
        }
        while (i <= m)
            arr[idx++] = nums[i++];
        while (j <= r)
            arr[idx++] = nums[j++];
        for (int i = l; i <= r; i++)
            nums[i] = arr[i - l];
    }
    
    void mergeSort(int l, int r, vector<int> &nums){
        if (l >= r)
            return;
        int m = l + (r - l) / 2;
        mergeSort(l, m, nums);
        mergeSort(m + 1, r, nums);
        merge(l, m, r, nums);
        return;
    } 
    
    vector<int> sortArray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        mergeSort(l, r, nums);
        return nums;
    }
};
```

