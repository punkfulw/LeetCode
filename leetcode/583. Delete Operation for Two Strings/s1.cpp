// OJ: https://leetcode.com/problems/delete-operation-for-two-strings
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        vector<vector<int>> A(m+1, vector<int>(n+1, 0));
        
        for (int i = 1; i < m+1; i++){         
            for (int j = 1; j < n+1; j++){
                if (word2[i-1] == word1[j-1])
                    A[i][j] = A[i-1][j-1] + 1;
                else
                    A[i][j] = max(A[i-1][j], A[i][j-1]);
                
            }
        }
       /********************************************************** 
       * for (int i = 0; i < m+1; i++){         
       *     for (int j = 0; j < n+1; j++){
       *         cout << A[i][j] << " ";        show DP result 
       *     }
       *     cout << endl;
       * }
       ***********************************************************/
        return  m - A[m][n] + n - A[m][n];
    }
};
