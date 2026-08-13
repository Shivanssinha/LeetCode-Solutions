class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 &&
                   (i == 0 || i == n - 1 || j == 0 || j == m - 1)) {

                    q.push({i, j});
                    grid[i][j] = 2; 
                }
            }
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < n &&
                   ny >= 0 && ny < m &&
                   grid[nx][ny] == 1) {

                    q.push({nx, ny});
                    grid[nx][ny] = 2;
                }
            }
        }
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};