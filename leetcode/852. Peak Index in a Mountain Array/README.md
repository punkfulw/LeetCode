# [852. Peak Index in a Mountain Array (Easy)](https://leetcode.com/problems/peak-index-in-a-mountain-array/)

<p>Let's call an array <code>arr</code> a <b>mountain</b> if the following properties hold:</p>

<ul>
	<li><code>arr.length &gt;= 3</code></li>
	<li>There exists <code>i</code> with <code>0 &lt; i&nbsp;&lt; A.length - 1</code> such that: </li>
	<ul>
		<li><code>arr[0] < arr[1] < ... arr[i-1] < arr[i]</code></li>
		<li><code>arr[i] > arr[i+1] > ... > arr[arr.length - 1]</code></li>
	</ul>
</ul>

<p>Given an integer array <code>arr</code> that is <b>guaranteed</b> to be a mountain,
return any <code>i</code> such that <code>arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]</code>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[0,1,0]</span>
<strong>Output: </strong><span id="example-output-1">1</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[0,2,1,0]</span>
<strong>Output: </strong><span id="example-output-2">1</span></pre>
</div>

<p><strong>Constraints:</strong></p>

<ol>
	<li><code>3 &lt;= A.length &lt;= 10<sup>4</sup></code></li>
	<li><code><font face="monospace">0 &lt;= A[i] &lt;= 10<sup>6</sup></font></code></li>
	<li>arr&nbsp; is <b>guaranteed</b> to be a mountain array.</li>
</ol>


## Solution 1. Linear Search

```cpp
// OJ: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] > arr[i+1])
                return i;
        }
        return 0;
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1 , mid;
        while(l < r){
            mid = (r + l) /2;
            if (arr[mid] < arr[mid+1])
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
};
```
