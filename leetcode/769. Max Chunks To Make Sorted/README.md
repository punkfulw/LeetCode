# [769. Max Chunks To Make Sorted (Medium)](https://leetcode.com/problems/max-chunks-to-make-sorted/)

<p>Given an array <code>arr</code> that is a permutation of <code>[0, 1, ..., arr.length - 1]</code>, we split the array into some number of "chunks" (partitions), and individually sort each chunk.&nbsp; After concatenating them,&nbsp;the result equals the sorted array.</p>

<p>What is the most number of chunks we could have made?</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [4,3,2,1,0]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,0,2,3,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong>
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li><code>arr</code> will have length in range <code>[1, 10]</code>.</li>
	<li><code>arr[i]</code> will be a permutation of <code>[0, 1, ..., arr.length - 1]</code>.</li>
</ul>

<p>&nbsp;</p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Max Chunks To Make Sorted II (Hard)](https://leetcode.com/problems/max-chunks-to-make-sorted-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/max-chunks-to-make-sorted/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        for (int i = 0; i < n; i++){
            int cur = arr[i], mx = cur;
            while (mx > i && ++i < n)
                mx = max(mx, arr[i]);
            ans++;
        }
        return ans;
    }
};
```

