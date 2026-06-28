class Solution {
public:
    bool isPossible(vector<int>& nums, int k, long long maxSum) {
        int count = 1;          // number of subarrays
        long long curr = 0;

        for (int num : nums) {
            if (curr + num <= maxSum) {
                curr += num;
            } else {
                count++;       // start new subarray
                curr = num;
            }
        }
        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = 0, high = 0;

        for (int num : nums) {
            low = max(low, (long long)num);  // max element
            high += num;                     // total sum
        }

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
