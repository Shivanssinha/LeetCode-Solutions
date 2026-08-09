class Solution {
public:
    int findCircleNum(vector<vector<int>>& m) {
        
        int n = m.size();
        vector<int> visited(n, 0);
        
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            
            if (visited[i] == 0) {
                provinces++;

                queue<int> q;
                q.push(i);
                visited[i] = 1;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int j = 0; j < n; j++) {
                        
                        if (m[node][j] == 1 && visited[j] == 0) {
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return provinces;
    }
};