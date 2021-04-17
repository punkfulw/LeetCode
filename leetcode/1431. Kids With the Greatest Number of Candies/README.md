# [1431. Kids With the Greatest Number of Candies (Easy)](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/)

<p>Given the array <code>candies</code> and the integer <code>extraCandies</code>, where <code>candies[i]</code> represents the number of candies that the <b>ith</b> kid has.</p>

<p>For each kid check if there is a way to distribute <code>extraCandies</code> among the kids such that he or she can have the <b>greatest</b> number 
  of candies among them. Notice that multiple kids can have the <b>greatest</b> number of candies.</p>


<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [2,3,5,1,3], extraCandies = 3
<strong>Output:</strong> [true,true,true,false,true] 
<strong>Explanation:</strong> 
Kid 1 has 2 candies and if he or she receives all extra candies (3) will have 5 candies --- the greatest number of candies among the kids. 
Kid 2 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids. 
Kid 3 has 5 candies and this is already the greatest number of candies among the kids. 
Kid 4 has 1 candy and even if he or she receives all extra candies will only have 4 candies. 
Kid 5 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids. 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> candies = [4,2,1,1,2], extraCandies = 1
<strong>Output:</strong> [true,false,false,false,false] 
<strong>Explanation:</strong> 
There is only 1 extra candy, therefore only kid 1 will have the greatest number of candies among the kids regardless of who takes the extra candy.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> candies = [12,1,12], extraCandies = 10
<strong>Output:</strong> [true,false,true]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>


2 <= candies.length <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50


<ul>
	<li><code>2 &lt;= candies.length &lt;= 100</code></li>
	<li><code>1 &lt;= candies[i] &lt;= 100</code></li>
	<li><code>1 &lt;= extraCandies &lt;= 50</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
// Author: github.com/punfkulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int can_size = candies.size();
        int max {};
        vector<bool> res (can_size);
        for (int i = 0; i < can_size; i++){
            if (candies.at(i) > max){
                max = candies.at(i);
            }else{
                res.at(i) = true;
            }
        }
        for (int i = 0; i < can_size; i++){
            if((candies.at(i) + extraCandies) < max){
                res.at(i) = false;
            }else{
                res.at(i) = true;
            }
        }
        return res;
    }
};;
```
