
class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

    int upperBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int start = lowerBound(nums, target);
        int end = upperBound(nums, target);

        vector<int> ans;

        for (int i = start; i < end; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};
