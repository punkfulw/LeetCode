# [999. Available Captures for Rook (Easy)](https://leetcode.com/problems/available-captures-for-rook/)

<p>On an 8 x 8 chessboard, there is one white rook.&nbsp; There also may be empty squares, white bishops, and black pawns.&nbsp; These are given as characters 'R', '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and lowercase characters represent black pieces.</p>

<p>The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies.&nbsp; Also, rooks cannot move into the same square as other friendly bishops.</p>

<p>Return the number of pawns the rook can capture in one move.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/02/20/1253_example_1_improved.PNG" style="width: 300px; height: 305px;"></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]</span>
<strong>Output: </strong><span id="example-output-1">3</span>
<strong>Explanation: </strong>
In this example the rook is able to capture all the pawns.
</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/02/19/1253_example_2_improved.PNG" style="width: 300px; height: 306px;"></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]</span>
<strong>Output: </strong><span id="example-output-2">0</span>
<strong>Explanation: </strong>
Bishops are blocking the rook to capture any pawn.
</pre>

<p><strong>Example 3:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/02/20/1253_example_3_improved.PNG" style="width: 300px; height: 305px;"></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]</span>
<strong>Output: </strong><span id="example-output-3">3</span>
<strong>Explanation: </strong>
The rook can capture the pawns at positions b5, d6 and f5.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>board.length == board[i].length == 8</code></li>
	<li><code>board[i][j]</code> is either <code>'R'</code>, <code>'.'</code>, <code>'B'</code>, or&nbsp;<code>'p'</code></li>
	<li>There is exactly one cell with <code>board[i][j] == 'R'</code></li>
</ol>


**Companies**:  
[Square](https://leetcode.com/company/square)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/available-captures-for-rook/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x0 , y0;
        int ans = 0;
        
        for (int i = 0; i < 8; i++){
            for (int j =0; j < 8; j++){
                if (board[i][j] == 'R'){
                    x0 = i;
                    y0 = j;
                    break;
                }
            }
        }
        
        vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (auto d : direction) {
            for (int x = x0 + d[0], y = y0 + d[1]; 0 <= x && x < 8 && 0 <= y && y < 8; x += d[0], y += d[1]) {
                if (board[x][y] == 'p') ans++; 
                if (board[x][y] != '.') break;
            }
        }
        return ans;
    }
};

```
