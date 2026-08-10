class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;

        int min = 0;
        int fresh = 0;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    fresh++;
                }

                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                auto [r,c] = q.front();
                q.pop();

                int dr[] = {-1,1,0,0};
                int dc[] = {0,0,-1,1};

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < m &&
                       nc >= 0 && nc < n &&
                       grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        fresh--;

                        q.push({nr,nc});
                    }
                }
            }

            min++;
        }

        if(fresh > 0)
            return -1;

        if(min == 0)
            return 0;

        return min - 1;
    }
};