class Solution {
public:
    bool solve(vector<vector<char>>& board, const string& word,
               int i, int j, int index) {

        // Entire word matched
        if (index == word.size())
            return true;

        int m = board.size();
        int n = board[0].size();

        // Invalid position or character mismatch
        if (i < 0 || i >= m || j < 0 || j >= n ||
            board[i][j] != word[index])
            return false;

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all 4 directions
        bool found =
            solve(board, word, i + 1, j, index + 1) ||
            solve(board, word, i - 1, j, index + 1) ||
            solve(board, word, i, j + 1, index + 1) ||
            solve(board, word, i, j - 1, index + 1);

        // Restore the cell (Backtracking)
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (solve(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};