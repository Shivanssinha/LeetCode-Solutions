class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int sum = 0;
        int count = 0;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                count++;
            }
        }
        if(count == nums.size()){
            return 0;
        }
        for(int i = 0;i<nums.size();i++){
            sum ^= nums[i];
            if(i == n - 2 && nums[i + 1] == sum){
                return i + 1;
            }
        }
        return nums.size();
        
    }
};