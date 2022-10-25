```cpp
// OJ: https://leetcode.com/problems/subarrays-with-k-different-integers/
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int AtMost(vector<int> &nums, int k){
        int ret = 0, n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0, j = 0; j < n; j++){
            mp[nums[j]]++;
            while (mp.size() > k){
                int num = nums[i++];
                mp[num]--;
                if (mp[num] == 0)
                    mp.erase(num);
            }
            ret += j - i + 1;
        }
        return ret;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return AtMost(nums, k) - AtMost(nums, k - 1);
    }
};
```


```cpp
// OJ: https://leetcode.com/problems/count-number-of-nice-subarrays/
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int AtMost(vector<int> &nums, int k){
        int ret = 0, n = nums.size();
        for (int i = 0, j = 0; j < n; j++){
            k -= (nums[j] & 1);
            while (k < 0)
                k += (nums[i++] & 1);
            ret += j - i + 1;
        }
        return ret;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return AtMost(nums, k) - AtMost(nums, k - 1);
    }
};
```
