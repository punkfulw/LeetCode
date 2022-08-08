// OJ: https://leetcode.com/problems/boats-to-save-people/
// Author: github.com/punkfulw
// Time: O(NlogN) 
// Space: O(1)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0, r = people.size() - 1, ans = 0;
        sort(people.begin(), people.end());
        while (l <= r){
            if (people[l] + people[r] <= limit)
                l++;
            r--;
            ans++;
        }
        return ans;
    }
};
