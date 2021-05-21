// OJ: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int cnt[] = {0, 0};
        
        for (auto i: students){
            cnt[i]++;
        }
        for (auto i: sandwiches){
            if (cnt[i] > 0)
                cnt[i]--;
            else
                break;
            n--;
        }
        return n;
    }
};
