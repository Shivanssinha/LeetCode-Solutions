
class Solution {
public:
    void solve(vector<int>& arr,int i,int t,vector<vector<int>>& ans ,vector<int>& cand){
        if(t == 0 ){
            ans.push_back(arr);
            return;
        }
        if(i == cand.size()){
            return;
        }
        if(cand[i]<= t){
            arr.push_back(cand[i]);
            solve(arr,i,t - cand[i],ans,cand);
            arr.pop_back();
        }
        solve(arr,i+1,t,ans,cand);
    }
    
     
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> arr;
        solve(arr,0,target,ans,candidates);
        return ans;
    }
};