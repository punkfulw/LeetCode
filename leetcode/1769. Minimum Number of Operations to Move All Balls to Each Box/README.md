# [1769. Minimum Number of Operations to Move All Balls to Each Box (Medium)](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/)

<p>You have <code>n</code> boxes. You are given a binary string <code>boxes</code> of length <code>n</code>, where <code>boxes[i]</code> is <code>'0'</code> if the <code>i<sup>th</sup></code> box is <strong>empty</strong>, and <code>'1'</code> if it contains <strong>one</strong> ball.</p>

<p>In one operation, you can move <strong>one</strong> ball from a box to an adjacent box. Box <code>i</code> is adjacent to box <code>j</code> if <code>abs(i - j) == 1</code>. Note that after doing so, there may be more than one ball in some boxes.</p>

<p>Return an array <code>answer</code> of size <code>n</code>, where <code>answer[i]</code> is the <strong>minimum</strong> number of operations needed to move all the balls to the <code>i<sup>th</sup></code> box.</p>

<p>Each <code>answer[i]</code> is calculated considering the <strong>initial</strong> state of the boxes.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> boxes = "110"
<strong>Output:</strong> [1,1,3]
<strong>Explanation:</strong> The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> boxes = "001011"
<strong>Output:</strong> [11,8,5,4,3,4]</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == boxes.length</code></li>
	<li><code>1 &lt;= n &lt;= 2000</code></li>
	<li><code>boxes[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Minimum Cost to Move Chips to The Same Position (Easy)](https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/)

## Solution 1. Brute force

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans (n, 0);
        
        for (int i = 0; i < n; i++){
            int num = 0;
            for (int j = 0; j < n; j++){
                if (boxes[j] == '1')
                    num += abs(j-i);
            }
            ans[i] = num;
        }
        return ans;
    }
};
```

## Solution 2.

Assume we are at `s[i]` and the corresponding operations needed is `sum`. 
When we move from `s[i]` to `s[i + 1]`, if there are `left` balls that have indexes `<= i` and `right` balls that have indexes `> i`, 
then the number of operations needed for `s[i + 1]` will be `sum + left - right`.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
// Author: github.com/punkfulw
// Reference: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/1769.%20Minimum%20Number%20of%20Operations%20to%20Move%20All%20Balls%20to%20Each%20Box/README.md
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), right = 0, left = 0, sum = 0;
        vector<int> ans (n);
        
        for (int i = 0; i < n; i++){
            if (boxes[i] == '1'){
                right ++;
                sum += i;
            }
        }
        
        for (int i = 0; i < n; i++){
            ans[i] = sum;
            if (boxes[i] == '1'){
                left++;
                right--;
            }
            sum += left - right;
        }
        return ans;
    }
};
```
