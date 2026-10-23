#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    void adi(const vector<int>& nums, vector<int>& ans, int i, int n, int sum) {
        if (i == n) {
            ans.push_back(sum);
            return;
        }
        // Include nums[i]
        adi(nums, ans, i + 1, n, sum + nums[i]);
        // Exclude nums[i]
        adi(nums, ans, i + 1, n, sum);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n / 2;

        vector<int> ans1;
        vector<int> ans2;

        adi(nums, ans1, 0, mid, 0);
        adi(nums, ans2, mid, n, 0);

        sort(ans1.begin(), ans1.end());

        int ans = INT_MAX;

        for (int x : ans2) {
            int target = goal - x;
            auto it = lower_bound(ans1.begin(), ans1.end(), target);

            if (it != ans1.end()) {
                ans = min(ans, abs(goal - (x + *it)));
            }
            if (it != ans1.begin()) {
                ans = min(ans, abs(goal - (x + *(it - 1))));
            }
            if (ans == 0) return 0;
        }

        return ans;
    }
};