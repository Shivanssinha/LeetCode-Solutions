class Solution {
public:
    void solve(vector<int>& cand, vector<int>& arr,
               vector<vector<int>>& ans, int start, int target) {

        if (target == 0) {
            ans.push_back(arr);
            return;
        }

        for (int i = start; i < cand.size(); i++) {
            if (i > start && cand[i] == cand[i - 1])
                continue;

            if (cand[i] > target)
                break;

            arr.push_back(cand[i]);
            solve(cand, arr, ans, i + 1, target - cand[i]);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> arr;

        solve(candidates, arr, ans, 0, target);

        return ans;
    }
};