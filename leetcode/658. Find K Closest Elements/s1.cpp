// OJ: https://leetcode.com/problems/find-k-closest-elements/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC%2B%2BPython-Binary-Search-O(log(N-K)-%2B-K)
// Time: O(log(N - K))
// Space: O(1)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size()-k;
        while (left < right){
            int mid = (left + right) / 2;
            if (x - arr[mid] > arr[mid+k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int> (arr.begin() + left, arr.begin() + left + k);
    }
};
