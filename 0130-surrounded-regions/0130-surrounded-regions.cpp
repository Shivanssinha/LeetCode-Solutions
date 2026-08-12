class Solution {
public:
    void solve(vector<vector<char>>& b) {
        
        queue<pair<int, int>> q;

        int n = b.size();
        int m = b[0].size();
        for(int i = 0; i < n; i++) {
            if(b[i][0] == 'O') {
                q.push({i, 0});
                b[i][0] = '#';
            }
        }
        for(int i = 0; i < n; i++) {
            if(b[i][m - 1] == 'O') {
                q.push({i, m - 1});
                b[i][m - 1] = '#';
            }
        }
        for(int i = 1; i < m - 1; i++) {
            if(b[0][i] == 'O') {
                q.push({0, i});
                b[0][i] = '#';
            }
        }
        for(int i = 1; i < m - 1; i++) {
            if(b[n - 1][i] == 'O') {
                q.push({n - 1, i});
                b[n - 1][i] = '#';
            }
        }
        while(!q.empty()) {
            
            auto [x, y] = q.front();
            q.pop();

            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for(int k = 0; k < 4; k++) {
                
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    
                    if(b[nx][ny] == 'O') {
                        b[nx][ny] = '#';
                        q.push({nx, ny});
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if(b[i][j] == 'O') {
                    b[i][j] = 'X';
                }
                
                if(b[i][j] == '#') {
                    b[i][j] = 'O';
                }
            }
        }
    }
};