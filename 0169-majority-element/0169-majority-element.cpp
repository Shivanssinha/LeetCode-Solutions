class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int j = 0;j<nums.size();j++){
            mp[nums[j]]++;
        }
        n = n/2;
        for(auto x: mp){
            if(x.second >n){
                return x.first;
            }
        }
        return 0;

    }
};