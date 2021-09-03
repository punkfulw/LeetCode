# [1806. Minimum Number of Operations to Reinitialize a Permutation (Medium)](https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/)

<p>You are given an <strong>even</strong> integer <code>n</code>​​​​​​. You initially have a permutation <code>perm</code> of size <code>n</code>​​ where <code>perm[i] == i</code>​ <strong>(0-indexed)</strong>​​​​.</p>

<p>In one operation, you will create a new array <code>arr</code>, and for each <code>i</code>:</p>

<ul>
	<li>If <code>i % 2 == 0</code>, then <code>arr[i] = perm[i / 2]</code>.</li>
	<li>If <code>i % 2 == 1</code>, then <code>arr[i] = perm[n / 2 + (i - 1) / 2]</code>.</li>
</ul>

<p>You will then assign <code>arr</code>​​​​ to <code>perm</code>.</p>

<p>Return <em>the minimum <strong>non-zero</strong> number of operations you need to perform on </em><code>perm</code><em> to return the permutation to its initial value.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> perm = [0,1] initially.
After the 1<sup>st</sup> operation, perm = [0,1]
So it takes only 1 operation.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> perm = [0,1,2,3] initially.
After the 1<sup>st</sup> operation, perm = [0,2,1,3]
After the 2<sup>nd</sup> operation, perm = [0,1,2,3]
So it takes only 2 operations.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 6
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>n</code>​​​​​​ is even.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Simulate the whole array

```cpp
// OJ: https://leetcode.com/contest/weekly-contest-234/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> rec (n), arr, copy;
        iota(rec.begin(), rec.end(), 0);
        int cnt = 0;
        arr = copy = rec;
        while (cnt == 0 || arr != rec){
            for (int i = 0; i < n; i++){
                if (i % 2 == 0)
                    arr[i] = copy[i/2];
                else
                    arr[i] = copy[n/2 + (i - 1) / 2];

            }
            copy = arr;
            cnt++;
        }
        return cnt;
    }
};
```


## Solution 2. Simulate index 1

```cpp
// OJ: https://leetcode.com/contest/weekly-contest-234/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/discuss/1130534/JavaC%2B%2BPython-6-lines-O(1)-Space
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int reinitializePermutation(int n) {
        int i = 1, cnt = 0;
        while (cnt == 0 || i > 1){
            if (i < n / 2)
                i *= 2;
            else
                i = 2 * i - n + 1;
            cnt++;
        }
        return cnt;
    }
};
```
