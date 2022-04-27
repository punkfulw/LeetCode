# [1202. Smallest String With Swaps (Medium)](https://leetcode.com/problems/smallest-string-with-swaps/)

<p>You are given a string <code>s</code>, and an array of pairs of indices in the string&nbsp;<code>pairs</code>&nbsp;where&nbsp;<code>pairs[i] =&nbsp;[a, b]</code>&nbsp;indicates 2 indices(0-indexed) of the string.</p>

<p>You can&nbsp;swap the characters at any pair of indices in the given&nbsp;<code>pairs</code>&nbsp;<strong>any number of times</strong>.</p>

<p>Return the&nbsp;lexicographically smallest string that <code>s</code>&nbsp;can be changed to after using the swaps.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "dcab", pairs = [[0,3],[1,2]]
<strong>Output:</strong> "bacd"
<strong>Explaination:</strong> 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "dcab", pairs = [[0,3],[1,2],[0,2]]
<strong>Output:</strong> "abcd"
<strong>Explaination: </strong>
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "cba", pairs = [[0,1],[1,2]]
<strong>Output:</strong> "abc"
<strong>Explaination: </strong>
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= pairs.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= pairs[i][0], pairs[i][1] &lt;&nbsp;s.length</code></li>
	<li><code>s</code>&nbsp;only contains lower case English letters.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Union Find](https://leetcode.com/tag/union-find/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/smallest-string-with-swaps/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/smallest-string-with-swaps/discuss/388257/C%2B%2B-with-picture-union-find
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int ufind(vector<int> &par, int i)
    {
        return par[i] < 0 ? i : par[i] = ufind(par, par[i]);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> par (n, -1);
        vector<vector<int>> arr(n);
        
        for (auto p: pairs)
        {
            int x = ufind(par, p[0]), y = ufind(par, p[1]);
            if (x != y)
            {
                if (par[x] < par[y])
                    swap(x, y);
                par[x] += par[y];
                par[y] = x;
            }
        }
        for (int i = 0; i < n; i++)
            arr[ufind(par, i)].push_back(i);
        
        for (auto ids: arr)
        {
            string ss = "";
            for (auto id: ids)
                ss += s[id];
            sort(ss.begin(), ss.end());
            for (int i = 0; i < ids.size(); i++)
                s[ids[i]] = ss[i];
        }
        return s;
    }
};
```

## Solution 1. -py

```python3
# OJ: https://leetcode.com/problems/smallest-string-with-swaps/
# Author: github.com/punkfulw
# Ref: https://leetcode.com/problems/smallest-string-with-swaps/discuss/388257/C%2B%2B-with-picture-union-find
# Time: O(NlogN)
# Space: O(N)
class Solution:
    def union_find(self, par, i):
        if (par[i] < 0):
            return i;
        par[i] = self.union_find(par, par[i])
        return par[i]
    
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        n = len(s)
        par = [-1 for _ in range(n)]
        arr = [[] for _ in range(n)]
        res = ['0' for _ in range(n)]
        
        for i, j in pairs:
            i = self.union_find(par, i)
            j = self.union_find(par, j)

            if i != j:
                par[j] = i
        
        for i in range(n):
            arr[self.union_find(par, i)].append(i) 
            
        for ids in arr:
            ss = ""
            for id in ids:
                ss += s[id]
            ss = sorted(ss)
            for i in range(len(ids)):
                res[ids[i]] = ss[i]
        return ''.join(res)
        
```
