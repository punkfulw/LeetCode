# [1394. Find Lucky Integer in an Array (Easy)](https://leetcode.com/problems/find-lucky-integer-in-an-array/)

<p>Given an array of integers <code>arr</code>, a lucky integer is an integer which has a frequency in the array equal to its value.</p>

<p>Return a lucky integer in the array. If there are multiple lucky integers return the <b>largest</b> of them. If there is no lucky integer return <b>-1</b>.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> arr = [2,2,3,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The only lucky number in the array is 2 because frequency[2] == 2.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> arr = [1,2,2,3,3,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 1, 2 and 3 are all lucky numbers, return the largest of them.
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> arr = [2,2,2,3,3]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There are no lucky numbers in the array.
</pre>

<p><strong>Example 4:</strong></p>
<pre>
<strong>Input:</strong> arr = [5]
<strong>Output:</strong> -1
</pre>

<p><strong>Example 5:</strong></p>
<pre>
<strong>Input:</strong> arr = [7,7,7,7,7,7,7]
<strong>Output:</strong> 7
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= arr.length &lt;= 500</code></li>
  <li><code>1 &lt;= arr[i] &lt;= 500</code></li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-lucky-integer-in-an-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        unordered_map<int, int> mp;
        for (int i: arr)
            mp[i]++;
        for(auto p: mp){
            if (p.first == p.second)
                ans = max(ans, p.first);
        }
        return ans;
    }
};
```

