class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int bestLen = 0;
        for(int i = 0; i < n; i++) {
            unsigned long long prod;
            int clcm;
            int cgcd;
            for(int j = i; j < n; j++) {
                if(i == j) {
                    prod = nums[j];
                    clcm = nums[j];
                    cgcd = nums[j];
                } else {
                    prod *= nums[j];
                    clcm = lcm(clcm, nums[j]);
                    cgcd = gcd(cgcd, nums[j]);
                }
                if(prod == clcm*cgcd) 
                    bestLen = max(bestLen, j-i+1);
            }
        }
        return bestLen;
    }
};