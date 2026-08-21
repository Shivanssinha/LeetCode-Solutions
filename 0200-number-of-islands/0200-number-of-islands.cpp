class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        queue<pair<int,int>> q;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == '1') {
                    count++;

                    q.push({i, j});
                    grid[i][j] = '2';

                    while(!q.empty()) {
                        auto c = q.front();
                        q.pop();

                        int r = c.first;
                        int rx = c.second;

                        int dx[] = {-1, 1, 0, 0};
                        int dy[] = {0, 0, 1, -1};

                        for(int k = 0; k < 4; k++) {
                            int tx = r + dx[k];
                            int ty = rx + dy[k];

                            if(tx >= 0 && tx < n &&
                               ty >= 0 && ty < m &&
                               grid[tx][ty] == '1') {

                                q.push({tx, ty});
                                grid[tx][ty] = '2';
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};