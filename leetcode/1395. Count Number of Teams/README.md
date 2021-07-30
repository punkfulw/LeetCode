# [1395. Count Number of Teams (Medium)](https://leetcode.com/problems/count-number-of-teams/)

<p>There are <code>n</code> soldiers standing in a line. Each soldier is assigned a unique <code>rating</code> value.</p>

<p>You have to form a team of 3 soldiers amongst them under the following rules:</p>

<ul>
  <li>Choose 3 soldiers with index (<code>i</code>, <code>j</code>, <code>k</code>) with rating (<code>rating[i]</code>, <code>rating[j]</code>, <code>rating[k]</code>).</li>
  <li>A team is valid if: (<code>rating[i] < rating[j] < rating[k]</code>) or (<code>rating[i] > rating[j] > rating[k]</code>) where (<code>0 <= i < j < k < n</code>).</li>
</ul>

<p>Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> rating = [2,5,3,4,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> rating = [2,1,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> We can't form any team given the conditions.
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> rating = [1,2,3,4]
<strong>Output:</strong> 4
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>n == rating.length</code></li>
  <li><code>3 &lt;= n &lt;= 1000</code></li>
  <li><code>1 &lt;= rating[i] &lt;= 10<sup>5</sup></code></li>
  <li>All the integers in <code>rating</code> are <b>unique</b>.</li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [DP](https://leetcode.com/tag/dynamic-programming/), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-number-of-teams/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int numTeams(vector<int>& r) {
        int ans = 0, n = r.size();
        vector<int> leftsmall(n), leftbig(n), rightsmall(n), rightbig(n);
        for(int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (r[j] < r[i])
                    leftsmall[i]++;
                else if(r[j] > r[i])
                    leftbig[i]++;
            }
        }
        for(int i = n-2; i >= 0; i--){
            for (int j = n-1; j > i; j--){
                if (r[j] < r[i])
                    rightsmall[i]++;
                else if(r[j] > r[i])
                    rightbig[i]++;
            }
        }
        for (int i = 0; i < n; i++)
            ans += rightsmall[i] * leftbig[i] + leftsmall[i] * rightbig[i];
        return ans;
    }
};
```

## Solution 2. optimized

```cpp
// OJ: https://leetcode.com/problems/count-number-of-teams/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/count-number-of-teams/discuss/554795/C%2B%2BJava-O(n-*-n)-and-O(n-log-n)
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int numTeams(vector<int>& r) {
        int ans = 0, n = r.size();
        
        for(int i = 0; i < n; i++){
            int leftsmall = 0, leftbig = 0;
            int rightsmall = 0, rightbig = 0;
            for (int j = 0; j < i; j++){
                if (r[j] < r[i])
                    leftsmall++;
                else if(r[j] > r[i])
                    leftbig++;
            }
            for (int j = n-1; j > i; j--){
                if (r[j] < r[i])
                    rightsmall++;
                else if(r[j] > r[i])
                    rightbig++;
            }
            ans += rightsmall * leftbig + leftsmall * rightbig;
        }
        return ans;
    }
};
```
