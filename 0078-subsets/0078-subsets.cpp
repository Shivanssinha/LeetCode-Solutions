class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans,int i, vector<int>& arr){
        if(i == nums.size()){
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        solve(nums,ans,i + 1,arr);
        arr.pop_back();
        solve(nums,ans,i + 1,arr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(nums,ans,0,arr);
        return ans;
    }
};