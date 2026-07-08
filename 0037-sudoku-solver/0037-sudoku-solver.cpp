class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {

        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == ch)
                return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch)
                return false;
        }

        // Check 3x3 box
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;

        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {

                if (board[i][j] == ch)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        // Find first empty cell
        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {

                    // Try digits
                    for (char ch = '1'; ch <= '9'; ch++) {

                        if (isValid(board, i, j, ch)) {

                            board[i][j] = ch;

                            if (solve(board))
                                return true;

                            board[i][j] = '.';
                        }
                    }

                    // No digit worked
                    return false;
                }
            }
        }

        // No empty cells left
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};