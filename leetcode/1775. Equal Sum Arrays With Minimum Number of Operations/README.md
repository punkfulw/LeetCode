# [1775. Equal Sum Arrays With Minimum Number of Operations (Medium)](https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/)

<p>You are given two arrays of integers <code>nums1</code> and <code><font face="monospace">nums2</font></code>, possibly of different lengths. The values in the arrays are between <code>1</code> and <code>6</code>, inclusive.</p>

<p>In one operation, you can change any integer's value in <strong>any </strong>of the arrays to <strong>any</strong> value between <code>1</code> and <code>6</code>, inclusive.</p>

<p>Return <em>the minimum number of operations required to make the sum of values in </em><code>nums1</code><em> equal to the sum of values in </em><code>nums2</code><em>.</em> Return <code>-1</code>​​​​​ if it is not possible to make the sum of the two arrays equal.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed.
- Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [<u><strong>6</strong></u>,1,2,2,2,2].
- Change nums1[5] to 1. nums1 = [1,2,3,4,5,<strong><u>1</u></strong>], nums2 = [6,1,2,2,2,2].
- Change nums1[2] to 2. nums1 = [1,2,<strong><u>2</u></strong>,4,5,1], nums2 = [6,1,2,2,2,2].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,1,1,1,1,1,1], nums2 = [6]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no way to decrease the sum of nums1 or to increase the sum of nums2 to make them equal.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums1 = [6,6], nums2 = [1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed. 
- Change nums1[0] to 2. nums1 = [<strong><u>2</u></strong>,6], nums2 = [1].
- Change nums1[1] to 2. nums1 = [2,<strong><u>2</u></strong>], nums2 = [1].
- Change nums2[0] to 4. nums1 = [2,2], nums2 = [<strong><u>4</u></strong>].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 6</code></li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Number of Dice Rolls With Target Sum (Medium)](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/)

## Solution 1. sort

```cpp
// OJ: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    void sol(vector<int> &nums1, vector<int> &nums2, int &ans){
        int cnt1 = accumulate(nums1.begin(), nums1.end(), 0), 
            cnt2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (cnt1 == cnt2)
            return;
        if (cnt1 < cnt2){
            swap(nums1, nums2);
            swap(cnt1, cnt2);
        }
        sort(nums1.rbegin(), nums1.rend());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        while (cnt1 != cnt2){
            ans++;
            int d1 = i < n ? nums1[i] - 1 : 0, d2 = j < m ? 6 - nums2[j] : 0, dif = cnt1 - cnt2;
            if (max(d1, d2) >= dif)
                break;
            if (d1 > d2){
                cnt1 -= d1;
                i++;
            }
            else {
                cnt2 += d2;
                j++;
            }
            
        }
        return;
    }
    
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m * 6 || m > n * 6)
            return -1;
        int ans = 0;
        sol(nums1, nums2, ans);
        return ans;
    }
};
```

## Solution 2. Buckets Sort

```cpp
// OJ: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/discuss/1086142/C%2B%2BJava-O(n)
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minOperations(vector<int>& n1, vector<int>& n2) {
        int n = n1.size(), m = n2.size();
        if (n > m * 6 || m > n * 6)
            return -1;
        int cnt1 = accumulate(n1.begin(), n1.end(), 0), cnt2 = accumulate(n2.begin(), n2.end(), 0);
        if (cnt1 < cnt2)
            swap(n1, n2);
        int ans = 0, cnt[6] = {}, dif = abs(cnt1 - cnt2);
        
        for (int i: n1)
            cnt[i - 1]++;
        for (int i: n2)
            cnt[6 - i]++;
        
        for (int i = 5; i >= 1 && dif > 0; i--){
            int take = min(cnt[i], dif / i + (dif % i != 0));
            dif -= take * i;
            ans += take;
        }
        return ans;
    }
};
```
