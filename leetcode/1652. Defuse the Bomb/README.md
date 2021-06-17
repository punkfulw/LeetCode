# [1652. Defuse the Bomb (Easy)](https://leetcode.com/problems/defuse-the-bomb/)

<p>You have a bomb to defuse, and your time is running out! Your informer will provide you with a <b>circular</b> array <code>code</code> of length of <code>n</code> and a key <code>k</code>.</p>

<p>To decrypt the code, you must replace every number. All the numbers are replaced <b>simultaneously</b>.</p>

<ul>
  <li>If <code>k > 0</code>, replace the <code>i<sup>th</sup></code> number with the sum of the <b>next</b> <code>k</code> numbers.</li>
  <li>If <code>k < 0</code>, replace the <code>i<sup>th</sup></code> number with the sum of the <b>previous</b> <code>k</code> numbers.</li>
  <li>If <code>k == 0</code>, replace the <code>i<sup>th</sup></code> number with the <code>0</code></li>
</ul>

<p>As <code>code</code> is circular, the next element of <code>code[n-1]</code> is <code>code[0]</code>, and the previous element of <code>code[0]</code> is <code>code[n-1]</code>.</p>

<p>Given the <b>circular</b> array <code>code</code> and an integer key <code>k</code>, return <em>the decrypted code to defuse the bomb!</em></p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> code = [5,7,1,4], k = 3
<strong>Output:</strong> [12,10,16,13]
<strong>Explanation:</strong> Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> code = [1,2,3,4], k = 0
<strong>Output:</strong> [0,0,0,0]
<strong>Explanation:</strong> When k is zero, the numbers are replaced by 0. 
</pre>

<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> code = [2,4,9,3], k = -2
<strong>Output:</strong> [12,5,6,13]
<strong>Explanation:</strong> The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. If k is negative, the sum is of the previous numbers.
</pre>

n == code.length
1 <= n <= 100
1 <= code[i] <= 100
-(n - 1) <= k <= n - 1

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>n == code.length</code></li>
  <li><code>1 &lt;= n &lt;= 100</code></li>
  <li><code>1 &lt;= code[i] &lt;= 100</code></li>
  <li><code>-(n - 1) &lt;= k &lt;= n - 1</code></li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.
Brute Force

```cpp
// OJ: https://leetcode.com/problems/defuse-the-bomb/
// Author: github.com/punkfulw
// Time: O(NM)
// Space: O(N)
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0)
            return ans;
        for (int i = 0; i < n; i++){
            if (k > 0){
                for (int j = 1; j <= k; j++){
                    ans[i] += code[(i+j) % n];
                }
            }
            else {
                for (int j = -1; j >= k; j--){
                    ans[i] += code[(i+j+n) % n];
                }
            }
        }
        return ans;
    }
};
```

## Solution 2.
sliding window

```cpp
// OJ: https://leetcode.com/problems/defuse-the-bomb/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0)
            return ans;
        int sum = 0, start = 1, end = k;
        
        if (k < 0){
            start = n+k;
            end = n-1;
        }
        for (int i = start; i <= end; i++)
            sum += code[i];
        for (int i = 0; i < n; i++){
            ans[i] = sum;
            sum = sum - code[(start++) % n] + code[(++end) % n];
        }
        return ans;
    }
};
```
