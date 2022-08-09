# [1079. Letter Tile Possibilities (Medium)](https://leetcode.com/problems/letter-tile-possibilities/)

<p>You have a set of <code>tiles</code>, where each tile has one letter <code>tiles[i]</code> printed on it.&nbsp; Return the number of possible non-empty sequences of letters you can make.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"AAB"</span>
<strong>Output: </strong><span id="example-output-1">8</span>
<strong>Explanation: </strong>The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">"AAABBC"</span>
<strong>Output: </strong><span id="example-output-2">188</span>
</pre>

<p>&nbsp;</p>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= tiles.length &lt;= 7</code></li>
	<li><code>tiles</code> consists of uppercase English letters.</li>
</ol>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/letter-tile-possibilities/
// Author: github.com/punkfulw
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    int n;
    unordered_set<string> ans;
    
    void dfs(int i, string &s, string &tiles, vector<int> &visited){
        s += tiles[i];
        visited[i] = 1;
        ans.insert(s);
        for (int j = 0; j < n; j++)
            if (!visited[j])
                dfs(j, s, tiles, visited);
        visited[i] = 0;
        s.pop_back();
    }
    
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        sort(tiles.begin(), tiles.end());
        for (int i = 0; i < n; i++){
            string s;
            if (i == 0 || tiles[i] != tiles[i - 1]){
                vector<int> visited(n);
                dfs(i, s, tiles, visited);
            }
        }
        return ans.size();
    }
};
```
