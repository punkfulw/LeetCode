// OJ: https://leetcode.com/problems/find-k-closest-elements/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        arr.insert(arr.begin(), INT_MIN);
        arr.push_back(INT_MAX);
        auto r = upper_bound(arr.begin(), arr.end(), x), l = r - 1;
        
        while (r - l <= k){
            if (r == arr.end() - 1)
                l--;
            else if (l == arr.begin())
                r++;
            else {
                if (abs(*r - x) < abs(*l - x))
                    r++;
                else
                    l--;
            }
        }
        return vector<int> (l + 1, r);
    }
};
