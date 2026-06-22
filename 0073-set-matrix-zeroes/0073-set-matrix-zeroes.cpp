#include <vector>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeroes;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == 0){
                    zeroes.push_back({i,j});
                }
            }
        }
        for(auto p: zeroes){
            for(int i =0;i<m;i++){
                matrix[p.first][i] = 0;
            }
            for(int j = 0;j<n;j++){
                matrix[j][p.second] = 0;
            }
        }
        
    }
};