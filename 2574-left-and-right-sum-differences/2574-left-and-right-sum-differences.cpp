class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0;
        int n = nums.size(); 
        int msum = 0;
        vector<int> ans(n,0);
        for(int x:nums){
            msum += x;
        }
        for(int i = 0;i<n;i++){
            sum += nums[i];
            int leftsum = sum - nums[i];
            int rsum = msum - leftsum - nums[i];
            ans[i] = abs(rsum - leftsum);
        }
        return ans;
    }
};