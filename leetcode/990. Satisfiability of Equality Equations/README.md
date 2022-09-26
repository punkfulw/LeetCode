# [990. Satisfiability of Equality Equations (Medium)](https://leetcode.com/problems/satisfiability-of-equality-equations/)

<p>Given an array <font face="monospace">equations</font>&nbsp;of strings that represent relationships between variables, each string <code>equations[i]</code>&nbsp;has length <code>4</code> and takes one of two different forms: <code>"a==b"</code> or <code>"a!=b"</code>.&nbsp; Here, <code>a</code> and <code>b</code> are lowercase letters (not necessarily different) that represent one-letter variable names.</p>

<p>Return <code>true</code>&nbsp;if and only if it is possible to assign integers to variable names&nbsp;so as to satisfy all the given equations.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">["a==b","b!=a"]</span>
<strong>Output: </strong><span id="example-output-1">false</span>
<strong>Explanation: </strong>If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.  There is no way to assign the variables to satisfy both equations.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">["b==a","a==b"]</span>
<strong>Output: </strong><span id="example-output-2">true</span>
<strong>Explanation: </strong>We could assign a = 1 and b = 1 to satisfy both equations.
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">["a==b","b==c","a==c"]</span>
<strong>Output: </strong><span id="example-output-3">true</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong><span id="example-input-4-1">["a==b","b!=c","c==a"]</span>
<strong>Output: </strong><span id="example-output-4">false</span>
</pre>

<div>
<p><strong>Example 5:</strong></p>

<pre><strong>Input: </strong><span id="example-input-5-1">["c==c","b==d","x!=z"]</span>
<strong>Output: </strong><span id="example-output-5">true</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= equations.length &lt;= 500</code></li>
	<li><code>equations[i].length == 4</code></li>
	<li><code>equations[i][0]</code> and <code>equations[i][3]</code> are lowercase letters</li>
	<li><code>equations[i][1]</code> is either <code>'='</code> or <code>'!'</code></li>
	<li><code>equations[i][2]</code> is&nbsp;<code>'='</code></li>
</ol>
</div>
</div>
</div>
</div>
</div>


**Related Topics**:  
[Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/satisfiability-of-equality-equations/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int parent[26] = {};
    
    int find(int a){
        return parent[a] == a ? a : parent[a] = find(parent[a]); 
    }
    
    void unionNode(char a, char b){
        int p1 = find(a - 'a'),  p2 = find(b - 'a');
        if (p1 != p2)
            parent[p1] = p2;
    }
    
    bool equationsPossible(vector<string>& eq) {
        for (int i = 0; i < 26; i++)
            parent[i] = i;
        
        for (auto e: eq)
            if (e[1] == '=')
                unionNode(e[0], e[3]);

        for (auto e: eq)
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
                return false;
        return true;
    }
};
```

