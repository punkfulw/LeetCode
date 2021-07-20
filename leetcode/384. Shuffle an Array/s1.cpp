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
