# [413. Arithmetic Slices (Medium)](https://leetcode.com/problems/arithmetic-slices/)

<p>A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.</p>

<p>For example, these are arithmetic sequence:</p>
<pre>1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9</pre>

<p>The following sequence is not arithmetic.</p> <pre>1, 1, 2, 5, 7</pre> 
<br>

<p>A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 &lt;= P &lt; Q &lt; N.</p>

<p>A slice (P, Q) of array A is called arithmetic if the sequence:<br>
    A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 &lt; Q.</p>

<p>The function should return the number of arithmetic slices in the array A. </p>
<br>

<p><b>Example:</b>
</p><pre>A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
</pre>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Arithmetic Slices II - Subsequence (Hard)](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/arithmetic-slices/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        int ans {};
        if (size < 3){
            return 0;
        }else{
            vector<int> count {};
            int ans {};
            for (int i = 0; i < size-2; i++){
                if ((nums[i+2] - nums[i+1]) == (nums[i+1] - nums[i])){
                    int j = i;
                    int sss {3};
                    while ((j+3 < size) && (nums[j+3] - nums[j+2]) == (nums[j+2] - nums[j+1])){
                        j++;
                        sss++;
                    }
                    int temp = i;
                    i += sss-2;
                    j -= temp;
                    count.push_back(sss);
                }
            }
            for (int j = 0; j < count.size();j++){
                cout << count[j];
                for (int i = 1; i <= count[j]-2; i++){
                    ans += i;
                }
            }
            return ans;
        }    
    }
};
```
