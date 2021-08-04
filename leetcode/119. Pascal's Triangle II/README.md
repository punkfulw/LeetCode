# [119. Pascal's Triangle II (Easy)](https://leetcode.com/problems/pascals-triangle-ii/)

<p>Given a non-negative&nbsp;index <em>k</em>&nbsp;where <em>k</em> ≤&nbsp;33, return the <em>k</em><sup>th</sup>&nbsp;index row of the Pascal's triangle.</p>

<p>Note that the row index starts from&nbsp;0.</p>

<p><img alt="" src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif"><br>
<small>In Pascal's triangle, each number is the sum of the two numbers directly above it.</small></p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> 3
<strong>Output:</strong> [1,3,3,1]
</pre>

<p><strong>Follow up:</strong></p>

<p>Could you optimize your algorithm to use only <em>O</em>(<em>k</em>) extra space?</p>


**Companies**:  
[Adobe](https://leetcode.com/company/adobe), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

## Solution 1. recursive

```cpp
// OJ: https://leetcode.com/problems/pascals-triangle-ii/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    vector<int> getRow(int row) {
        vector<int> ans = {1, 1};
        if (row == 0)
            return {1};
        dfs(ans, row, 1);
        return ans;
    }
    void dfs(vector<int>& ans, int row, int end){
        vector<int> temp(ans.size() + 1, 1);
        if (row == end)
            return;
        for (int i = 1; i < temp.size()-1; i++)
            temp[i] = ans[i-1] + ans[i];
        end++;
        ans = temp;
        dfs(ans, row, end);
        return;
    } 
};
```


## Solution 2. 
```cpp
// OJ: https://leetcode.com/problems/pascals-triangle-ii/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 0);
        ans[0] = 1;
        for(int i = 1; i < rowIndex+1; i++)
            for(int j = i; j >= 1; j--)
                ans[j] += ans[j-1];
        return ans;
    }
};
```


## Solution 3. one pass
<pre>
We know that the elements of the ith line of pascal triangle is just the coefficients of the expansion of

(a + b) ^ i

For example, the 4th line:

1 4 6 4 1
(a + b) ^ 4 = a^4 + 4a^3b + 6a^2b^2 + 4ab^3 + b^4

And the we know the coefficients can be computed by composition. 
For the above example, the coefficients are respectively C(4, 0), C(4, 1), C(4, 2), C(4, 3), C(4, 4).

Then we have the following code:
</pre>

```cpp
// OJ: https://leetcode.com/problems/pascals-triangle-ii/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/pascals-triangle-ii/discuss/38438/7-lines-C%2B%2B-solution-one-pass-O(k)-space-for-return-with-detailed-explanation
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex + 1, 1);
        long C = 1;
        for (int i = 1; i < rowIndex; i++) {
            C = C * (rowIndex - i + 1) / i;
            ret[i] = C;
        }
        return ret;
    }
};
```
