class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {

        vis[node] = 1;   // currently visiting

        for (int neighbour : adj[node]) {

            if (vis[neighbour] == 0) {

                if (dfs(neighbour, adj, vis))
                    return true;

            }
            else if (vis[neighbour] == 1) {

                // neighbour is already in current DFS path
                return true;
            }
        }

        vis[node] = 2;   // completely processed
        return false;
    }

    bool canFinish(int nums, vector<vector<int>>& p) {

        vector<vector<int>> adj(nums);

        for (int i = 0; i < p.size(); i++) {
            adj[p[i][0]].push_back(p[i][1]);
        }

        vector<int> vis(nums, 0);

        for (int i = 0; i < nums; i++) {

            if (vis[i] == 0) {

                if (dfs(i, adj, vis))
                    return false;   // cycle exists
            }
        }

        return true;   // no cycle
    }
};