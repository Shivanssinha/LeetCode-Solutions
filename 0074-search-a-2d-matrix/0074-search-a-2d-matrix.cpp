class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int low = 0;
        int m = nums.size();
        int n = nums[0].size();
        int  high = m*n - 1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid/n][mid%n] == target){
                return true;
            }
            else if(nums[mid/n][mid%n]>target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;

        
    }
};