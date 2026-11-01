class Solution {
public:
    
    int minMoves(vector<int>& nums) {
        int moves = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i<nums.size() - 1;i++){
            moves += nums[i + 1] - nums[0];
            if(i + 2<n){
                nums[i + 2] += moves;
            }
            nums[0] += nums[i + 1] - nums[0];
        }
        return moves;
    }
};