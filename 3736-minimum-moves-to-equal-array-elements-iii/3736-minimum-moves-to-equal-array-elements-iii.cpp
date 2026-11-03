class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = *max_element(nums.begin(),nums.end());
        int moves = 0;
        for(int x:nums){
            moves += m - x;
        }
        return moves;
    }
};