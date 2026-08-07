class Solution {
public:
    int atmost(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        int dist = 0;
        int l = 0;
        int count = 0;
        for(int r = 0;r<nums.size();r++){
            if(!mp[nums[r]]){
                dist++;
            }
            mp[nums[r]]++;
            while(dist>k){
                mp[nums[l]]--;
                if(!mp[nums[l]]){
                    dist--;
                }
                l++;
            }
            count += r - l + 1; 

        }
        return count;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k - 1);
    }
};