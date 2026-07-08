class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }
        int i = row - 1;
        int j = col - 1;

        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        i = row - 1;
        j = col + 1;

        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans,vector<string>& b,int row,int n){
        if(row == n){
            ans.push_back(b);
            return;
        }
        for(int i = 0;i<n;i++){
            if(isSafe(row,i,b,n)){
                b[row][i] = 'Q';
                solve(ans,b,row + 1,n);
                b[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(ans,board,0,n);
        return ans;
    }
};