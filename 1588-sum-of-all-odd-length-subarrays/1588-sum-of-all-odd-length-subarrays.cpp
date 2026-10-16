class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& nums) {
        int megasum = 0;
        
        for(int i = 0;i<nums.size();i++){
            int sum = 0;
            for(int j = i;j<nums.size();j++){
                sum += nums[j];
                if((j - i) % 2 == 0){
                    megasum = sum + megasum;
                }
            }
        }
        return megasum;
    }
};