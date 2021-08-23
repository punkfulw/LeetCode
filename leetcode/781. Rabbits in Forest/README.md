# [781. Rabbits in Forest (Medium)](https://leetcode.com/problems/rabbits-in-forest/)

<p>There is a forest with an unknown number of rabbits.
  We asked n rabbits <b>"How many rabbits have the same color as you?"</b> and collected the answers in an integer array <code>answers</code> where <code>answers[i]</code> is the answer of the <code>i<sup>th</sup></code> rabbit.</p>

<p>Given the array <code>answers</code>, return <em>the minimum number of rabbits that could be in the forest.</em></p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> answers = [1, 1, 2]
<strong>Output:</strong> 5
<strong>Explanation:</strong>
The two rabbits that answered "1" could both be the same color, say red.
The rabbit than answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> answers = [10, 10, 10]
<strong>Output:</strong> 11
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= answers.length &lt;= 1000</code></li>
  <li><code>0 &lt;= answers[i] &lt;= 1000</code></li>
</ul>




**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/rabbits-in-forest/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int, int> map;
        for (auto num: answers) map[num]++;
        for (auto &[num, cnt] : map){
            if (num == 0){
                ans += cnt;
                continue;
            }
            int group = cnt / (num+1);
            if (cnt % (num+1)) group++;
            ans += group * (num + 1);
        }
        return ans;
    }
};
```
