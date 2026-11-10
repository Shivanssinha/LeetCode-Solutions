class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1,INT_MAX);
        vector<int> nums(n+1, 0);
        for (int i = 1; i <= n; i++) nums[i] = costs[i-1];
        dp[0] = 0;
        for(int i = 1;i<=n;i++){
            if (i-1 >= 0) dp[i] = min(dp[i], dp[i-1] + nums[i] + (1*1));
            if (i-2 >= 0) dp[i] = min(dp[i], dp[i-2] + nums[i] + (2*2));
            if (i-3 >= 0) dp[i] = min(dp[i], dp[i-3] + nums[i] + (3*3));
        }
        return dp[n];
    }
};