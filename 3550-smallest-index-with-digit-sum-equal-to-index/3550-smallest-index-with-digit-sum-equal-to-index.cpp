class Solution {
public:
    int sumo(int k){
        int sum = 0;
        while(k>0){
            sum = sum + k%10;
            k = k/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            if(sumo(nums[i]) == i){
                return i;
            }
        }
        return -1;
    }
};