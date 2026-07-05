class Solution {
public:
    void solve(int i, int k, int n, vector<int>& curr,
               vector<vector<int>>& ans) {
        if (k == 0 && n == 0) {
            ans.push_back(curr);
            return;
        }
        if (k == 0 || n < 0 || i > 9)
            return;

        curr.push_back(i);
        solve(i + 1, k - 1, n - i, curr, ans);
        curr.pop_back();

        solve(i + 1, k, n, curr, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(1, k, n, curr, ans);

        return ans;
    }
};