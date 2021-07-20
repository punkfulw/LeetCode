# [384. Shuffle an Array (Medium)](https://leetcode.com/problems/shuffle-an-array/)

<p>Given an integer array <code>nums</code>, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.</p>

<p>Implement the <code>solution</code> class:</p>


<ul>
  <li><code>Solution(int[] nums)</code> Initializes the object with the integer array nums.</li>
  <li><code>int[] reset()</code> Resets the array to its original configuration and returns it.</li>
  <li><code>int[] shuffle()</code> Returns a random shuffling of the array.</li>
</ul>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> 
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
<strong>Output:</strong> 
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]
<strong>Explanation:</strong> 
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
                       // Any permutation of [1,2,3] must be equally likely to be returned.
                       // Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 200</code></li>
  <li><code>-10<sup>6</sup> &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
  <li>All the elements of <code>nums</code> are <b>unique</b>.</li>
  <li>At most <code>5 * 10<sup>4</sup></code> calls in total will be made to <code>reset</code> and <code>shuffle</code>.</li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/shuffle-an-array/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/shuffle-an-array/discuss/86001/C%2B%2B-solution-with-Fisher-Yates-algorithm
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> ori, arr;
    Solution(vector<int>& nums) {
        srand(time(NULL));
        ori = nums;
        arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int i , j;
        for (i = arr.size()-1; i > 0; i--){
            j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }
        return arr;
    }
};
```
