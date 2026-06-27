class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        if ((long long)m * k > nums.size())
            return -1;

        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int flowers = 0;
            int bouquets = 0;

            for (int x : nums) {
                if (x <= mid) {
                    flowers++;
                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }

            if (bouquets >= m) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};