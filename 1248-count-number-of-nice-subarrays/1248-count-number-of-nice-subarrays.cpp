class Solution {
public:
    bool div(int k) {
        if (k % 2 == 0) {
            return 0;
        }
        return 1;
    }

    int atmost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int l = 0;
        int count = 0;
        int ans = 0;

        for (int r = 0; r < nums.size(); r++) {

            if (div(nums[r])) {
                count++;
            }

            while (count > k) {
                if (div(nums[l])) {
                    count--;
                }
                l++;
            }

            ans += r - l + 1;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};