// OJ: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
// Author: github.com/punkfulw
// Time:
//      FindSumPairs: O(N)
//      add: O(1)
//      count: O(N)
// Space: O(N)
class FindSumPairs {
public:
    unordered_map<int, int> mp1, mp2;
    vector<int> nums1, nums2; 
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (auto i: nums1)
            mp1[i]++;
        for (auto i: nums2)
            mp2[i]++;
    }
    
    void add(int index, int val) {
        int ori = nums2[index];
        nums2[index] += val;
        mp2[ori]--;
        mp2[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (auto p: mp1){
            int l = p.first;
            if (l >= tot)
                continue;
            ans += p.second * mp2[tot - l]; 
        }
        return ans;
    }
};
