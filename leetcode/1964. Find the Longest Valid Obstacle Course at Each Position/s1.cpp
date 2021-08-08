// OJ: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/discuss/1390159/C%2B%2BPython-Same-with-Longest-Increasing-Subsequence-problem-Clean-and-Concise
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        int n = obs.size();
        vector<int> list;
        for (int i = 0; i < n; i++){
            int cur = obs[i];
            if (list.empty() || list.back() <= cur){
                list.push_back(cur);
                obs[i] = list.size();
            }
            else{
                int it = upper_bound(list.begin(), list.end(), cur) - list.begin();
                list[it] = cur;
                obs[i] = it + 1;
            }
        }
        return obs;
    }
};
