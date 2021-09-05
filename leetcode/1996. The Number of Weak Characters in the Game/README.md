# [1996. The Number of Weak Characters in the Game (Medium)](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/)

<p>You are playing a game that contains multiple characters, and each of the characters has two main properties: <b>attack</b> and <b>defense</b>. 
  You are given a 2D integer array properties where <code>properties[i] = [attacki, defensei]</code> represents the properties of the ith character in the game.</p>

<p>A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. 
  More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.</p>

<p>Return the number of weak characters.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> properties = [[5,5],[6,3],[3,6]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> No character has strictly greater attack and defense than the other.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> properties = [[2,2],[3,3]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The first character is weak because the second character has a strictly greater attack and defense.
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> properties = [[1,5],[10,4],[4,3]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The third character is weak because the second character has a strictly greater attack and defense.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>2 &lt;= properties.length &lt;= 10<sup>5</sup></code></li>
  <li><code>properties[i].length == 2</code></li>
  <li><code>1 &lt;= attacki, defensei &lt;= 10<sup>5</sup></code></li>
</ul>



**Related Topics**:  
[Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/)



## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/discuss/1445186/EASY-C%2B%2B-solution-with-great-explanation-and-comments-(nlogn)-sorting
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        sort(pro.begin(), pro.end(), [](vector<int> &a, vector<int> &b){
            if (a[0] == b[0]) 
                return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int ans = 0, n = pro.size(), mx = 0;
        for (int i = n-1; i >= 0; i--){
            if (pro[i][1] < mx)
                ans++;
            mx = max(mx, pro[i][1]);
        }
        return ans;
    }
};
```
