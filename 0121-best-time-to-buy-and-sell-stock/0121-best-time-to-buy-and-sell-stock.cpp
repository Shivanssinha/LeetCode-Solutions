class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int mn = nums[0];
        int profit = 0;
        for(int i = 0;i<nums.size();i++){
            mn = min(mn,nums[i]);
            profit = max(profit,nums[i] - mn);
        }
        return profit;
    }
};