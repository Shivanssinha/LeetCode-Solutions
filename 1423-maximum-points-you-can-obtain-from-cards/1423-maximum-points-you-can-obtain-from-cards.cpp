class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size() - 1;

        vector<int> v(k + 1, 0);
        vector<int> b(k + 1, 0);

        int sum = 0, sum1 = 0;

        for(int i = 0; i < k; i++){
            sum += nums[i];
            v[i + 1] = sum;
        }
        int l = 1;

        for(int j = n; j > n - k; j--){
            sum1 += nums[j];
            b[l] = sum1;
            l++;
        }

        int maxi = 0;

        for(int i = 0; i <= k; i++){
            maxi = max(maxi, v[i] + b[k - i]);
        }

        return maxi;
    }
};