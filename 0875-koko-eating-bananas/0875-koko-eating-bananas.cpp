class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long k = 0;

            for (int x : nums) {
                k += (x + mid - 1) / mid;
            }

            if (k <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};