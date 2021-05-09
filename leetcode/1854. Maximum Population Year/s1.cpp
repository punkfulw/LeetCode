// OJ: https://leetcode.com/problems/maximum-population-year/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> pop (100, 0);
        
        for (int i = 0; i < logs.size(); i++){
            for (int j = logs[i][0]; j < logs[i][1]; j++){
                pop[j - 1950]++;
            }
        }
        int max = 0;
        int index = 0;
        for(int i = 0; i < 100; i++){
            if (pop[i] > max){
                max = pop[i];
                index = i;
            }
        }
        return index+1950;
    }
};
