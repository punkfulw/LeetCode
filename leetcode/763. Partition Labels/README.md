# [763. Partition Labels (Medium)](https://leetcode.com/problems/partition-labels/)

<p>
A string <code>S</code> of lowercase letters is given.  We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
</p><p>

</p><p><b>Example 1:</b><br>
</p><pre><b>Input:</b> S = "ababcbacadefegdehijhklij"
<b>Output:</b> [9,7,8]
<b>Explanation:</b>
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
</pre>
<p></p>

<p><b>Note:</b><br></p><ol>
<li><code>S</code> will have length in range <code>[1, 500]</code>.</li>
<li><code>S</code> will consist of lowercase letters (<code>'a'</code> to <code>'z'</code>) only.</li>
</ol><p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)

## Solution 1. 

First find the lst position of every letter.

Iterate ths string again and use a running count to record current partition

If the max last position == i, it's an end of one partition.

Push the current running cnout into ans;

```cpp
// OJ: https://leetcode.com/problems/partition-labels/
// Author: github.com/punkfulw
// Time: O(S)
// Space: O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        int last[26];
        for (int i = 0; i < n; i++)
            last[s[i] - 'a'] = i;
        
        int window = 1, Atleast = 0;
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            int lastPos = last[c - 'a'];
            Atleast = max(Atleast, lastPos);  
            if (i == Atleast)
            {
                ans.push_back(window);
                window = 1;
                Atleast = i + 1;
            }
            else 
                window++;
        } 
        return ans;
    }
};
```
