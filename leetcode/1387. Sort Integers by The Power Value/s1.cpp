// OJ: https://leetcode.com/problems/sort-integers-by-the-power-value/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> A;
        
        for (int i = lo; i <= hi; i++){
            A.push_back({pow(i),i});
        }
        sort(A.begin(), A.end());
        return A[k-1].second;
    }
    int pow(int num){
        int cnt {};
        while (num != 1){
            if (num % 2 == 0){
                num /= 2;
                cnt++;
            }
            else{
                num = num * 3 + 1;
                cnt++;
            }
        }
        return cnt;
    }
};
