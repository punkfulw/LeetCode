// OJ: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        map<int, int> rowA, rowB, colA, colB;
        int n = moves.size(), rdiaA = 0, rdiaB = 0, ldiaA = 0, ldiaB = 0;
        
        for (int i = 0; i < n; i++){
            int r = moves[i][0], c = moves[i][1];
            if (i % 2 == 0){
                rowA[r]++;
                colA[c]++;
                if (r - c == 0) rdiaA++;
                if (r + c == 2) ldiaA++;
                if (rowA[r] == 3 || colA[c] == 3 || rdiaA == 3 || ldiaA == 3)
                    return "A";
            }
            else {
                rowB[r]++;
                colB[c]++;
                if (r - c == 0) rdiaB++;
                if (r + c == 2) ldiaB++;
                if (rowB[r] == 3 || colB[c] == 3 || rdiaB == 3 || ldiaB == 3) 
                    return "B";
            }
        }
        cout << colB[0] << " " << colB[1] << " " << colB[2];
        return n == 9 ? "Draw" : "Pending";
    }
};
