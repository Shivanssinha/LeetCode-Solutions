class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v(n); 
        for(int j = 0;j<n;j++){
            v[j].resize(j + 1);
            v[j][0] = 1;
            v[j][j] = 1;
            for(int k = 1;k<j;k++){
                v[j][k] = v[j - 1][k - 1] + v[j - 1][k];
            }
        }
        return v;
    }
};
