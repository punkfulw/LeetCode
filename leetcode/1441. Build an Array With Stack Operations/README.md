# [1441. Build an Array With Stack Operations (Easy)](https://leetcode.com/problems/build-an-array-with-stack-operations/)

<p>Given an array <code>target</code> and an integer <code>n</code>. In each iteration, you will read a number from  <code>list = {1,2,3..., n}</code>.</p>

<p>Build the <code>target</code> array using the following operations:</p>

<ul>
  <li><b>Push</b>: Read a new element from the beginning <code>list</code>, and push it in the array.</li>
  <li><b>Pop</b>: delete the last element of the array.</li>
  <li>If the target array is already built, stop reading more elements.</li>
</ul>

<p>Return the operations to build the target array. You are guaranteed that the answer is unique.</p>


<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> target = [1,3], n = 3
<strong>Output:</strong> ["Push","Push","Pop","Push"]
<strong>Explanation: </strong> 
Read number 1 and automatically push in the array -> [1]
Read number 2 and automatically push in the array then Pop it -> [1]
Read number 3 and automatically push in the array -> [1,3]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> target = [1,2,3], n = 3
<strong>Output:</strong> ["Push","Push","Push"]
</pre>


<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> target = [1,2], n = 4
<strong>Output:</strong> ["Push","Push"]
<strong>Explanation: </strong>You only need to read the first 2 numbers and stop.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> target = [2,3,4], n = 4
<strong>Output:</strong> ["Push","Pop","Push","Push","Push"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= target.length &lt;= 100</code></li>
  <li><code>1 &lt;= target[i] &lt;= n</code></li>
  <li><code>1 &lt;= n &lt;= 100</code></li>
  <li><code>target</code> is strictly increasing.</li>
</ul>

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/build-an-array-with-stack-operations/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans {};
        int cnt {};
        
        for (int i = 0; i < target.size(); i++){
            if (target[i] == cnt + 1){
                ans.push_back("Push");
                cnt++;
            }
            else{
                while (target[i] != cnt + 1){
                    ans.push_back("Push");  
                    ans.push_back("Pop");
                    cnt++;
                }
                i--;
            }
        }
        return ans;
    }
};
```
