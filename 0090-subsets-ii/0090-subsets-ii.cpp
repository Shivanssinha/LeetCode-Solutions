class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& arr, int i,
               vector<int>& nums) {

        if (i == nums.size()) {
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        solve(ans, arr, i + 1, nums);
        arr.pop_back();
        solve(ans,arr, i + 1, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> arr;
        solve(ans, arr, 0, nums);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};