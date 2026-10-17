class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int x:nums){
            mp[x]++;
        }
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        for(auto x:mp){
            bucket[x.second].push_back(x.first);
        }
        for(int i = n;i>= 1;i--){
            for(int x:bucket[i]){
                ans.push_back(x);
            }
            if(ans.size() == k){
                return ans;
            }
        }
        return ans;
    }
};