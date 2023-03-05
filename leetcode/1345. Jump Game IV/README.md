# [1345. Jump Game IV (Hard)](https://leetcode.com/problems/jump-game-iv/)

<p>Given an array of&nbsp;integers <code>arr</code>, you are initially positioned at the first index of the array.</p>

<p>In one step you can jump from index <code>i</code> to index:</p>

<ul>
	<li><code>i + 1</code> where:&nbsp;<code>i + 1 &lt; arr.length</code>.</li>
	<li><code>i - 1</code> where:&nbsp;<code>i - 1 &gt;= 0</code>.</li>
	<li><code>j</code> where: <code>arr[i] == arr[j]</code> and <code>i != j</code>.</li>
</ul>

<p>Return <em>the minimum number of steps</em> to reach the <strong>last index</strong> of the array.</p>

<p>Notice that you can not jump outside of the array at any time.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [100,-23,-23,404,100,23,23,23,3,404]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You need three jumps from index 0 --&gt; 4 --&gt; 3 --&gt; 9. Note that index 9 is the last index of the array.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [7]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Start index is the last index. You do not need to jump.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [7,6,9,6,9,6,9,7]
<strong>Output:</strong> 1
<strong>Explanation:</strong> You can jump directly from index 0 to index 7 which is last index of the array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>8</sup> &lt;= arr[i] &lt;= 10<sup>8</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [tiktok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Jump Game VII (Medium)](https://leetcode.com/problems/jump-game-vii/)

## Solution 1. BFS


```cpp
// OJ: https://leetcode.com/problems/jump-game-iv/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        vector<int> vis(n);
        
        for (int i = 0; i < n; i++){
            int x = arr[i];
            mp[x].push_back(i);
        }
        
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        int step = 0;
        
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto idx = q.front();
                q.pop();
                int cur = arr[idx];
                if (idx == n - 1)
                    return step;
                
                if (mp.find(cur) != mp.end()){
                    for (auto nxt: mp[cur]){
                        if (!vis[nxt]){
                            q.push(nxt);
                            vis[nxt] = 1; 
                        }
                    }
                }
                
                if (idx >= 1 && !vis[idx - 1]) {
                    q.push(idx - 1);
                    vis[idx - 1] = 1;
                }
                if (idx < n - 1 && !vis[idx + 1]) {
                    q.push(idx + 1);
                    vis[idx + 1] = 1;
                }
                mp.erase(cur);
            }
            step++;
        }  
        return 0;
    }
};
```
