// https://leetcode.com/problems/valid-sudoku/description/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = 9;
        int rows[N][N] = {}, cols[N][N] = {}, subBoxes[N][N] = {};

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == '.') continue;
                int indx = board[i][j] - '1';
                int currBox = (i / 3) * 3 + j / 3;
                if(rows[i][indx] || cols[j][indx] || subBoxes[currBox][indx]) return false;
                rows[i][indx]++;
                cols[j][indx]++;
                subBoxes[currBox][indx]++;
            }
        }
        return true;
    }
};
