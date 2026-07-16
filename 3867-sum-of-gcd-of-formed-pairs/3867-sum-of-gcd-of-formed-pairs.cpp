class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> v;
        int maxi = 0;
        for (auto a : nums) {
            maxi = max(maxi, a);
            v.push_back(gcd(a, maxi));
        }
        sort(v.begin(), v.end());
        int n = v.size();
        long long sum = 0;
        for (int i = 0; i < n / 2; i++) {
            sum = sum + gcd(v[i], v[n - 1 - i]);
            
        }
        return sum;
    }
};