# [406. Queue Reconstruction by Height (Medium)](https://leetcode.com/problems/queue-reconstruction-by-height/)

<p>Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers <code>(h, k)</code>, where <code>h</code> is the height of the person and <code>k</code> is the number of people in front of this person who have a height greater than or equal to <code>h</code>. Write an algorithm to reconstruct the queue.</p>

<p><b>Note:</b><br>
The number of people is less than 1,100.</p>
&nbsp;

<p><b>Example</b></p>

<pre>Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
</pre>

<p>&nbsp;</p>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Count of Smaller Numbers After Self (Hard)](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)

## Solution 1. shortest -> tallest

```cpp
// OJ: https://leetcode.com/problems/queue-reconstruction-by-height
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& P) {
        int n = P.size();      
        sort(P.begin(), P.end());
        vector<vector<int>> ans(n, vector<int> (2, -1));
        for (auto p: P){
            int skip = p[1], pos = 0;
            while (ans[pos][0] != -1){
                skip -= ans[pos][0] == p[0] ? 1 : 0;
                pos++;
            }
            while (skip > 0){
                if (ans[pos][0] == -1 || ans[pos][0] == p[0])
                    skip--; 
                pos++;
            }
            while (ans[pos][0] != -1)
                pos++;
            ans[pos] = p;
        }
        return ans;
    }
};



```

## Solution 2. tallest -> shortest

```cpp
// OJ: https://leetcode.com/problems/queue-reconstruction-by-height
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/queue-reconstruction-by-height/discuss/89345/Easy-concept-with-PythonC%2B%2BJava-Solution
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& P) {
        sort(P.begin(), P.end(), [](vector<int> &a, vector<int> &b){
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<vector<int>> ans;
        for (auto p: P)
            ans.insert(ans.begin() + p[1], p);
        return ans;
    }
};

```
