# [835. Image Overlap (Medium)](https://leetcode.com/problems/image-overlap/)

<p>Two images <code>A</code> and <code>B</code> are given, represented as&nbsp;binary, square matrices of the same size.&nbsp; (A binary matrix has only 0s and 1s as values.)</p>

<p>We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.&nbsp; After, the <em>overlap</em> of this translation is the number of positions that have a 1 in both images.</p>

<p>(Note also that a translation does <strong>not</strong> include any kind of rotation.)</p>

<p>What is the largest possible overlap?</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = [[1,1,0],
            [0,1,0],
&nbsp;           [0,1,0]]
&nbsp;      B = [[0,0,0],
&nbsp;           [0,1,1],
&nbsp;           [0,0,1]]
<strong>Output: </strong>3
<strong>Explanation:</strong> We slide A to right by 1 unit and down by 1 unit.</pre>

<p><strong>Notes:</strong>&nbsp;</p>

<ol>
	<li><code>1 &lt;= A.length = A[0].length = B.length = B[0].length &lt;= 30</code></li>
	<li><code>0 &lt;=&nbsp;A[i][j], B[i][j] &lt;= 1</code></li>
</ol>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/image-overlap/
// Author: github.com/punkfulw
// Time: O(N^4)
// Space: O(1)
class Solution {
public:
    int ans = 0, n;
    void check(vector<vector<int>>& img1, vector<vector<int>>& img2, int shift_i, int shift_j){
        int cnt = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int r = i + shift_i, c = j + shift_j;
                if (r < 0 || r >= n || c < 0 || c >= n || img2[i][j] == 0 || img1[r][c] == 0)
                    continue;
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n = img1.size();
        for (int i = -n; i < n; i++)
            for (int j = -n; j < n; j++)
                check(img1, img2, i, j);
        
        return ans;
    }
};

```
